# External QH256 v2.0 Check — 2026-09-17

This is a research/compile check against the public QH256 repository main branch at build time. The files were fetched through the public raw repository view and copied only into the local validation workspace, not into this alpha package.

Reference paths:
- tests/validation/v2.0/qh256.h
- tests/validation/v2.0/qh256.c

Retrieved file SHA-256:
- qh256.h: a198b04ee4b603d6a936f1f0e22835db8767b96bdf302cc23181a3434e25ced4
- qh256.c: 8b34583644146571b9bff9c1aade08d0d56ec373d4f9f8aaadf264f2b00e59b5

This check confirms that the alpha compiles against the currently retrieved public API and implementation. It does not pin a Git commit, and therefore it does not replace the user's local QH256 repository as the authoritative provenance source.
