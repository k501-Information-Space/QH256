# K501 Information Space Structure Specification v0.3

**Status:** Current repository reconciliation contract  
**Scope:** Complete path inventory and separation of the Information Space control surface from existing QH256 payload  
**Time anchor:** `1792578946` · **Input main commit:** `5cd7e4a6d0a30fcdab5bfee5978f5dc9d58a5d09`

## Purpose

v0.3 is the active structural contract. v0.2 remains the unchanged root-entrypoint transition record; v0.1 remains the unchanged initial nested-layout record. Root-level presentation does not make the existing QH256 payload part of the control surface.

## Layer A — Information Space control surface

- `README.md`, `Gateway.md`, `Gateway.json`: landing and stable entry.
- `Index.md`, `Index.json`: complete derived inventory of every file and directory.
- `frames/`: append-only structural records; Frame 002 records this reconciliation.
- `runs/run.schema.json`: bounded run/evidence schema.
- `specifications/`: v0.3 current; v0.1/v0.2 historical.
- `docs/OPERATOR_MANUAL.md`: gate-based instructions.
- `MANIFEST.json`, `SHA256SUMS.txt`, `SHA256SUMS.txt.sha256`: integrity data for the declared control-surface scope.
- `LICENSE_SCOPE.md`: scope pointer; `LICENSE` remains the actual license text.

## Layer B — existing QH256 payload

Existing paths remain in place and are classified, not copied into navigation: `.gitignore`, `LICENSE`, other existing `docs/` files, `metadata/`, `obsolete/alpha/`, `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/`, `references/`, `releases/`, `scripts/`, and `tests/validation/`.

`docs/` is a shared container; children are classified individually. A Gateway link does not change the target artifact's classification or meaning.

## Inventory contract

1. Index 0.3 lists every path from input commit `5cd7e4a6d0a30fcdab5bfee5978f5dc9d58a5d09`, plus the four paths added by Frame 002.
2. The candidate inventory contains 150 entries: 146 source-tree entries plus four new frame/specification paths.
3. Every entry has path, tree kind, role and classification. The Index is derived navigation metadata, not content identity or semantic proof.
4. No existing QH256 payload path is removed.
5. Frame 000, Frame 001, and specifications v0.1/v0.2 remain byte-for-byte unchanged.
6. The manifest names the control-surface and selected referenced files it hashes; it does not claim to hash every QH256 payload byte.
7. SHA-256 values cover exact UTF-8 bytes; the checksum list contains the manifest hash and its sidecar hashes the checksum list.

## Historical path crosswalk

These initial nested-layout values are historical identifiers, not active paths. Do not recreate the removed nested tree solely to satisfy old path strings.

| Historical path | Current path / resolution |
|---|---|
| `information-space/Gateway.md` | `Gateway.md` |
| `information-space/Gateway.json` | `Gateway.json` |
| `information-space/Index.md` | `Index.md` |
| `information-space/Index.json` | `Index.json` |
| `information-space/frames/` | `frames/` |
| `information-space/runs/run.schema.json` | `runs/run.schema.json` |
| `information-space/docs/OPERATOR_MANUAL.md` | `docs/OPERATOR_MANUAL.md` |
| `information-space/LICENSE.md` | `LICENSE_SCOPE.md (scope pointer); LICENSE remains authoritative` |
| `information-space/MANIFEST.json` | `MANIFEST.json` |
| `information-space/SHA256SUMS.txt` | `SHA256SUMS.txt` |

The same crosswalk is represented in `Gateway.json` and Frame 002. Current Gateway links refer only to live paths.

## Invariants

`PROOF_BEFORE_STATE` · `RECONSTRUCT_BEFORE_EXTEND` · `APPEND_ONLY` · `NO_DRIFT` · `NO_PHANTOM` · `DERIVED_IS_NOT_CANONICAL`

Historical records are not rewritten. Existing implementation, validation, release, reference and archive paths are not moved, duplicated or reinterpreted. Canonicality derives from the default branch and verified commit history.
