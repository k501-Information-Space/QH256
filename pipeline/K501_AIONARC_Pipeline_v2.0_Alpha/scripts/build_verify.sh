#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
CORE_DIR=${QH256_CORE_DIR:-"$ROOT/../../tests/validation/v2.0"}
CC=${CC:-cc}; CFLAGS=${CFLAGS:-"-std=c11 -O2 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -Werror"}
$CC $CFLAGS -I"$ROOT/include" -I"$CORE_DIR" "$ROOT/src/common/sha256.c" "$ROOT/src/common/bytes.c" "$ROOT/src/object_record/object_record.c" "$ROOT/src/state/history.c" "$ROOT/src/pipeline/verify.c" "$CORE_DIR/qh256.c" -o "$ROOT/build/k501_aionarc_verify_alpha"
printf '%s\n' 'VERIFY BUILD PASS'
