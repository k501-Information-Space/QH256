# QH256 Repository Architecture

## 1. Purpose

This repository is organized around traceability, reproducibility, and explicit separation of canonical evidence from derived state.

QH256 is a deterministic four-state information algebra and 256-bit state representation developed within the K501-AIONARC Information Space.

The repository must preserve the distinction between:

- canonical source material,
- historical evidence,
- formal specification,
- implementation,
- validation evidence,
- derived QH256 transitions,
- reconstructed state.

No directory or artifact is considered functional merely because its name appears in the repository topology.

## 2. Repository Topology

QH256/
├── README.md
├── LICENSE
├── include/                    # reserved: public interface location
├── src/                        # reserved: reference implementation location
├── spec/                       # reserved: formal specification location
├── tests/
│   └── validation/
│       ├── v0.1/              # historical validation workspace
│       └── v2.0/              # expanded validation workspace
├── docs/
│   ├── ARCHITECTURE.md
│   ├── AUTHORSHIP.md
│   ├── EVIDENCE_AND_RECONSTRUCTION_MODEL.md
│   ├── VALIDATION_STATUS.md
│   ├── PROOF_BEFORE_STATE.md
│   ├── HISTORY.md
│   ├── REPOSITORY_GUIDE.md
│   └── REPOSITORY_RESOLUTION_NOTES.md
├── history/                    # reserved: historical notices / lineage
├── references/                 # reference index and provenance notes
├── metadata/                   # machine-readable repository metadata
├── releases/                   # release notes and release evidence
├── scripts/                    # deterministic packaging / verification tools
└── obsolete/
    └── alpha/                  # preserved historical Alpha artifacts

## 3. Reserved Topology

The directories include/, src/, spec/, and history/ are currently reserved topology.

At the current repository state they contain no active files.

Their presence is not evidence of an implementation, formal specification, or historical record.

No file shall be added merely to satisfy the directory model.

A future artifact may occupy a reserved location only when its provenance, purpose, and relation to the applicable QH256 specification are established.

## 4. Canonicality Rules

Canonical material is source material whose identity and provenance are explicitly established.

Canonical material is not silently rewritten, replaced, or semantically normalized into a different state.

Derived artifacts may be regenerated from canonical inputs but do not replace those inputs.

A derived result must remain traceable to:

1. its canonical source,
2. the applicable specification or deterministic procedure,
3. the reconstruction or derivation step that produced it.

## 5. Historical Model

Historical artifacts remain identifiable as historical artifacts.

The obsolete/alpha/ tree preserves the former Alpha implementation and documentation lineage. Its contents are not part of the current v2.0 implementation claim.

Historical presence does not imply current validity.

Likewise, an empty history/ directory does not imply that historical evidence has been lost; it means that no active history artifact is currently assigned to that topology location.

## 6. State and Evidence Separation

The repository distinguishes the following layers:

CANONICAL SOURCE / EVIDENCE
          ↓
FRAME / EVENT ORDERING
          ↓
QH256 DELTA
          ↓
RECONSTRUCTED QH256 STATE

STATE is a QH256 aggregate representation.

HISTORY is an ordered external evidence source from which state may be reconstructed.

EVIDENCE is the externally supplied material or reference used by a reconstruction or validation process.

QH256 DELTA is a derived transition calculated under an applicable QH256 specification.

RECONSTRUCTED STATE is a deterministic result produced by replaying declared evidence and transitions.

These layers must not be collapsed into one another.

## 7. Reconstruction Boundary

The reconstruction boundary is external to the QH256 algebra itself.

QH256 does not contain its own provenance, source identity, event time, historical authority, or semantic interpretation.

A reconstruction process may use those external properties to establish an ordered sequence of evidence and derive QH256 transitions.

The reconstruction process must remain deterministic and reproducible from its declared inputs.

The conceptual reconstruction rule is:

QH256(t) = deterministic_reconstruction(H(t))

where H(t) denotes the declared evidence history available up to the reconstruction boundary t.

## 8. QH256 Semantic Boundary

QH256 provides a deterministic four-state information algebra and a 256-bit state representation.

It does not by itself provide:

- an archive,
- a semantic interpreter,
- a truth authority,
- a provenance system,
- a probabilistic model,
- a proof authority,
- cryptographic security merely because its representation contains 256 bits.

Meaning, authority, provenance, and proof status remain external properties.

## 9. Evidence and Time Boundary

Time belongs to the evidence and event layer, not intrinsically to the QH256 state.

Where applicable, temporal records must distinguish at least:

- event_timestamp,
- ingest_timestamp,
- validation_timestamp,
- commit_timestamp,
- release_timestamp,
- publication_timestamp.

These timestamps must not be silently substituted for one another.

An event timestamp must not be inferred from filesystem modification time, Git commit time, release time, or publication time unless the source explicitly defines that timestamp as the event time.

## 10. Proof Boundary

The repository follows the principle:

Definition
    ↓
Implementation
    ↓
Test
    ↓
Validation Evidence
    ↓
Released State

A claim about implementation, validation, provenance, or reconstruction must be supported by the corresponding evidence.

Passing validation establishes only the tested machine-checkable scope.

It does not by itself establish universal correctness, semantic truth, completeness, superiority, or external authority.

## 11. Future Extension Rule

Future QH256 functionality must be introduced only after its relation to the existing specification, implementation, validation evidence, and repository topology has been established.

New state, metadata, schemas, interfaces, or reconstruction mechanisms must not be introduced merely because they are convenient.

Extensions must preserve:

- append-only provenance,
- deterministic reconstruction,
- canonical immutability,
- explicit derived-state boundaries,
- temporal consistency,
- traceability.
