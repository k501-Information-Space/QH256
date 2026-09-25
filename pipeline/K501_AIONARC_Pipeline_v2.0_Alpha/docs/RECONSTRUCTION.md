# Reconstruction — V2.0 Alpha

records.bin is a deterministic sequence of uint32_le(length) + Binary Object Record bytes.
history.bin is a deterministic sequence of uint32_le(length) + alpha state/history bytes.
manifest.json is a derived projection. Raw pathname bytes are emitted as lowercase hexadecimal path_hex values.

Reconstruction must verify every record, the object_id, H_record, QH256 state deserialization, and chain linkage from an all-zero previous-chain hash.
