#!/usr/bin/env sh
set -eu

make clean
make
./qh256_validation
