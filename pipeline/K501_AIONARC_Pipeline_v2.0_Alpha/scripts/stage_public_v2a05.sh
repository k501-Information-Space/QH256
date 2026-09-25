#!/bin/bash
set -euo pipefail

ROOT="$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)"
STAGE="$ROOT/release_staging/K501_AIONARC_Pipeline_v2.0_Alpha"

echo "V2A-02.5 PUBLIC RELEASE STAGING"
echo "STATUS: START"

if [ ! -d "$STAGE" ]; then
    echo "ERROR: staging directory missing"
    exit 1
fi

is_public_file() {
    case "$1" in
        ./.git/*|./build/*|./evidence/*|./release_staging/*|./K501_AIONARC_Pipeline_v0.2_Candidate/*)
            return 1
            ;;
        *.bak|*.tmp|*~)
            return 1
            ;;
        *)
            return 0
            ;;
    esac
}

echo "STEP 1: CLEAR STAGING"
find "$STAGE" -mindepth 1 -maxdepth 1 -exec rm -rf -- {} +

echo "STEP 2: COPY PUBLIC SCOPE"

copied=0

while IFS= read -r -d '' rel; do
    if ! is_public_file "$rel"; then
        continue
    fi

    src="$ROOT/${rel#./}"
    dst="$STAGE/${rel#./}"

    case "$src" in
        "$ROOT"/release_staging/*)
            continue
            ;;
    esac

    mkdir -p "$(dirname "$dst")"
    cp -a -- "$src" "$dst"
    copied=$((copied + 1))
done < <(
    find . \
        -path './.git' -prune -o \
        -type f -print0
)

echo "COPIED FILES: $copied"

echo "STEP 3: SOURCE/STAGING FILE COUNT"

source_count=0
while IFS= read -r -d '' rel; do
    if is_public_file "$rel"; then
        source_count=$((source_count + 1))
    fi
done < <(
    find . \
        -path './.git' -prune -o \
        -type f -print0
)

stage_count="$(
    find "$STAGE" \
        -type f \
        -printf '%P\n' | wc -l
)"

echo "SOURCE PUBLIC FILE COUNT: $source_count"
echo "STAGING FILE COUNT:       $stage_count"

if [ "$source_count" -ne "$stage_count" ]; then
    echo "RESULT: FAIL"
    echo "ERROR: source/staging file count mismatch"
    exit 1
fi

echo "STEP 4: BYTE COMPARISON"

while IFS= read -r -d '' rel; do
    if ! is_public_file "$rel"; then
        continue
    fi

    src="$ROOT/${rel#./}"
    dst="$STAGE/${rel#./}"

    if ! cmp -s -- "$src" "$dst"; then
        echo "RESULT: FAIL"
        echo "ERROR: byte mismatch: $rel"
        exit 1
    fi
done < <(
    find . \
        -path './.git' -prune -o \
        -type f -print0
)

echo "BYTE COMPARISON: PASS"
echo "V2A-02.5 PUBLIC RELEASE STAGING / RESULT: PASS"
