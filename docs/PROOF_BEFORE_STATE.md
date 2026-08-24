# Proof Before State

## Canonical rule

A repository state should not be presented as established merely because source code exists.

The preferred progression is:

```text
DEFINITION
  ↓
IMPLEMENTATION
  ↓
TEST
  ↓
VALIDATION EVIDENCE
  ↓
RELEASED STATE
```

## Evidence classes

### Mathematical

Properties derivable directly from the formal definitions, such as the cardinality `2^256` and algebraic properties of component-wise OR.

### Implementation

Observed behavior of a concrete reference implementation under documented compilation and execution conditions.

### Reproducibility

A second execution path or independent reconstruction that produces the same result.

### Scientific

Comparative or empirical evidence establishing practical performance, novelty, or superiority. These claims remain open unless experimentally demonstrated.

## Prohibition

Do not convert a successful test run into a broader scientific claim than the test actually supports.

The current v2.0 status therefore remains:

`VALIDATED FOR THE TESTED MACHINE-CHECKABLE SCOPE`
