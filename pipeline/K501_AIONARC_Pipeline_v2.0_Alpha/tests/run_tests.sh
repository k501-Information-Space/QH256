#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
CORE_DIR=${QH256_CORE_DIR:-"$ROOT/../../tests/validation/v2.0"}
CC=${CC:-cc}; CFLAGS=${CFLAGS:-"-std=c11 -O2 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -Werror"}
mkdir -p "$ROOT/build/tests"
$CC $CFLAGS -I"$ROOT/include" -I"$CORE_DIR" "$ROOT/tests/test_known_vectors.c" "$ROOT/src/common/sha256.c" "$ROOT/src/object_record/object_record.c" "$ROOT/src/common/bytes.c" "$CORE_DIR/qh256.c" -o "$ROOT/build/tests/test_known_vectors"
"$ROOT/build/tests/test_known_vectors"

$CC $CFLAGS -I"$ROOT/include" "$ROOT/tests/test_negative_record.c" "$ROOT/src/common/sha256.c" "$ROOT/src/object_record/object_record.c" "$ROOT/src/common/bytes.c" -o "$ROOT/build/tests/test_negative_record"
"$ROOT/build/tests/test_negative_record"
