# QH256 v2.0 — Validation Matrix

The matrix maps specification clauses to executable validation classes.

| Spec clause | Machine-testable content | Validation | Status |
|---|---|---|---|
| 2 | Q = {00,01,10,11}; 128 cells; 2^256 cardinality | T1-T3, T20, T23 | PASS |
| 3-4 | F2^256 representation; (t,f) evidence model | T1-T3, T8, T18-T20, T23 | PASS |
| 5-6 | GUARD = (1,1), append-only guard behavior | T2, T4, T14 | PASS |
| 8-9 | Knowledge order and state interpretation | T6, T14, T21 | PASS |
| 10 | MERGE_K table and componentwise OR | T4, T7, T13, T21 | PASS |
| 11-12 | Monotonicity and transitions | T7, T14, T21 | PASS |
| 13 | Truth Order | T6 | PASS |
| 14 | NOT swaps planes; involution | T5, T11, T19, T20 | PASS |
| 15 | AND | T5, T12, T18 | PASS |
| 16 | OR | T5, T12, T18 | PASS |
| 18 | Designated states TRUE/GUARD | T2, T17 | PASS |
| 22-27 | Algebraic structure; idempotence, commutativity, associativity, determinism | T4, T7, T10, T13, T16, T21 | PASS |
| 28-29 | Two 128-bit evidence planes; 32-byte representation | T1, T8, T23 | PASS |
| 32-33 | Semantic endianness separation; canonical little-endian serialization | T9, T10, T23 | PASS |
| 34 | UNKNOWN_BY_DEFAULT | T1, T3, T14, T15 | PASS |
| 35 | Evidence accumulation by OR; proof-before-state boundary | T13, T14, T21 | PASS for machine-testable algebraic part |
| 37 | Delta state | T14, T15, T16 | PASS |
| 38 | Time is external to QH256 state | Not encoded in qh256_t; documented boundary | PASS as representation constraint |
| 39 | Replay(H) reconstructs aggregate | T15, T16 | PASS |
| 48 | decode(encode(x)) identity | T20, T23 | PASS |
| 49 | I1-I13 invariants | T1-T7, T11, T13, T14, T19, T21, T23 | PASS |
| 50-51 | Exhaustive cell algebra; vector-level property checks | T4-T7, T12-T13, T18, T21 | PASS |
| 54-58 | Frozen v2.0 state definition | Cross-covered by all rows above | PASS for machine-testable definitions |

## Not directly machine-validatable by this C core

The following specification boundaries are not software-state properties and therefore are not claimed as proven by the executable suite:

- historical provenance and bibliography;
- semantic correctness or truth of external claims;
- source trustworthiness / evidence quality;
- reconstruction of historical ordering from QH256 alone;
- mathematical novelty;
- algorithmic or hardware superiority;
- practical superiority over Belnap/FDE or other systems;
- any primitive implication operator, because v2.0 explicitly does not define one.

These are retained as scientific-status boundaries rather than silently converted into PASS claims.
