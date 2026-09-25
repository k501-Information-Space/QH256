# Terminal Start — V2.0 Alpha

From the QH256 repository root, extract this alpha under pipeline/ and enter its directory.

Then run:

./tests/integration_v02_2c.sh

./scripts/run_alpha_validation.sh

The first command replays the direct-core-binding proof. The second command runs the complete alpha harness, including deterministic ingest, binary record verification, raw invalid-UTF8 path handling, mutation locality, tamper rejection, history linkage and ASan/UBSan.

The alpha does not automatically git add, commit or push anything.
