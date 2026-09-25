#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
BASE="$ROOT/build/fixture_input"
A="$ROOT/build/mutation_input_a"
B="$ROOT/build/mutation_input_b"
OA="$ROOT/build/mutation_out_a"
OB="$ROOT/build/mutation_out_b"
rm -rf "$A" "$B" "$OA" "$OB"
cp -a "$BASE" "$A"
cp -a "$BASE" "$B"
"$ROOT/build/k501_aionarc_pipeline_alpha" --root-id ROOT_TEST_V2_ALPHA "$A" "$OA"
printf '%s' 'alpha fixture MUTATED' > "$B/02_text.txt"
"$ROOT/build/k501_aionarc_pipeline_alpha" --root-id ROOT_TEST_V2_ALPHA "$B" "$OB"
python3 - "$OA/manifest.json" "$OB/manifest.json" <<'PY'
import json,sys
A=json.load(open(sys.argv[1],encoding='utf-8'))['records']
B=json.load(open(sys.argv[2],encoding='utf-8'))['records']
a={x['path_hex']:x for x in A}; b={x['path_hex']:x for x in B}
k='30325f746578742e747874'
assert a[k]['object_id']==b[k]['object_id']
assert a[k]['record_hash']!=b[k]['record_hash']
print('PASS: content mutation leaves object_id stable and changes record_hash')
PY
