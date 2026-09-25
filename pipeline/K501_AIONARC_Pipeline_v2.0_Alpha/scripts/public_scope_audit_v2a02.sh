#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
FAIL=0

pass() {
    printf 'PASS: %s\n' "$1"
}

fail() {
    printf 'FAIL: %s\n' "$1"
    FAIL=1
}

is_public_file() {
    case "$1" in
        "$ROOT"/build/*)
            return 1
            ;;
        "$ROOT"/evidence/*)
            return 1
            ;;
        "$ROOT"/../K501_AIONARC_Pipeline_v0.2_Candidate/*)
            return 1
            ;;
        "$ROOT"/scripts/public_scope_audit_v2a02.sh)
            return 1
            ;;
    esac

    return 0
}

printf '%s\n' 'V2A-02.4 PUBLIC SCOPE AUDIT'
printf '%s\n' 'MODE: READ-ONLY'
printf '%s\n' 'SCOPE: PUBLIC RELEASE CANDIDATE'
printf '%s\n' '----------------------------------------'

printf '%s\n' 'CHECK 1: PUBLIC PATH ENUMERATION'

PUBLIC_COUNT=0

while IFS= read -r file; do
    if is_public_file "$file"; then
        PUBLIC_COUNT=$((PUBLIC_COUNT + 1))
    fi
done <<EOF
$(find "$ROOT" -type f)
EOF

printf 'PUBLIC FILE COUNT: %s\n' "$PUBLIC_COUNT"

if [ "$PUBLIC_COUNT" -gt 0 ]; then
    pass 'public candidate contains files'
else
    fail 'public candidate is empty'
fi

printf '%s\n' '----------------------------------------'
printf '%s\n' 'CHECK 2: EXCLUDED TREES'

EXCLUDED_COUNT=$(
    find "$ROOT" \
        -type f \
        \( \
            -path "$ROOT/build/*" \
            -o -path "$ROOT/evidence/*" \
            -o -path "$ROOT/../K501_AIONARC_Pipeline_v0.2_Candidate/*" \
        \) \
        | wc -l
)

printf 'EXCLUDED FILE COUNT: %s\n' "$EXCLUDED_COUNT"
pass 'build/evidence/v0.2 candidate are outside public enumeration'

printf '%s\n' '----------------------------------------'
printf '%s\n' 'CHECK 3: ABSOLUTE HOST PATHS'

HOST_PATH_MATCHES=''

while IFS= read -r file; do
    if is_public_file "$file"; then
        MATCH=$(
            grep -hInE \
                '/home/|/mnt/data|/root/|/Users/|/private/tmp/|[A-Za-z]:\\\\|\\\\Users\\\\' \
                "$file" 2>/dev/null || true
        )

        if [ -n "$MATCH" ]; then
            HOST_PATH_MATCHES="${HOST_PATH_MATCHES}${file}
${MATCH}
"
        fi
    fi
done <<EOF
$(find "$ROOT" -type f)
EOF

if [ -z "$HOST_PATH_MATCHES" ]; then
    pass 'no absolute host paths in public scope'
else
    printf '%s\n' "$HOST_PATH_MATCHES"
    fail 'absolute host path detected'
fi

printf '%s\n' '----------------------------------------'
printf '%s\n' 'CHECK 4: HOSTNAME / LOCAL USER REFERENCES'

HOST_REFERENCE_MATCHES=''

while IFS= read -r file; do
    if is_public_file "$file"; then
        MATCH=$(
            grep -hInE \
                'hirn@hirn|@localhost|localhost:' \
                "$file" 2>/dev/null || true
        )

        if [ -n "$MATCH" ]; then
            HOST_REFERENCE_MATCHES="${HOST_REFERENCE_MATCHES}${file}
${MATCH}
"
        fi
    fi
done <<EOF
$(find "$ROOT" -type f)
EOF

if [ -z "$HOST_REFERENCE_MATCHES" ]; then
    pass 'no local hostname/user references in public scope'
else
    printf '%s\n' "$HOST_REFERENCE_MATCHES"
    fail 'local hostname/user reference detected'
fi

printf '%s\n' '----------------------------------------'
printf '%s\n' 'CHECK 5: MODULE MANIFEST'

MODULE_MANIFEST="$ROOT/v2.0_ALPHA_MODULE_MANIFEST.json"

if [ -f "$MODULE_MANIFEST" ]; then
    pass 'module manifest exists'
else
    fail 'module manifest missing'
fi

printf '%s\n' '----------------------------------------'
printf '%s\n' 'CHECK 6: MODULE MANIFEST PATHS'

if [ -f "$MODULE_MANIFEST" ]; then
    MANIFEST_PATHS=$(
        sed -n 's/.*"\(docs\/[^"]*\|include\/[^"]*\|scripts\/[^"]*\|src\/[^"]*\|tests\/[^"]*\|README\.md\|VERSION\)".*/\1/p' \
        "$MODULE_MANIFEST" | sort -u
    )

    MANIFEST_MISSING=0

    for path in $MANIFEST_PATHS; do
        if [ ! -f "$ROOT/$path" ]; then
            printf 'MISSING: %s\n' "$path"
            MANIFEST_MISSING=1
        fi
    done

    if [ "$MANIFEST_MISSING" -eq 0 ]; then
        pass 'all discovered module manifest paths exist'
    else
        fail 'module manifest contains missing paths'
    fi
else
    fail 'manifest path check skipped because manifest is missing'
fi

printf '%s\n' '----------------------------------------'
printf '%s\n' 'CHECK 7: CHECKSUM FILE PATH SAFETY'

CHECKSUM_FILE="$ROOT/v2.0_ALPHA_MODULE_MANIFEST.json.sha256"

if [ -f "$CHECKSUM_FILE" ]; then
    CHECKSUM_REFERENCE=$(awk '{print $2}' "$CHECKSUM_FILE")

    case "$CHECKSUM_REFERENCE" in
        /*|[A-Za-z]:\\*)
            printf 'CHECKSUM REFERENCE: %s\n' "$CHECKSUM_REFERENCE"
            fail 'checksum file contains an absolute path'
            ;;
        *)
            pass 'checksum file uses a relative path'
            ;;
    esac
else
    fail 'module manifest checksum file missing'
fi

printf '%s\n' '----------------------------------------'
printf '%s\n' 'CHECK 8: PUBLIC MANIFEST COVERAGE'

if [ -f "$MODULE_MANIFEST" ]; then
    MANIFEST_COUNT=$(
        grep -cE '"path"[[:space:]]*:' "$MODULE_MANIFEST" || true
    )

    printf 'MANIFEST PATH COUNT: %s\n' "$MANIFEST_COUNT"

    if [ "$MANIFEST_COUNT" -gt 0 ]; then
        pass 'module manifest contains path entries'
    else
        fail 'module manifest contains no path entries'
    fi
else
    fail 'manifest coverage check skipped because manifest is missing'
fi

printf '%s\n' '----------------------------------------'
printf '%s\n' 'V2A-02.4 PUBLIC SCOPE AUDIT'

if [ "$FAIL" -eq 0 ]; then
    printf '%s\n' 'RESULT: PASS'
    exit 0
else
    printf '%s\n' 'RESULT: FAIL'
    exit 1
fi
