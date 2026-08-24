# QH256 Validation v2.0

C11 reference implementation and executable validation suite for the machine-testable parts of QH256 — K501 Formal Scientific Specification v2.0.

Core model: QH256 = 128 cells, 2 bits/cell, 256 bits; two 128-bit evidence planes T and F.

Canonical states: 00 UNKNOWN, 01 FALSE, 10 TRUE, 11 GUARD.

MERGE_K: component-wise OR. NOT: swap T/F. AND: (T_a&T_b, F_a|F_b). OR: (T_a|T_b, F_a&F_b).

Knowledge order: component-wise evidence inclusion. Truth order: T ascending and F descending. Designated states: TRUE and GUARD.

Canonical binary format (QH256 binary v1): bytes 0..7 T[0] little-endian, 8..15 T[1], 16..23 F[0], 24..31 F[1].

Tests cover structural invariants, all cell states/boundaries, exhaustive 4x4 core truth tables, orders, merge algebra, bit-plane mapping, exact serialization, deterministic round trips, 128-cell lifting, append-only monotonicity, replay/reconstruction, designated states, error paths and deterministic randomized property tests.

Build: make clean && make test
Full validation: ./run_validation.sh
Sanitizers: make asan

Scientific boundary: PASS validates the explicitly machine-testable definitions implemented here. It does not by itself establish historical facts, semantic truth, mathematical novelty, performance superiority, or the correctness of external canonical history.
