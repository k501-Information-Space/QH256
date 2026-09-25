#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
CORE_DIR=${QH256_CORE_DIR:-"$ROOT/../../tests/validation/v2.0"}
CC=${CC:-cc}
CFLAGS=${CFLAGS:-"-std=c11 -O1 -g -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -Werror -fsanitize=address,undefined -fno-omit-frame-pointer"}
mkdir -p "$ROOT/build/asan"
$CC $CFLAGS -I"$ROOT/include" -I"$CORE_DIR" \
  "$ROOT/src/common/sha256.c" "$ROOT/src/common/bytes.c" "$ROOT/src/ingest/ingest.c" \
  "$ROOT/src/object_record/object_record.c" "$ROOT/src/qh256_mapping/mapping.c" \
  "$ROOT/src/state/history.c" "$ROOT/src/pipeline/main.c" "$CORE_DIR/qh256.c" \
  -o "$ROOT/build/asan/pipeline_alpha_asan"
"$ROOT/build/asan/pipeline_alpha_asan" "$ROOT/build/fixture_input" "$ROOT/build/run_asan"
printf '%s\n' 'PASS: ASan/UBSan alpha execution'
