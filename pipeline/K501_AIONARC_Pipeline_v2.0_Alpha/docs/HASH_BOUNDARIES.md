# Hash Boundaries — V2.0 Alpha

H_content = SHA-256(file content bytes), when content is observable.
H_object = object_id = SHA-256(alpha byte-native identity preimage).
H_record = SHA-256(canonical Binary Object Record bytes excluding record_hash).
H_chain = SHA-256("K501-CHAIN-2A\\0" || previous_chain_hash || current_record_bytes).

Hashes establish deterministic integrity/linkage. They do not establish authorship or semantic truth.
