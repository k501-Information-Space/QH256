# V2.0 Alpha Status

Provenance basis:
- QH256 v2.0 validated core exists and was directly compile/runtime-bound in V02-2C.
- V0.1 Canonical Object Record is an IMPLEMENTED / PROOF PASS baseline.
- V0.1 object_id identity inputs: schema + root_id + relative_path + object_type.
- V0.1 record_hash excludes record_hash itself from the hash input.

Alpha adjustments:
1. raw path bytes are first-class record values;
2. SHA-256 digests are stored as 32 raw bytes;
3. variable byte fields use uint32_le length prefixes;
4. nullable size/content-digest values use 0x00/0x01 presence bytes;
5. signed mtime values preserve their historical signed widths;
6. the alpha identity projection is domain-separated and byte-native;
7. manifest rendering uses path_hex so invalid UTF-8 cannot be replaced.

These are alpha decisions, not canonical decisions.

## Time anchors

V02-2C PASS: Unix 1789673383 / 2026-09-17 19:29:43 UTC / 21:29:43 CEST.
Alpha construction frame: Unix 1789677716 / 2026-09-17 20:41:56 UTC / 22:41:56 CEST.
