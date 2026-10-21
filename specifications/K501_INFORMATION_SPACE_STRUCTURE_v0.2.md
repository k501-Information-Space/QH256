# K501 Information Space Structure Specification v0.2

**Status:** Root-level navigation contract  
**Scope:** QH256 repository landing page and Information Space navigation  
**Time anchor:** `1792577732`

## Root-level components

- `README.md`: visible GitHub landing page and navigation summary.
- `Gateway.md` / `Gateway.json`: stable human- and machine-readable entrypoint.
- `Index.md` / `Index.json`: derived map of current paths and referenced repository artifacts.
- `frames/`: append-only structural declarations and transitions.
- `runs/run.schema.json`: contract for bounded execution/evidence records.
- `docs/OPERATOR_MANUAL.md`: controlled operating sequence.
- `specifications/`: versioned structure contracts; v0.1 records the initial nested layout, v0.2 defines this root-level layout.
- `LICENSE_SCOPE.md`: pointer to the existing root `LICENSE`.
- `MANIFEST.json`, `SHA256SUMS.txt`, and `SHA256SUMS.txt.sha256`: scoped file identity and integrity metadata.

## Invariants

1. The GitHub repository landing page presents the new navigation directly; no nested `information-space/` visit is required.
2. QH256 remains the deterministic four-state algebra and 256-bit state representation.
3. History, provenance, and execution evidence remain external to the QH256 aggregate state.
4. Frame 000 and the v0.1 contract remain unchanged historical records of the initial layout.
5. Frames and run evidence are append-only; earlier records are not overwritten.
6. The index is derived and does not replace source artifacts.
7. All active Gateway/Index paths resolve from the repository root.
8. Manifest and SHA-256 checksums are recomputed from the exact committed UTF-8 bytes.
9. A branch is not canonical `main` until integrated and the resulting ref is read back.

## Controlled transition

One bounded path transition was made from the initial `information-space/` layout to root-level navigation. The corresponding declaration is Frame 001. This transition changes repository organization and references only; it does not redefine QH256 or modify historical validation evidence.
