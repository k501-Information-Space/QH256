# QH256 — K501 Information Space

**Repository root:** this is the visible landing page. The Information Space control surface is exposed here; existing QH256 project payload remains at established paths.

## Current entrypoints

- **Gateway:** [Gateway.md](Gateway.md) / [Gateway.json](Gateway.json).
- **Complete Index:** [Index.md](Index.md) / [Index.json](Index.json) — every file and directory path, classified by layer.
- **Current structure:** [v0.3 Markdown](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.3.md) / [v0.3 JSON](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.3.json).
- **Current reconciliation frame:** [Frame 002](frames/FRAME_002_RECONCILIATION.md) / [machine record](frames/FRAME_002_RECONCILIATION.json).
- **Historical transitions:** [Frame 001](frames/FRAME_001_ROOT_ENTRYPOINT.md) and [Frame 000](frames/FRAME_000_BOOTSTRAP.md).
- **Operator manual:** [docs/OPERATOR_MANUAL.md](docs/OPERATOR_MANUAL.md).
- **Run schema:** [runs/run.schema.json](runs/run.schema.json).
- **Scoped integrity set:** [MANIFEST.json](MANIFEST.json), [SHA256SUMS.txt](SHA256SUMS.txt), [sidecar](SHA256SUMS.txt.sha256).

## Two distinct layers

| Layer | Locations | Meaning |
|---|---|---|
| Information Space control surface | `Gateway.*`, `Index.*`, `frames/`, `runs/run.schema.json`, `specifications/`, `docs/OPERATOR_MANUAL.md`, `MANIFEST.json`, checksums, `LICENSE_SCOPE.md` | Navigation, structural records, run schema and scoped integrity metadata. |
| Existing QH256 payload | `.gitignore`, `LICENSE`, remaining `docs/`, `metadata/`, `obsolete/`, `pipeline/`, `references/`, `releases/`, `scripts/`, `tests/` | Identity, project documentation, implementation, archive, references, releases and validation. |

`docs/` is shared: `docs/OPERATOR_MANUAL.md` is control surface; other files remain QH256 documentation. Index 0.3 classifies each path. Existing payload paths are not copied, moved or removed by this reconciliation.

## QH256 boundary

QH256 is a deterministic four-state information algebra and 256-bit state representation: 128 cells, two evidence bits per cell, 256 bits / 32 bytes total. `UNKNOWN = 00`, `FALSE = 01`, `TRUE = 10`, `GUARD = 11`; state-space cardinality is `2^256`.

QH256 is not an archive, probabilistic model, embedding or semantic interpreter. Gateway and Index provide navigation; they do not redefine the algebra or prove semantic correctness.

## Existing QH256 payload remains in place

- `docs/`: architecture, reconstruction/evidence, history, validation status and repository guidance, except operator manual.
- `metadata/`: repository identity and release metadata.
- `obsolete/alpha/`: historical alpha artifacts retained as an archive.
- `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/`: existing versioned pipeline.
- `references/`, `releases/`, `scripts/`, `tests/validation/`: reference, release, script and validation artifacts.

Frame 002 removes no existing source, test, release, reference, metadata or archive path.

## Historical paths are not active paths

Frame 000 and specification v0.1 preserve the initial nested layout. Values such as `information-space/Gateway.md` are historical strings, not live destinations. Use the [current path crosswalk in v0.3](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.3.md#historical-path-crosswalk). The nested tree is not recreated and historical records are not rewritten.

## Validation record

The repository contains `tests/validation/v0.1/` and `tests/validation/v2.0/`. The v2.0 record documents 6,620,625 assertions, 0 failures and PASS within its declared machine-checkable scope. This navigation correction does not re-run those executable tests.

## Principles

`PROOF_BEFORE_STATE` · `RECONSTRUCT_BEFORE_EXTEND` · `APPEND_ONLY` · `NO_DRIFT` · `NO_PHANTOM` · `NO_INTERPRETATION` · `STRUCTURE_PRECEDES_MEANING` · `TRACEABILITY_REQUIRED` · `DERIVED_IS_NOT_CANONICAL`

## External references

- Zenodo: https://zenodo.org/records/21957465
- ORCID: https://orcid.org/0009-0004-3275-9545
- Mastodon: https://mastodon.social/@K501
- DEV Community: https://dev.to/k501is/qh256-in-c-a-deterministic-256-bit-state-structure-for-k501-aionarc-3bji
- GitHub: https://github.com/k501-Information-Space
- Website: https://www.iinkognit0.de/

## Author

Patrick R. Miller (Iinkognit0) · K501 / K501-AIONARC
