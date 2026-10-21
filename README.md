# QH256 — K501 Information Space

**Repository entrypoint:** the Information Space navigation is maintained at this repository root. Begin here; the navigation layer is not hidden in a subdirectory.

## Start here

- **Gateway:** [Gateway.md](Gateway.md) / [Gateway.json](Gateway.json) — stable human- and machine-readable entrypoint.
- **Index:** [Index.md](Index.md) / [Index.json](Index.json) — derived map of the current structure and referenced repository artifacts.
- **Current transition frame:** [Frame 001](frames/FRAME_001_ROOT_ENTRYPOINT.md) / [machine record](frames/FRAME_001_ROOT_ENTRYPOINT.json) — records the move to root-level navigation.
- **Initial frame:** [Frame 000](frames/FRAME_000_BOOTSTRAP.md) / [machine record](frames/FRAME_000_BOOTSTRAP.json) — preserved initial bootstrap declaration.
- **Operator manual:** [docs/OPERATOR_MANUAL.md](docs/OPERATOR_MANUAL.md).
- **Current structure contract:** [v0.2 Markdown](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.2.md) / [v0.2 JSON](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.2.json).
- **Run schema:** [runs/run.schema.json](runs/run.schema.json).
- **Integrity:** [MANIFEST.json](MANIFEST.json), [SHA-256 list](SHA256SUMS.txt), [checksum sidecar](SHA256SUMS.txt.sha256).
- **License scope:** [LICENSE_SCOPE.md](LICENSE_SCOPE.md), pointing to the existing root [LICENSE](LICENSE).

## Root-level Information Space layout

```text
QH256/
├── README.md                       # Repository landing page
├── Gateway.md / Gateway.json       # Human/machine entrypoint
├── Index.md / Index.json           # Derived navigation index
├── frames/
│   ├── FRAME_000_BOOTSTRAP.*
│   └── FRAME_001_ROOT_ENTRYPOINT.*
├── runs/run.schema.json
├── specifications/
│   ├── K501_INFORMATION_SPACE_STRUCTURE_v0.1.*  # Initial layout record
│   └── K501_INFORMATION_SPACE_STRUCTURE_v0.2.*  # Current root-level contract
├── docs/OPERATOR_MANUAL.md
├── LICENSE_SCOPE.md
├── MANIFEST.json
├── SHA256SUMS.txt
└── SHA256SUMS.txt.sha256
```

The previous nested layout is superseded by these root-level paths. Frame 000 and the v0.1 contract are retained unchanged as records of the initial layout; Frame 001 records the transition. The Git history preserves the prior commit and original paths.

## QH256 — canonical repository

QH256 is a deterministic four-state information algebra and 256-bit state representation developed within the K501-AIONARC Information Space.

- 128 cells
- 2 evidence bits per cell
- 256 bits total
- 32 bytes physical state size
- `UNKNOWN = 00`
- `FALSE = 01`
- `TRUE = 10`
- `GUARD = 11`

The mathematical state-space cardinality is `2^256`.

QH256 is a state representation, not a historical archive, probabilistic model, embedding, or semantic interpreter. History and provenance remain external.

## Validation status

The repository contains two validation generations:

- `tests/validation/v0.1/` — initial QH256 Validation PoC / alpha validation lineage.
- `tests/validation/v2.0/` — expanded machine-checkable validation corresponding to QH256 Formal Specification v2.0.

The v2.0 validation record documents 6,620,625 assertions, 0 failures, and PASS within the declared machine-checkable specification scope, with normal C11 execution and an AddressSanitizer/UndefinedBehaviorSanitizer path.

## Repository principles

`PROOF_BEFORE_STATE` · `RECONSTRUCT_BEFORE_EXTEND` · `APPEND_ONLY` · `NO_DRIFT` · `NO_INTERPRETATION` · `STRUCTURE_PRECEDES_MEANING` · `TRACEABILITY_REQUIRED` · `DERIVED_IS_NOT_CANONICAL`

## Existing repository organization

Architecture and scientific context remain in `docs/`; machine-readable repository metadata remains in `metadata/`; versioned validation evidence remains in `tests/`. Existing implementation, historical artifacts, releases, and references are not redefined by this navigation layer.

## Canonical external references

- Zenodo: https://zenodo.org/records/21957465
- ORCID: https://orcid.org/0009-0004-3275-9545
- Mastodon: https://mastodon.social/@K501
- DEV Community: https://dev.to/k501is/qh256-in-c-a-deterministic-256-bit-state-structure-for-k501-aionarc-3bji
- K501 GitHub: https://github.com/k501-Information-Space
- Website: https://www.iinkognit0.de/

## Author

Patrick R. Miller (Iinkognit0) · K501 / K501-AIONARC  
ORCID: https://orcid.org/0009-0004-3275-9545

**Boundary:** This navigation layer organizes access to source, specifications, validation, historical records, and evidence. It does not redefine QH256 or turn it into an archive or semantic interpreter.
