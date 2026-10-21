# Gateway — QH256 Repository / K501 Information Space

**Current structure:** [v0.3](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.3.md) · [JSON](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.3.json)  
**Current reconciliation frame:** [Frame 002](frames/FRAME_002_RECONCILIATION.md) · [JSON](frames/FRAME_002_RECONCILIATION.json)

## Active entrypoints

- [Repository landing page](README.md)
- [Complete path Index](Index.md) · [machine Index](Index.json)
- [Frame 002 — reconciliation](frames/FRAME_002_RECONCILIATION.md) · [JSON](frames/FRAME_002_RECONCILIATION.json)
- [Frame 001 — root transition, historical](frames/FRAME_001_ROOT_ENTRYPOINT.md) · [JSON](frames/FRAME_001_ROOT_ENTRYPOINT.json)
- [Frame 000 — initial bootstrap, historical](frames/FRAME_000_BOOTSTRAP.md) · [JSON](frames/FRAME_000_BOOTSTRAP.json)
- [Operator manual](docs/OPERATOR_MANUAL.md) · [run schema](runs/run.schema.json)
- [License scope](LICENSE_SCOPE.md) · [authoritative license](LICENSE)
- [Scoped manifest](MANIFEST.json) · [checksum list](SHA256SUMS.txt) · [sidecar](SHA256SUMS.txt.sha256)

## Boundary

The root exposes two classified layers. The **Information Space control surface** contains entrypoints, Index, frames, run schema, specifications, operator manual and scoped integrity files. The **existing QH256 payload** contains project documentation, metadata, archived alpha material, pipeline, references, releases, scripts and validation material. Existing payload paths are retained in place, not copied into the navigation layer.

`docs/` is shared: `docs/OPERATOR_MANUAL.md` is control surface; other existing docs remain QH256 project documentation. Index 0.3 classifies every path, including directories.

## Historical path resolution

Frame 000 and specification v0.1 preserve the initial nested layout. Their `information-space/...` values are historical, not active destinations. Use the [crosswalk in v0.3](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.3.md#historical-path-crosswalk). The nested tree is not recreated and historical records are not rewritten.

## Integrity boundary

The manifest/checksum set covers declared control-surface files and selected referenced records only. The complete Index is a path inventory, not a repository-wide content hash or semantic proof. QH256 remains the four-state algebra and 256-bit state representation; navigation does not redefine it.
