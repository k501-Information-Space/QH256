#!/usr/bin/env bash
set -eu
make clean
make test
make asan
