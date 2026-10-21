# Frame 002 — Repository State Reconciliation

- **Frame ID:** `K501-QH256-IS-FRAME-002`
- **Type:** `REPOSITORY_STATE_RECONCILIATION`
- **Time anchor:** `1792578946` (2026-10-21T10:35:46Z; 2026-10-21T12:35:46+02:00)
- **Input main commit:** `5cd7e4a6d0a30fcdab5bfee5978f5dc9d58a5d09`
- **Previous frame:** [Frame 001](FRAME_001_ROOT_ENTRYPOINT.md)

## Observation

The root-entrypoint transition made navigation visible but left Index 0.2 scoped to a subset of the repository. The source tree contained 146 entries, including directory nodes. The existing QH256 payload and Information Space control surface were not explicitly separated in a complete inventory.

## Reconciliation

The repository has two declared layers: (1) Information Space control surface: README, Gateway, complete Index, Frames, run schema, versioned structure specifications, operator manual, license-scope pointer and scoped integrity files; (2) existing QH256 payload: project documentation, metadata, archived alpha material, versioned pipeline, references, releases, scripts and validation sources/results.

`docs/` is a shared container. `docs/OPERATOR_MANUAL.md` is control surface; other existing files under `docs/` remain QH256 project documentation. Index 0.3 classifies every path separately, including directories.

## Historical path resolution

Frame 000 and specification v0.1 remain immutable records of the initial nested layout. Their `information-space/...` values are historical strings, not active destinations. Gateway and specification v0.3 provide the path crosswalk. The old nested tree is not recreated, and historical records are not rewritten.

## Preservation boundary

- No existing QH256 implementation, test, release, reference, metadata or archive path is removed by this reconciliation.
- Frame 000, Frame 001, and specifications v0.1/v0.2 remain unchanged.
- The complete Index covers 146 input-tree paths plus four new Frame 002 paths: 150 expected entries.
- The scoped manifest hashes the declared control surface and selected referenced records; it is not a full-repository content hash.
- Current paths must resolve. Historical paths are explicitly historical and covered by the crosswalk.
- QH256 remains the four-state algebra and 256-bit state representation; navigation does not redefine or copy underlying artifacts.

## Status boundary

This frame binds the input state and declared reconciliation. Canonical-main status is established only by reading back the resulting branch and commit after integration.
