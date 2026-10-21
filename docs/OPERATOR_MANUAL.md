# Operator Manual — Initial Structure

1. Read the Gateway and resolve targets through the Index.
2. Read the latest accepted Frame and its applicable specification before proposing an extension.
3. Bind each operation to a gate, run ID, time anchor, exact inputs, outputs, commands, result, and evidence.
4. Keep canonical source, derived index, run evidence, and temporary context separate.
5. Do not overwrite earlier frames or historical runs. Unknowns remain OPEN/UNKNOWN.
6. Review the exact candidate diff; validate machine-readable documents and SHA-256 checksums.
7. Use the repository's pull-request policy. After merge, read back the merge commit, tree, paths and checksums before recording PASS.

Safety: no reset, forced update, cleanup or destructive synchronization as a shortcut. Do not place credentials, private keys, or private conversation contents into public artifacts. A checksum or exit code alone is not a gate PASS.
