#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
CORE_DIR=${QH256_CORE_DIR:-"$ROOT/../../tests/validation/v2.0"}
CC=${CC:-cc}
CFLAGS=${CFLAGS:-"-std=c11 -O2 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -Werror"}
[ -f "$CORE_DIR/qh256.h" ] || { echo "ERROR: missing $CORE_DIR/qh256.h" >&2; exit 2; }
[ -f "$CORE_DIR/qh256.c" ] || { echo "ERROR: missing $CORE_DIR/qh256.c" >&2; exit 2; }
BUILD="$ROOT/build"; rm -rf "$BUILD"; mkdir -p "$BUILD"
$CC $CFLAGS -I"$ROOT/include" -I"$CORE_DIR" \
  "$ROOT/src/common/sha256.c" "$ROOT/src/common/bytes.c" \
  "$ROOT/src/ingest/ingest.c" "$ROOT/src/object_record/object_record.c" \
  "$ROOT/src/qh256_mapping/mapping.c" "$ROOT/src/state/history.c" \
  "$ROOT/src/pipeline/main.c" "$CORE_DIR/qh256.c" \
  -o "$BUILD/k501_aionarc_pipeline_alpha"
printf '%s\n' "BUILD PASS: $BUILD/k501_aionarc_pipeline_alpha"
