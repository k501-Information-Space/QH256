# Repository Guide

## For humans

Start with `README.md`, then `docs/ARCHITECTURE.md`, `docs/VALIDATION_STATUS.md`, and `docs/HISTORY.md`.

## For machines

Read `metadata/qh256.repository.json` first. It defines namespace, project identity, state dimensions, validation generations, canonical links, and status declarations in a compact deterministic structure.

## For reviewers

Use the validation workspace under `tests/validation/` together with the corresponding release notes and checksums.

## For reproducibility

Do not use only the latest source tree. Use the exact release tag and the corresponding validation artifact.

## For future releases

1. Add a new versioned artifact directory.
2. Add a release note and provenance statement.
3. Generate SHA-256 checksums for every uploaded archive.
4. Tag the release.
5. Publish the GitHub release.
6. Preserve the previous release unchanged.
7. Update the root metadata only by appending the new release entry and current status.
