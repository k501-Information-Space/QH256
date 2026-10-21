# QH256 Information Space — Navigation Root

Status: initial structural bootstrap, currently proposed on a candidate branch. Git refs and pull-request evidence—not file names—determine whether this transition is canonical in `main`.

## Read order

1. [Gateway.md](Gateway.md) / [Gateway.json](Gateway.json)
2. [Index.md](Index.md) / [Index.json](Index.json)
3. [Frame 000](frames/FRAME_000_BOOTSTRAP.md) / [machine record](frames/FRAME_000_BOOTSTRAP.json)
4. [Operator Manual](docs/OPERATOR_MANUAL.md)
5. [Structure Specification](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.1.md) / [machine specification](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.1.json)
6. [Run schema](runs/run.schema.json)
7. [Manifest](MANIFEST.json), [SHA-256 list](SHA256SUMS.txt), and [checksum sidecar](SHA256SUMS.txt.sha256)

QH256 stays the deterministic four-state algebra and 256-bit representation. This navigation layer references repository metadata, specification, validation, and external provenance; it does not turn QH256 into an archive or semantic interpreter.

Frames and run evidence are append-only. Derived indexes may be regenerated only against a declared source state and procedure. Unknown values remain OPEN/UNKNOWN.
