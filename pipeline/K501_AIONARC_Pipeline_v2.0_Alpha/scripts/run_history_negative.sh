#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
BAD="$ROOT/build/history_bad.bin"
cp "$ROOT/build/run_a/history.bin" "$BAD"
printf '\377' | dd of="$BAD" bs=1 seek=40 conv=notrunc status=none
if "$ROOT/build/k501_aionarc_verify_alpha" "$ROOT/build/run_a/records.bin" "$BAD" >/dev/null 2>&1; then echo 'FAIL: tampered history accepted'; exit 1; fi
echo 'PASS: tampered history rejected'
