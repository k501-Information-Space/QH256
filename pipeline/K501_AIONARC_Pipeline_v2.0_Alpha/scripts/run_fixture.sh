#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
INPUT="$ROOT/build/fixture_input"
OUT1="$ROOT/build/run_a"
rm -rf "$INPUT" "$OUT1"
mkdir -p "$INPUT/subdir"
printf '%s' '' > "$INPUT/01_empty.txt"
printf '%s' 'alpha fixture' > "$INPUT/02_text.txt"
printf '%s' 'nested' > "$INPUT/subdir/03_nested.txt"
printf '%s' 'link-target' > "$INPUT/link_target.txt"
ln -s link_target.txt "$INPUT/link_to_regular"
python3 - "$INPUT" <<'PY'
import os, sys
root=os.fsencode(sys.argv[1])
name=b'invalid-' + bytes([0xff]) + b'.bin'
fd=os.open(root+b'/'+name, os.O_WRONLY|os.O_CREAT|os.O_TRUNC, 0o644)
os.write(fd, b'raw-byte-path')
os.close(fd)
PY
"$ROOT/scripts/build.sh"
"$ROOT/build/k501_aionarc_pipeline_alpha" --root-id ROOT_TEST_V2_ALPHA "$INPUT" "$OUT1"
"$ROOT/tests/run_tests.sh"
python3 - "$OUT1/manifest.json" <<'PY'
import json,sys
m=json.load(open(sys.argv[1],encoding='utf-8'))
assert m['count']==7, m['count']
assert any('ff' in x['path_hex'] for x in m['records'])
print('PASS: raw invalid-UTF8 pathname preserved in projection')
PY
