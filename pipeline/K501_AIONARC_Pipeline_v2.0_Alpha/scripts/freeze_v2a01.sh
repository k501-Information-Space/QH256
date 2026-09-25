#!/bin/sh
set -eu

ROOT="$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)"
OUT="$ROOT/evidence/V2A-01_STATE_FREEZE"

mkdir -p "$OUT"

{
printf '%s\n' 'K501-AIONARC PIPELINE V2.0 ALPHA'
printf '%s\n' 'GATE: V2A-01'
printf '%s\n' 'MODE: RECONSTRUCTION / STATE FREEZE'
printf '%s\n' 'ROOT:'
printf '%s\n' "$ROOT"
printf '%s\n' 'TIME_ANCHOR_UNIX:'
printf '%s\n' '1789761261'
printf '%s\n' 'TIME_ANCHOR_UTC:'
printf '%s\n' '2026-09-18 19:54:21 UTC'
printf '%s\n' 'TIME_ANCHOR_EUROPE_BERLIN:'
printf '%s\n' '2026-09-18 21:54:21 CEST'
printf '%s\n' '---'
printf '%s\n' 'GIT ROOT'
git -C "$ROOT/../.." rev-parse --show-toplevel
printf '%s\n' 'GIT BRANCH'
git -C "$ROOT/../.." rev-parse --abbrev-ref HEAD
printf '%s\n' 'GIT HEAD'
git -C "$ROOT/../.." rev-parse HEAD
printf '%s\n' 'GIT STATUS'
git -C "$ROOT/../.." status --branch --porcelain=v1
printf '%s\n' '---'
printf '%s\n' 'ALPHA FILES'
find "$ROOT" -type f ! -path "$OUT/*" -print | LC_ALL=C sort
} > "$OUT/STATE_FREEZE.txt"

(
cd "$ROOT"
find . -type f ! -path './evidence/V2A-01_STATE_FREEZE/*' -print0 | LC_ALL=C sort -z | xargs -0 sha256sum
) > "$OUT/FILES_SHA256.txt"

sha256sum "$OUT/STATE_FREEZE.txt" "$OUT/FILES_SHA256.txt" > "$OUT/FREEZE_SHA256.txt"

printf '%s\n' 'V2A-01 FREEZE COMPLETE'
printf '%s\n' "OUTPUT: $OUT"
cat "$OUT/FREEZE_SHA256.txt"
