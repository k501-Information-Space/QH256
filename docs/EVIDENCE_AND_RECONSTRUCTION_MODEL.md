# QH256 Evidence and Reconstruction Model

## 1. Purpose

This document defines the conceptual evidence and reconstruction model used by the QH256 repository.

Its purpose is to establish stable terminology and explicit boundaries before machine-readable schemas and metadata are introduced.

This document is a repository architecture definition.

It is not itself a serialized data schema, validation protocol, or implementation specification.

## 2. Core Principle

QH256 state is derived from declared evidence.

Evidence and provenance remain external to the QH256 state representation.

The reconstruction process must be deterministic from its declared inputs.

The conceptual flow is:

~~~text
SOURCE / EVIDENCE
        ↓
FRAME
        ↓
EVENT ORDERING
        ↓
QH256 DELTA
        ↓
RECONSTRUCTED STATE
~~~

The layers remain independently traceable.

Derived state must not replace canonical evidence.

## 3. Evidence

Evidence is an externally supplied artifact, observation, record, publication, file, message, or other source material used by a reconstruction or validation process.

Evidence does not become canonical merely because it is referenced by a reconstruction.

Each evidence item should have an explicit source reference.

The minimum conceptual distinction is:

~~~text
evidence ≠ interpretation
evidence ≠ reconstructed state
evidence ≠ QH256 delta
~~~

Interpretation may be performed externally, but must not be silently incorporated into the canonical QH256 state.

## 4. Frame

A frame is a deterministic record describing one reconstruction-relevant state transition or evidence event.

A frame provides the boundary between external evidence and derived QH256 state.

The conceptual minimum frame identity is:

~~~text
frame_id
timestamp
source_ref
evidence
classification
event_order
~~~

A frame may contain additional fields when required by a defined reconstruction process.

A frame must remain independently identifiable and traceable.

## 5. Frame ID

`frame_id` is the stable identifier of a frame within its applicable frame sequence.

A frame identifier identifies the frame record.

It does not itself encode semantic meaning.

A frame ID must not be silently reused for a different frame.

If a frame is superseded or corrected, the replacement must remain distinguishable from the original historical frame.

## 6. Time and Timestamp Rules

Time is an external property of evidence and event ordering.

The reconstruction model distinguishes, where applicable:

~~~text
event_timestamp
ingest_timestamp
validation_timestamp
commit_timestamp
release_timestamp
publication_timestamp
~~~

These timestamps represent different events and must not be silently substituted for one another.

The primary temporal anchor for event ordering is `event_timestamp` when an authoritative source explicitly provides one.

If an authoritative event timestamp is unavailable, the reconstruction process must record the absence rather than silently replacing it with filesystem time, commit time, or publication time.

A time anchor must identify the available temporal representation explicitly.

Where applicable, this includes:

~~~text
unix_epoch
utc
timezone representation
~~~

## 7. Event Ordering

Event ordering is a reconstruction property.

A timestamp alone is not necessarily sufficient to establish a unique order.

When multiple events share the same timestamp, the reconstruction procedure must use an explicitly declared deterministic tie-break rule.

Possible ordering information may include:

~~~text
event_timestamp
source sequence
frame_id
ingest order
explicit predecessor
~~~

The selected ordering rule must be documented by the applicable reconstruction procedure.

No implicit ordering based solely on filesystem enumeration is permitted.

## 8. Source Reference

`source_ref` identifies the external source from which the evidence associated with a frame originates.

A source reference may identify, for example:

- a canonical file,
- a repository object,
- a publication,
- an external record,
- an eArc artifact,
- another explicitly declared evidence source.

The source reference identifies provenance.

It does not itself establish the truth, authority, or interpretation of the referenced material.

## 9. Evidence Classification

`classification` describes the declared type or role of evidence used by the reconstruction process.

Classification must not be confused with semantic truth.

A classification system must be explicitly defined by the applicable schema or reconstruction procedure.

Until such a classification vocabulary is formally established, classification values must not be invented or treated as canonical.

## 10. QH256 Specification Reference

A derived frame may identify the QH256 specification under which its state transition was calculated.

The conceptual field is:

~~~text
qh256_spec
~~~

For the current QH256 repository lineage, a value such as:

~~~text
"2.0"
~~~

identifies the applicable formal specification generation.

The specification reference identifies the rule set used for derivation.

It does not replace the specification artifact itself.

## 11. QH256 Delta

`qh256_delta` represents a derived transition calculated from declared evidence under the applicable QH256 specification.

The delta is not canonical source evidence.

It is a derived artifact.

The conceptual relationship is:

~~~text
declared evidence
        +
applicable QH256 specification
        ↓
deterministic derivation
        ↓
qh256_delta
~~~

A delta must remain traceable to its source frame and applicable specification.

## 12. Reconstructed State

`reconstructed_state` represents the deterministic QH256 state obtained by applying the declared sequence of QH256 transitions.

The conceptual relationship is:

~~~text
S₀
 ↓
