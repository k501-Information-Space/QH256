# QH256 v2.0 Reference Binding

The alpha does not copy or fork the QH256 core.

Expected external files:
- tests/validation/v2.0/qh256.h
- tests/validation/v2.0/qh256.c

The public interface required by the alpha includes:
- qh256_t
- qh256_unknown()
- qh256_set_cell()
- qh256_equal()
- qh256_serialize()
- qh256_deserialize()

The alpha checks QH256_BITS = 256, QH256_BYTES = 32, QH256_CELLS = 128 and the established t9 exact 32-byte vector.

The actual local repository remains the authoritative core source for K501 validation. This document does not pin a Git commit and therefore does not replace local provenance evidence.
