#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
INPUT="$ROOT/build/fixture_input"
A="$ROOT/build/run_a"
B="$ROOT/build/run_b"
rm -rf "$B"
"$ROOT/build/k501_aionarc_pipeline_alpha" --root-id ROOT_TEST_V2_ALPHA "$INPUT" "$B"
cmp "$A/records.bin" "$B/records.bin"
cmp "$A/history.bin" "$B/history.bin"
cmp "$A/manifest.json" "$B/manifest.json"
printf '%s\n' 'PASS: deterministic second-run byte equality'
