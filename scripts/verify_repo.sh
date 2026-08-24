#!/usr/bin/env bash
set -euo pipefail

ROOT=$(cd "$(dirname "$0")/.." && pwd)
fail=0

required=(
  README.md
  docs/ARCHITECTURE.md
  docs/PROOF_BEFORE_STATE.md
  docs/VALIDATION_STATUS.md
  docs/AUTHORSHIP.md
  docs/HISTORY.md
  references/REFERENCES.md
  metadata/qh256.repository.json
)

for f in "${required[@]}"; do
  if [[ ! -f "$ROOT/$f" ]]; then
    echo "MISSING: $f"
    fail=1
  else
    echo "OK: $f"
  fi
done

python3 - <<PY
import json
from pathlib import Path
p = Path("$ROOT/metadata/qh256.repository.json")
obj = json.loads(p.read_text())
assert obj["structure"]["bits"] == 256
assert obj["structure"]["bytes"] == 32
assert obj["structure"]["state_space"] == "2^256"
assert obj["validation"]["v2.0"]["assertions"] == 6620625
assert obj["validation"]["v2.0"]["failures"] == 0
print("OK: machine-readable metadata")
PY

exit "$fail"
