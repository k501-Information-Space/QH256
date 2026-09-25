#!/bin/sh
set -eu

ROOT="$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)"
OUT="$ROOT/evidence/V2A-02_REPOSITORY_SCOPE"

CANDIDATE="$ROOT/../K501_AIONARC_Pipeline_v0.2_Candidate"

mkdir -p "$OUT"

{
    printf '%s\n' 'K501-AIONARC PIPELINE V2.0 ALPHA'
    printf '%s\n' 'GATE: V2A-02'
    printf '%s\n' 'SUBGATE: 02.1 REPOSITORY SCOPE'
    printf '%s\n' 'MODE: SCOPE RECORD'
    printf '%s\n' 'TIME_ANCHOR_UNIX:'
    printf '%s\n' '1789762535'
    printf '%s\n' 'TIME_ANCHOR_UTC:'
    printf '%s\n' '2026-09-18 20:15:35 UTC'
    printf '%s\n' 'TIME_ANCHOR_EUROPE_BERLIN:'
    printf '%s\n' '2026-09-18 22:15:35 CEST'
    printf '%s\n' '---'
    printf '%s\n' 'QH256 ONLINE REPOSITORY SCOPE'
    printf '%s\n' 'INCLUDE: pipeline/K501_AIONARC_Pipeline_v2.0_Alpha'
    printf '%s\n' 'EXCLUDE: pipeline/K501_AIONARC_Pipeline_v0.2_Candidate'
    printf '%s\n' '---'
    printf '%s\n' 'V0.2 CANDIDATE STATUS'
    printf '%s\n' 'HISTORICAL DEVELOPMENT ARTIFACT'
    printf '%s\n' 'NOT MERGED'
    printf '%s\n' 'NOT RELEASED IN QH256 REPOSITORY'
    printf '%s\n' 'NOT PART OF V2.0 ALPHA RELEASE SCOPE'
    printf '%s\n' 'FUTURE ARCHIVE TARGET: K501-AIONARC eArc'
    printf '%s\n' '---'
    printf '%s\n' 'RATIONALE'
    printf '%s\n' 'Prevent parallel public pipeline definitions and release-scope drift.'
    printf '%s\n' 'Historical preservation remains append-only.'
    printf '%s\n' '---'
    printf '%s\n' 'V0.2 FILE HASHES'
    sha256sum \
        "$CANDIDATE/README.md" \
        "$CANDIDATE/scripts/README.md" \
        "$CANDIDATE/v0.2_MODULE_MANIFEST.json"
} > "$OUT/V2A-02_SCOPE.txt"

sha256sum "$OUT/V2A-02_SCOPE.txt" > "$OUT/V2A-02_SCOPE.sha256"

printf '%s\n' 'V2A-02 SCOPE RECORD COMPLETE'
printf '%s\n' "OUTPUT: $OUT"
cat "$OUT/V2A-02_SCOPE.sha256"
