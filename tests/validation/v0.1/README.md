# QH256 Validation PoC v0.1

Deterministic C11 reference implementation and validation test framework for the QH256 structure.

## Structure

- `qh256.h` — public interface and canonical constants
- `qh256.c` — reference implementation
- `test_qh256_validation.c` — deterministic validation suite
- `Makefile` — reproducible build
- `run_validation.sh` — clean build and test command

## Canonical definition used by this PoC

- 128 cells
- 2 bits per cell
- 256 bits total
- 32 bytes total
- `00 = UNKNOWN`
- `01 = FALSE`
- `10 = TRUE`
- `11 = GUARD`

Packing is deterministic: cell 0 occupies bits 1:0 of byte 0, cell 1 occupies bits 3:2, cell 2 bits 5:4, and cell 3 bits 7:6. The pattern repeats for all 32 bytes.

## MERGE_K

This implementation uses the stated QH256 definition that MERGE_K is bitwise OR over the two-bit state encoding.

Truth table:

| A | B | A OR B |
|---|---|--------|
| UNKNOWN | UNKNOWN | UNKNOWN |
| UNKNOWN | FALSE   | FALSE   |
| UNKNOWN | TRUE    | TRUE    |
| UNKNOWN | GUARD   | GUARD   |
| FALSE   | UNKNOWN | FALSE   |
| FALSE   | FALSE   | FALSE   |
| FALSE   | TRUE    | GUARD   |
| FALSE   | GUARD   | GUARD   |
| TRUE    | UNKNOWN | TRUE    |
| TRUE    | FALSE   | GUARD   |
| TRUE    | TRUE    | TRUE    |
| TRUE    | GUARD   | GUARD   |
| GUARD   | UNKNOWN | GUARD   |
| GUARD   | FALSE   | GUARD   |
| GUARD   | TRUE    | GUARD   |
| GUARD   | GUARD   | GUARD   |

## Build on Debian / Linux

```sh
make clean
make
./qh256_validation
```

Or:

```sh
./run_validation.sh
```

## VS Codium

Open this directory as a workspace. The project is plain C11 and does not require a framework.

Recommended build command in the integrated terminal:

```sh
make test
```

## Evidence boundary

This repository is a validation PoC. A successful local test run demonstrates only that the included implementation passes the included test suite on the environment where it was executed. It does not by itself establish mathematical novelty, cryptographic security, hardware independence, or scientific superiority.
