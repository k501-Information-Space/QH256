#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
OUT="$ROOT/v2.0_ALPHA_FILE_MANIFEST.sha256"
( cd "$ROOT" && find . -type f ! -path './build/*' ! -name 'v2.0_ALPHA_FILE_MANIFEST.sha256' ! -name 'v2.0_ALPHA_MODULE_MANIFEST.json' -print0 | sort -z | xargs -0 sha256sum ) > "$OUT"
printf '%s\n' "WROTE: $OUT"
