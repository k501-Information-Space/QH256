# K501 Information Space Structure Specification v0.1

**Status:** Initial structural contract  
**Scope:** QH256 repository navigation layer only  
**Time anchor:** `1792574554`

## Roles

- Gateway: stable human/machine entrypoint.
- Index: navigable artifact map, explicitly derived.
- Frames: append-only declarations of structural state and transitions.
- Runs: bounded execution/evidence records conforming to the versioned schema.
- Operator manual: safe, gate-based operating sequence.
- Manifest and SHA-256 list: byte identities for the declared bootstrap file set.
- License reference: points to the existing root `LICENSE`; it creates no additional grant.

## Invariants

1. QH256 remains the deterministic four-state algebra and 256-bit representation.
2. History and provenance remain external to the QH256 algebra.
3. Existing frames and runs are never rewritten in place.
4. Index is derived and does not replace source artifacts.
5. Every declared path exists or remains explicitly OPEN; no phantom references.
6. A candidate branch is not canonical `main` until merge and post-merge verification.
7. SHA-256 identifies bytes, not authorship or semantic correctness.

Extension: make one bounded change, bind the exact paths, validate JSON and checksum data, review the diff, and record the verified result as a new frame.
