#!/usr/bin/env bash
set -euo pipefail

usage() {
  echo "Usage: $0 <validation-workspace> <version> <output-dir>"
  echo "Example: $0 /home/hirn/K501/workspace/QH256_Validation_v2.0 v2.0.0 dist"
}

[[ $# -eq 3 ]] || { usage >&2; exit 2; }
SRC=$1
VER=$2
OUT=$3

[[ -d "$SRC" ]] || { echo "ERROR: workspace not found: $SRC" >&2; exit 1; }
mkdir -p "$OUT"

NAME="QH256_Validation_${VER}"
STAGE="$OUT/$NAME"
rm -rf "$STAGE"
mkdir -p "$STAGE"
cp -a "$SRC"/. "$STAGE"/

cat > "$STAGE/SOURCE_WORKSPACE.txt" <<META
QH256 Validation Release
version=$VER
source_workspace=$SRC
prepared_at_unix=$(date +%s)
META

TAR="$OUT/${NAME}.tar.gz"
ZIP="$OUT/${NAME}.zip"
rm -f "$TAR" "$ZIP"

tar -C "$OUT" -czf "$TAR" "$NAME"
(cd "$OUT" && zip -qr "${NAME}.zip" "$NAME")

sha256sum "$TAR" "$ZIP" | tee "$OUT/${NAME}.SHA256SUMS"
