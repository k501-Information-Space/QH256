#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
CC=${CC:-cc}; CFLAGS=${CFLAGS:-"-std=c11 -O2 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -Werror"}
mkdir -p "$ROOT/build"
$CC $CFLAGS -I"$ROOT/include" -I"$ROOT/tests/stub_qh256" \
  "$ROOT/src/common/sha256.c" "$ROOT/src/common/bytes.c" "$ROOT/src/ingest/ingest.c" \
  "$ROOT/src/object_record/object_record.c" "$ROOT/src/qh256_mapping/mapping.c" \
  "$ROOT/src/state/history.c" "$ROOT/src/pipeline/main.c" \
  "$ROOT/tests/stub_qh256/qh256.c" -o "$ROOT/build/pipeline_stub"
printf '%s\n' 'STUB COMPILE PASS'
