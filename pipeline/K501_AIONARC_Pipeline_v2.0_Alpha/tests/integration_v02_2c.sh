#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
CORE_DIR=${QH256_CORE_DIR:-"$ROOT/../../tests/validation/v2.0"}
CC=${CC:-cc}; CFLAGS=${CFLAGS:-"-std=c11 -O2 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -Werror"}
mkdir -p "$ROOT/build"
$CC $CFLAGS -I"$CORE_DIR" "$ROOT/tests/integration_v02_2c.c" "$CORE_DIR/qh256.c" -o "$ROOT/build/v02_2c"
"$ROOT/build/v02_2c"
