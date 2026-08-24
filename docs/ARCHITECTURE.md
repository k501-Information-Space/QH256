# QH256 Repository Architecture

## 1. Purpose

This repository is organized around traceability. Source, specification, validation, history, metadata, and release evidence are separated so that each claim can be reconstructed from a concrete artifact.

## 2. Directory Model

```text
QH256/
├── README.md
├── LICENSE
├── include/                    # public C interface
├── src/                        # reference implementation
├── spec/                       # formal QH256 specification
├── tests/
│   └── validation/
│       ├── v0.1/              # historical validation workspace
│       └── v2.0/              # expanded validation workspace
├── docs/
│   ├── ARCHITECTURE.md
│   ├── VALIDATION_STATUS.md
│   ├── PROOF_BEFORE_STATE.md
│   ├── HISTORY.md
│   ├── AUTHORSHIP.md
│   └── REPOSITORY_GUIDE.md
├── history/                    # immutable historical notices / lineage
├── references/                 # reference index and provenance notes
├── metadata/                   # machine-readable repository metadata
├── releases/                   # release notes and checksums manifests
└── scripts/                    # deterministic packaging / verification tools
```

## 3. Canonicality Rules

The canonical source is the version-controlled repository content and its tagged releases.

External publications are references, not substitutes for repository state.

Validation workspaces are historical artifacts. Their contents must not be merged destructively into a newer validation version.

Derived reports must identify their source version and time anchor.

## 4. History Model

The repository should preserve version transitions rather than rewriting them:

`QH256 v0.1 alpha`

→ `validation v0.1`

→ `formal specification v2.0`

→ `validation v2.0`

Future releases must append new evidence rather than silently modifying the meaning of previous release artifacts.

## 5. State / History / Evidence Separation

`STATE` is the 32-byte QH256 aggregate.

`HISTORY` is the external append-only evidence source.

`EVIDENCE` is the validation record showing which properties were checked.

This separation is a repository invariant.
