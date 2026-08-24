# QH256 — K501 Information Space

## Canonical Repository

QH256 is a deterministic 256-bit information-state structure developed within the K501-AIONARC Information Space.

Canonical structure:

- 128 cells
- 2 evidence bits per cell
- 256 bits total
- 32 bytes physical state size
- `UNKNOWN = 00`
- `FALSE = 01`
- `TRUE = 10`
- `GUARD = 11`

The mathematical state-space cardinality is `2^256`.

QH256 is a state representation, not a historical archive, probabilistic model, embedding, or semantic interpreter. Historical provenance remains external to the aggregate state.

## Validation Status

The repository contains two validation generations:

- `tests/validation/v0.1/` — initial QH256 Validation PoC / alpha validation lineage.
- `tests/validation/v2.0/` — expanded machine-checkable validation corresponding to the QH256 Formal Specification v2.0.

The v2.0 validation record currently documents:

`6,620,625 assertions`

`0 failures`

`PASS`

with normal C11 execution and a sanitizer execution path covering AddressSanitizer and UndefinedBehaviorSanitizer.

## Repository Principles

`PROOF_BEFORE_STATE`

`RECONSTRUCT_BEFORE_EXTEND`

`APPEND_ONLY`

`NO_DRIFT`

`NO_INTERPRETATION`

`STRUCTURE_PRECEDES_MEANING`

`TRACEABILITY_REQUIRED`

`DERIVED_IS_NOT_CANONICAL`

## Human / Machine Readability

Human-readable architectural and scientific context is maintained in `docs/`.

Machine-readable metadata is maintained in `metadata/`.

Validation artifacts remain separated by version so that historical reproducibility is not silently overwritten.

## Canonical External References

- Zenodo: https://zenodo.org/records/21957465
- ORCID: https://orcid.org/0009-0004-3275-9545
- Mastodon: https://mastodon.social/@K501
- DEV Community: https://dev.to/k501is/qh256-in-c-a-deterministic-256-bit-state-structure-for-k501-aionarc-3bji
- K501 GitHub organization: https://github.com/k501-Information-Space
- Website: https://www.iinkognit0.de/

## Author

Patrick R. Miller (Iinkognit0)

K501 / K501-AIONARC

ORCID: https://orcid.org/0009-0004-3275-9545

## Status

This repository is intended to preserve the implementation, validation evidence, historical evolution, and machine-readable metadata without collapsing them into a single semantic layer.
