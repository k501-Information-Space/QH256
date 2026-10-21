# Frame 001 — Root-Level Navigation Transition

- **Frame ID:** `K501-QH256-IS-FRAME-001`
- **Type:** `ROOT_ENTRYPOINT_TRANSITION`
- **Time anchor:** `1792577732` (2026-10-21T10:15:32Z; 2026-10-21T12:15:32+02:00)
- **Repository:** `k501-Information-Space/QH256`
- **Pre-transition main commit:** `a2635acb9caa6f512cfc0743901239fa9e7f9941`
- **Previous frame:** [Frame 000](FRAME_000_BOOTSTRAP.md), preserved unchanged

## Transition

The initial navigation structure was placed under `information-space/`. That made the GitHub repository landing page lead through an extra directory before the new navigation layer became visible.

This transition places the active navigation artifacts at the repository root: `Gateway.md`, `Gateway.json`, `Index.md`, `Index.json`, the `frames/`, `runs/`, and `specifications/` directories, the operator manual under the existing `docs/` directory, and root-level manifest/checksum files.

The repository landing page `README.md` now starts with the Gateway, Index, current frame, current structure contract, run schema, and integrity links. No click into a nested `information-space/` directory is required.

## Preservation and boundaries

- Frame 000 is preserved byte-for-byte as the initial bootstrap record.
- The v0.1 structure specification is preserved as the record of the initial nested layout.
- The v0.2 structure specification defines the root-level layout.
- The previous committed tree remains available in Git history; this transition changes current paths, not the QH256 algebra or historical validation artifacts.
- QH256 remains the state algebra; this navigation layer does not become an archive or semantic interpreter.

## Next transition

Append a new identified frame for any later structural transition. Do not overwrite Frame 000 or Frame 001.
