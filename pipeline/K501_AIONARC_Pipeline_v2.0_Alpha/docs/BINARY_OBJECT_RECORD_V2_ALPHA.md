# Binary Object Record v2.0 Alpha

Status: ALPHA / NOT CANONICAL

Field order:
1 schema
2 object_id
3 root_id
4 relative_path_bytes
5 object_type
6 size_bytes
7 content_sha256
8 mtime_sec
9 mtime_nsec
10 mode
11 readable
12 record_hash

Integer encoding: little-endian. uint32 width 4, uint64 width 8, int64 width 8 two's complement, int32 width 4 two's complement.

Variable byte values: uint32_le(length) followed by exactly length bytes, no NUL terminator.

SHA-256 values: exactly 32 raw digest bytes.

Object type: 0x01 REGULAR_FILE, 0x02 DIRECTORY, 0x03 SYMLINK, 0x04 OTHER. Other values invalid.

Boolean/readable: 0x00 false, 0x01 true. Other values invalid.

Nullable fields: one-byte presence. 0x00 ABSENT/NULL, 0x01 PRESENT followed by payload.
size_bytes payload = uint64_le.
content_sha256 payload = 32 bytes.

record_hash is appended as the final 32 bytes and is SHA-256 over all preceding serialized record bytes. It is not included in its own input.

Alpha object_id preimage:
ASCII bytes K501-OID-V2A\0
+ schema (length+bytes)
+ root_id (length+bytes)
+ relative_path_bytes (length+raw bytes)
+ object_type (1 byte)

This changes representation from the v0.1 JSON identity projection for v2 alpha purposes and MUST NOT be described as v0.1 digest compatibility.
