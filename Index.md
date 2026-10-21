# Index — QH256 Repository / K501 Information Space

**Index ID:** `K501-QH256-INDEX-0.3` · **Classification:** DERIVED · **Completeness:** complete path inventory  
**Basis:** `5cd7e4a6d0a30fcdab5bfee5978f5dc9d58a5d09` (146 existing paths) plus four Frame 002 paths = **150 expected entries**. Directory nodes are included. This is not a repository-wide content hash.

## Layer rules

- **Information Space control surface:** root entrypoints, Index, Frames, run schema, specifications, operator manual, license-scope pointer and scoped integrity files.
- **Existing QH256 payload:** project documentation, metadata, archived alpha artifacts, pipeline, references, releases, scripts and tests/validation, plus root `.gitignore` and `LICENSE`.
- **Shared container:** `docs/`. Its `OPERATOR_MANUAL.md` belongs to the control surface; remaining existing docs belong to the QH256 payload.
- Historical Frame 000 and v0.1/v0.2 specifications are preserved records. Their initial nested-layout strings are historical, not active paths.

## Complete path inventory

| Path | Kind | Role | Classification |
|---|---|---|---|
| `.gitignore` | blob | Existing repository configuration. | QH256_REPOSITORY_BASE |
| `Gateway.json` | blob | Machine-readable active gateway. | ROOT_ENTRYPOINT |
| `Gateway.md` | blob | Human-readable active gateway. | ROOT_ENTRYPOINT |
| `Index.json` | blob | Complete machine-readable path inventory; derived. | DERIVED_COMPLETE_INDEX |
| `Index.md` | blob | Complete human-readable path inventory; derived. | DERIVED_COMPLETE_INDEX |
| `LICENSE` | blob | Existing repository license text. | QH256_REPOSITORY_BASE |
| `LICENSE_SCOPE.md` | blob | Human-readable repository artifact or documentation. | INFORMATION_SPACE_CONTROL_SURFACE |
| `MANIFEST.json` | blob | Machine-readable repository artifact or record. | INFORMATION_SPACE_CONTROL_SURFACE |
| `README.md` | blob | Repository landing page with control-surface/payload boundary. | ROOT_ENTRYPOINT |
| `SHA256SUMS.txt` | blob | Existing repository artifact retained at its recorded path. | INFORMATION_SPACE_CONTROL_SURFACE |
| `SHA256SUMS.txt.sha256` | blob | Existing repository artifact retained at its recorded path. | INFORMATION_SPACE_CONTROL_SURFACE |
| `docs` | tree | Directory container; child paths classified independently. | SHARED_CONTAINER |
| `docs/ARCHITECTURE.md` | blob | Human-readable repository artifact or documentation. | QH256_PROJECT_DOCUMENTATION |
| `docs/AUTHORSHIP.md` | blob | Human-readable repository artifact or documentation. | QH256_PROJECT_DOCUMENTATION |
| `docs/EVIDENCE_AND_RECONSTRUCTION_MODEL.md` | blob | Human-readable repository artifact or documentation. | QH256_PROJECT_DOCUMENTATION |
| `docs/HISTORY.md` | blob | Human-readable repository artifact or documentation. | QH256_PROJECT_DOCUMENTATION |
| `docs/OPERATOR_MANUAL.md` | blob | Gate-based Information Space operating instructions. | INFORMATION_SPACE_CONTROL_SURFACE |
| `docs/PROOF_BEFORE_STATE.md` | blob | Human-readable repository artifact or documentation. | QH256_PROJECT_DOCUMENTATION |
| `docs/REPOSITORY_GUIDE.md` | blob | Human-readable repository artifact or documentation. | QH256_PROJECT_DOCUMENTATION |
| `docs/REPOSITORY_RESOLUTION_NOTES.md` | blob | Human-readable repository artifact or documentation. | QH256_PROJECT_DOCUMENTATION |
| `docs/VALIDATION_STATUS.md` | blob | Human-readable repository artifact or documentation. | QH256_PROJECT_DOCUMENTATION |
| `frames` | tree | Directory container; child paths classified independently. | INFORMATION_SPACE_DIRECTORY |
| `frames/FRAME_000_BOOTSTRAP.json` | blob | Machine-readable repository artifact or record. | HISTORICAL_BOOTSTRAP_RECORD |
| `frames/FRAME_000_BOOTSTRAP.md` | blob | Human-readable repository artifact or documentation. | HISTORICAL_BOOTSTRAP_RECORD |
| `frames/FRAME_001_ROOT_ENTRYPOINT.json` | blob | Machine-readable repository artifact or record. | HISTORICAL_TRANSITION_RECORD |
| `frames/FRAME_001_ROOT_ENTRYPOINT.md` | blob | Human-readable repository artifact or documentation. | HISTORICAL_TRANSITION_RECORD |
| `frames/FRAME_002_RECONCILIATION.json` | blob | Machine-readable repository artifact or record. | CURRENT_RECONCILIATION_RECORD |
| `frames/FRAME_002_RECONCILIATION.md` | blob | Human-readable repository artifact or documentation. | CURRENT_RECONCILIATION_RECORD |
| `metadata` | tree | Directory container; child paths classified independently. | QH256_REPOSITORY_METADATA |
| `metadata/qh256.repository.json` | blob | Machine-readable repository artifact or record. | QH256_REPOSITORY_METADATA |
| `metadata/release-manifest.template.json` | blob | Machine-readable repository artifact or record. | QH256_REPOSITORY_METADATA |
| `obsolete` | tree | Directory container; child paths classified independently. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha` | tree | Directory container; child paths classified independently. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/QH256Engine.hpp` | blob | Source/header in existing QH256 payload. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/QH256_BREAKTHROUGH.md` | blob | Human-readable repository artifact or documentation. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/QH256_EXECUTIVE_SUMMARY.md` | blob | Human-readable repository artifact or documentation. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/QH256_GLOSSARY.md` | blob | Human-readable repository artifact or documentation. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/QH256_IMPLEMENTATION_GUIDE.md` | blob | Human-readable repository artifact or documentation. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/QH256_formal_theory.md` | blob | Human-readable repository artifact or documentation. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/RELEASE_PROCEDURE.md` | blob | Human-readable repository artifact or documentation. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/test.txt` | blob | Existing repository artifact retained at its recorded path. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/test_qh256` | blob | Existing repository artifact retained at its recorded path. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/test_qh256.cpp` | blob | Existing repository artifact retained at its recorded path. | QH256_HISTORICAL_ARCHIVE |
| `obsolete/alpha/verify_v6.sh` | blob | Repository or validation script. | QH256_HISTORICAL_ARCHIVE |
| `pipeline` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/README.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/VERSION` | blob | Existing repository artifact retained at its recorded path. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/ALPHA_STATUS.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/BINARY_OBJECT_RECORD_V2_ALPHA.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/EXTERNAL_QH256_CHECK_2026-09-17.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/GATE_MAP.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/HASH_BOUNDARIES.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/IMPLEMENTATION_DIFFERENCES_V01_V20_ALPHA.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/QH256_ALPHA_MAPPING.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/QH256_REFERENCE_BINDING.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/RECONSTRUCTION.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/TERMINAL_START.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/docs/VALIDATION_PLAN.md` | blob | Human-readable repository artifact or documentation. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/include` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/include/k501_aionarc` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/include/k501_aionarc/bytes.h` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/include/k501_aionarc/history.h` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/include/k501_aionarc/ingest.h` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/include/k501_aionarc/object_record.h` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/include/k501_aionarc/qh256_mapping.h` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/include/k501_aionarc/sha256.h` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/build.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/build_stub.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/build_verify.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/freeze_v2a01.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/make_manifest.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/public_scope_audit_v2a02.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/record_v2a02_scope.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/run_alpha_validation.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/run_alpha_validation_stub.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/run_asan.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/run_determinism.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/run_fixture.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/run_history_negative.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/run_mutation_proof.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/run_negative_validation.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/scripts/stage_public_v2a05.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/common` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/common/bytes.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/common/sha256.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/ingest` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/ingest/ingest.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/object_record` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/object_record/object_record.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/pipeline` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/pipeline/main.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/pipeline/verify.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/qh256_mapping` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/qh256_mapping/mapping.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/state` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/src/state/history.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests/integration_v02_2c.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests/integration_v02_2c.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests/run_tests.sh` | blob | Repository or validation script. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests/stub_qh256` | tree | Directory container; child paths classified independently. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests/stub_qh256/qh256.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests/stub_qh256/qh256.h` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests/test_known_vectors.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests/test_negative_record.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/tests/test_record_vectors.c` | blob | Source/header in existing QH256 payload. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/v2.0_ALPHA_FILE_MANIFEST.sha256` | blob | Existing repository artifact retained at its recorded path. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/v2.0_ALPHA_MODULE_MANIFEST.json` | blob | Machine-readable repository artifact or record. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `pipeline/K501_AIONARC_Pipeline_v2.0_Alpha/v2.0_ALPHA_MODULE_MANIFEST.json.sha256` | blob | Existing repository artifact retained at its recorded path. | QH256_VERSIONED_IMPLEMENTATION_PAYLOAD |
| `references` | tree | Directory container; child paths classified independently. | QH256_REFERENCE_PAYLOAD |
| `references/REFERENCES.md` | blob | Human-readable repository artifact or documentation. | QH256_REFERENCE_PAYLOAD |
| `releases` | tree | Directory container; child paths classified independently. | QH256_RELEASE_RECORD |
| `releases/RELEASE_QH256_Validation_v0.1.0.md` | blob | Human-readable repository artifact or documentation. | QH256_RELEASE_RECORD |
| `releases/RELEASE_QH256_Validation_v2.0.0.md` | blob | Human-readable repository artifact or documentation. | QH256_RELEASE_RECORD |
| `runs` | tree | Directory container; child paths classified independently. | INFORMATION_SPACE_DIRECTORY |
| `runs/run.schema.json` | blob | Machine-readable repository artifact or record. | INFORMATION_SPACE_RUN_SCHEMA |
| `scripts` | tree | Directory container; child paths classified independently. | QH256_REPOSITORY_SCRIPT |
| `scripts/prepare_release.sh` | blob | Repository or validation script. | QH256_REPOSITORY_SCRIPT |
| `scripts/verify_repo.sh` | blob | Repository or validation script. | QH256_REPOSITORY_SCRIPT |
| `specifications` | tree | Directory container; child paths classified independently. | INFORMATION_SPACE_DIRECTORY |
| `specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.1.json` | blob | Machine-readable repository artifact or record. | HISTORICAL_STRUCTURE_SPECIFICATION_V0_1 |
| `specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.1.md` | blob | Human-readable repository artifact or documentation. | HISTORICAL_STRUCTURE_SPECIFICATION_V0_1 |
| `specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.2.json` | blob | Machine-readable repository artifact or record. | HISTORICAL_TRANSITION_SPECIFICATION_V0_2 |
| `specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.2.md` | blob | Human-readable repository artifact or documentation. | HISTORICAL_TRANSITION_SPECIFICATION_V0_2 |
| `specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.3.json` | blob | Machine-readable repository artifact or record. | CURRENT_STRUCTURE_SPECIFICATION_V0_3 |
| `specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.3.md` | blob | Human-readable repository artifact or documentation. | CURRENT_STRUCTURE_SPECIFICATION_V0_3 |
| `tests` | tree | Directory container; child paths classified independently. | QH256_VALIDATION_PAYLOAD |
| `tests/validation` | tree | Directory container; child paths classified independently. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v0.1` | tree | Directory container; child paths classified independently. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v0.1/Makefile` | blob | Build and validation instructions. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v0.1/README.md` | blob | Human-readable repository artifact or documentation. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v0.1/TIME_ANCHOR.txt` | blob | Existing repository artifact retained at its recorded path. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v0.1/qh256.c` | blob | Source/header in existing QH256 payload. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v0.1/qh256.h` | blob | Source/header in existing QH256 payload. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v0.1/run_validation.sh` | blob | Repository or validation script. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v0.1/test_qh256_validation.c` | blob | Source/header in existing QH256 payload. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0` | tree | Directory container; child paths classified independently. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0/Makefile` | blob | Build and validation instructions. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0/README.md` | blob | Human-readable repository artifact or documentation. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0/TIME_ANCHOR.txt` | blob | Existing repository artifact retained at its recorded path. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0/VALIDATION_MATRIX.md` | blob | Human-readable repository artifact or documentation. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0/VALIDATION_RESULT.txt` | blob | Existing repository artifact retained at its recorded path. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0/qh256.c` | blob | Source/header in existing QH256 payload. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0/qh256.h` | blob | Source/header in existing QH256 payload. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0/run_validation.sh` | blob | Repository or validation script. | QH256_VALIDATION_PAYLOAD |
| `tests/validation/v2.0/test_qh256_validation.c` | blob | Source/header in existing QH256 payload. | QH256_VALIDATION_PAYLOAD |

## Historical path crosswalk

| Historical path | Current path / resolution |
|---|---|
| `information-space/Gateway.md` | `Gateway.md` |
| `information-space/Gateway.json` | `Gateway.json` |
| `information-space/Index.md` | `Index.md` |
| `information-space/Index.json` | `Index.json` |
| `information-space/frames/` | `frames/` |
| `information-space/runs/run.schema.json` | `runs/run.schema.json` |
| `information-space/docs/OPERATOR_MANUAL.md` | `docs/OPERATOR_MANUAL.md` |
| `information-space/LICENSE.md` | `LICENSE_SCOPE.md (scope pointer); LICENSE remains authoritative` |
| `information-space/MANIFEST.json` | `MANIFEST.json` |
| `information-space/SHA256SUMS.txt` | `SHA256SUMS.txt` |

Active entrypoints: [Gateway](Gateway.md) · [structure v0.3](specifications/K501_INFORMATION_SPACE_STRUCTURE_v0.3.md) · [Frame 002](frames/FRAME_002_RECONCILIATION.md).
