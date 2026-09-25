#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
QH256_CORE_DIR=${QH256_CORE_DIR:-"$ROOT/../../tests/validation/v2.0"} "$ROOT/scripts/build_verify.sh"
A="$ROOT/build/negative_a"; B="$ROOT/build/negative_b"; rm -rf "$A" "$B"; cp -a "$ROOT/build/run_a" "$A"; cp -a "$A" "$B"
printf '\000' | dd of="$B/records.bin" bs=1 seek=0 conv=notrunc status=none
if "$ROOT/build/k501_aionarc_verify_alpha" "$B/records.bin" "$B/history.bin" >/dev/null 2>&1; then
  echo 'FAIL: tampered record set accepted'; exit 1
fi
echo 'PASS: tampered record set rejected'
