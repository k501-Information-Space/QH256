#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
"$ROOT/tests/integration_v02_2c.sh"
"$ROOT/scripts/build.sh"
"$ROOT/scripts/build_verify.sh"
"$ROOT/tests/run_tests.sh"
rm -rf "$ROOT/build/fixture_input" "$ROOT/build/run_a" "$ROOT/build/run_b" "$ROOT/build/run_asan" "$ROOT/build/mutation_input_a" "$ROOT/build/mutation_input_b" "$ROOT/build/mutation_out_a" "$ROOT/build/mutation_out_b" "$ROOT/build/history_bad.bin" "$ROOT/build/negative_a" "$ROOT/build/negative_b"
mkdir -p "$ROOT/build/fixture_input/subdir"
: > "$ROOT/build/fixture_input/01_empty.txt"
printf '%s' 'alpha fixture' > "$ROOT/build/fixture_input/02_text.txt"
printf '%s' 'nested' > "$ROOT/build/fixture_input/subdir/03_nested.txt"
printf '%s' 'link-target' > "$ROOT/build/fixture_input/link_target.txt"
ln -s link_target.txt "$ROOT/build/fixture_input/link_to_regular"
python3 - "$ROOT/build/fixture_input" <<'PY'
import os,sys
r=os.fsencode(sys.argv[1]); n=b'invalid-'+bytes([255])+b'.bin'
fd=os.open(r+b'/'+n,os.O_WRONLY|os.O_CREAT|os.O_TRUNC,0o644); os.write(fd,b'raw-byte-path'); os.close(fd)
PY
"$ROOT/build/k501_aionarc_pipeline_alpha" --root-id ROOT_TEST_V2_ALPHA "$ROOT/build/fixture_input" "$ROOT/build/run_a"
"$ROOT/build/k501_aionarc_verify_alpha" "$ROOT/build/run_a/records.bin" "$ROOT/build/run_a/history.bin"
"$ROOT/build/k501_aionarc_pipeline_alpha" --root-id ROOT_TEST_V2_ALPHA "$ROOT/build/fixture_input" "$ROOT/build/run_b"
for f in records.bin history.bin manifest.json; do cmp "$ROOT/build/run_a/$f" "$ROOT/build/run_b/$f"; done
echo 'PASS: second-run byte equality'
python3 - "$ROOT/build/run_a/manifest.json" <<'PY'
import json,sys
m=json.load(open(sys.argv[1],encoding='utf-8'))
assert m['count']==7
assert any('ff' in x['path_hex'] for x in m['records'])
print('PASS: raw invalid-UTF8 path preserved')
PY
"$ROOT/scripts/run_mutation_proof.sh"
"$ROOT/scripts/run_negative_validation.sh"
"$ROOT/scripts/run_history_negative.sh"
"$ROOT/scripts/run_asan.sh"
printf '%s\n' 'V2.0 ALPHA VALIDATION COMPLETE (external QH256 v2.0 core)'
