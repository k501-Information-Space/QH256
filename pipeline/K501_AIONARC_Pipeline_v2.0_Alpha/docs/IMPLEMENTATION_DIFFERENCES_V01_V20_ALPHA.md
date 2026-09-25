# V0.1 -> V2.0 Alpha Implementation Boundary

V0.1 is the semantic record-layer proof baseline. V2.0 Alpha is an integration implementation candidate.

Retained semantics:
- explicit root_id
- root_id participates in identity
- absolute host path excluded from identity
- object type domain 1..4
- content-independent object identity
- record hash excludes itself
- ingest-only validity markers excluded from the canonical record
- QH256 remains outside the object-record layer until mapping

Alpha representation changes:
- raw path bytes replace text-only proof representation;
- SHA-256 fields are 32 raw bytes instead of 64 hex characters;
- variable byte values carry explicit uint32_le lengths;
- nullable values use explicit 0x00/0x01 presence markers;
- signed mtime values keep their signed historical widths;
- binary object identity uses a domain-separated alpha preimage;
- manifest rendering is a hex projection.

The alpha identity rule is not a claim of digest compatibility with the v0.1 object_id value.