Δ₁
 ↓
S₁
 ↓
Δ₂
 ↓
S₂
~~~

A reconstructed state is derived state.

It does not replace the evidence from which it was reconstructed.

A state must therefore remain reproducible from its declared predecessor state, ordered deltas, and applicable specification.

## 13. Derivation

A reconstruction or state derivation must declare its derivation mode.

The canonical conceptual value for deterministic reconstruction is:

~~~text
"deterministic"
~~~

Deterministic means that identical declared inputs, specification, ordering rules, and initial state produce the same resulting state.

A process must not be described as deterministic if hidden external inputs can alter the result.

## 14. Canonical Source

A reconstruction record may identify the canonical source from which its evidence lineage originates.

The conceptual field is:

~~~text
canonical_source
~~~

For K501-AIONARC historical reconstruction, a canonical source may be identified as:

~~~text
"eArc"
~~~

when the relevant evidence has actually been established as originating from the eArc historical state-space.

This field must not be used merely because eArc is conceptually relevant.

The actual provenance relationship must be established first.

## 15. Conceptual Frame Record

A conceptual frame may therefore have the following form:

~~~json
{
  "frame_id": "...",
  "timestamp": "...",
  "source_ref": "...",
  "evidence": "...",
  "classification": "...",
  "event_order": "...",
  "qh256_spec": "2.0",
  "qh256_delta": "...",
  "reconstructed_state": "...",
  "derivation": "deterministic",
  "canonical_source": "eArc"
}
~~~

This example defines terminology and relationships.

It is not yet the canonical machine-readable schema.

The exact serialization, required fields, data types, validation rules, and permitted vocabularies remain subject to a later formal schema definition.

## 16. No-Phantom Principle

A reconstruction must not create information that is absent from its declared evidence.

The No-Phantom principle is:

~~~text
NO SOURCE
    ↓
NO EVIDENCE
    ↓
NO DERIVED CLAIM
~~~

A missing source value must remain missing.

An unknown timestamp must not be replaced by an invented timestamp.

An absent event must not be manufactured to complete a sequence.

An inferred relationship must not be represented as observed evidence unless the inference is explicitly classified as such by the applicable procedure.

## 17. Temporal Consistency

A reconstruction must preserve the distinction between the time of an event and the time at which the event was observed, ingested, validated, committed, released, or published.

Temporal information must therefore remain attributable to its source.

A later observation of an earlier event does not change the event timestamp.

Likewise, a later Git commit does not become the event timestamp merely because the evidence was committed to the repository at that time.

## 18. Append-Only Reconstruction

Historical reconstruction must preserve prior frames and their relationships.

Corrections, additional evidence, or improved reconstruction procedures must be represented as new derived state or new records rather than by silently rewriting historical evidence.

The preferred model is:

~~~text
FRAME_0001
FRAME_0002
FRAME_0003
FRAME_0004
        ↓
new evidence / correction
        ↓
FRAME_0005
~~~

The historical frame sequence remains reconstructable.

## 19. Proof Boundary

A reconstructed state is evidence of a deterministic derivation only to the extent that the declared inputs, procedure, ordering, and specification are available for verification.

A reconstructed state does not by itself prove:

- that the source evidence is true,
- that the source is authoritative,
- that the reconstruction is complete,
- that the interpretation is correct,
- that the underlying historical record is complete.

Proof status must remain attached to the evidence and validation layer.

## 20. Canonical / Derived Boundary

The repository maintains the following distinction:

~~~text
CANONICAL
    source
    evidence
    established provenance
    formal specification

DERIVED
    frame ordering
    QH256 delta
    reconstructed state
    reports
    indexes
~~~

Derived artifacts may be regenerated.

Canonical artifacts must not be silently replaced by their derived representations.

## 21. Formalization Boundary

This document establishes terminology and architectural relationships required for the current Gate 3 work.

The following remain outside the present document's formal scope:

- final JSON Schema definitions,
- mandatory field requirements,
- canonical classification vocabulary,
- frame serialization versioning,
- cryptographic frame identifiers,
- formal event-ordering algorithms,
- complete eArc reconstruction protocol,
- automated provenance validation.

Those elements may be introduced in later controlled changes after their dependencies have been established.

## 22. Reconstruction Rule

The conceptual reconstruction rule is:

~~~text
QH256(t) = deterministic_reconstruction(
    canonical_evidence,
    ordered_frames,
    applicable_specification,
    initial_state
)
~~~

The resulting state is reproducible only when all inputs and ordering rules required by the reconstruction are declared.

The reconstruction process must therefore expose its dependencies rather than relying on hidden state.

## 23. Gate 3 Boundary

This document establishes the minimum stable conceptual vocabulary required for the current repository architecture:

~~~text
frame_id
timestamp
source_ref
evidence
classification
event_order
qh256_spec
qh256_delta
reconstructed_state
derivation
canonical_source
~~~

These terms are introduced now to prevent later semantic drift.

Their final machine-readable representation remains a subsequent controlled state change.
