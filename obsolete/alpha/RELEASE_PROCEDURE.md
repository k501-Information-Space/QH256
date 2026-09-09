# Release Procedure

## Preconditions

Run this on the project workstation where both source workspaces exist.

```bash
cd /home/hirn/K501/workspace
ls -ld QH256_Validation_v0.1 QH256_Validation_v2.0
```

Do not continue if either source path is missing.

## 1. Clone or enter the QH256 repository

```bash
git clone https://github.com/k501-Information-Space/QH256.git
cd QH256
```

Preserve the existing repository history.

## 2. Apply the repository structure

Copy the structural files from this package into the repository root. Do not delete the existing alpha history.

## 3. Import validation workspaces

```bash
mkdir -p tests/validation/v0.1 tests/validation/v2.0
cp -a /home/hirn/K501/workspace/QH256_Validation_v0.1/. tests/validation/v0.1/
cp -a /home/hirn/K501/workspace/QH256_Validation_v2.0/. tests/validation/v2.0/
```

If the workspaces already contain their own `.git` metadata, remove only those nested Git directories before committing:

```bash
find tests/validation -type d -name .git -prune -exec rm -rf {} +
```

## 4. Verify test artifacts

Run the v0.1 and v2.0 validation commands recorded in their local README / scripts. Do not invent a new result. Record the actual output.

For v2.0, verify that the documented result remains:

`6,620,625 assertions / 0 failures / PASS`

## 5. Add repository documentation

Install the files from `docs/`, `references/`, and `metadata/`.

Update `README.md` only with verified facts.

## 6. Generate immutable release archives

From the repository root:

```bash
./scripts/prepare_release.sh \
  /home/hirn/K501/workspace/QH256_Validation_v0.1 \
  v0.1.0 \
  release-build

./scripts/prepare_release.sh \
  /home/hirn/K501/workspace/QH256_Validation_v2.0 \
  v2.0.0 \
  release-build
```

The resulting archives and SHA-256 manifests belong in the corresponding GitHub releases as binary assets.

## 7. Commit the repository restructure

Use a message such as:

```text
test: import QH256 validation v0.1 and v2.0 workspaces
```

Then:

```bash
git add .
git status
git diff --cached
```

Review the complete staged diff before committing.

## 8. Tag releases

```bash
git tag -a QH256_Validation_v0.1.0 -m "QH256 Validation v0.1.0"
git tag -a QH256_Validation_v2.0.0 -m "QH256 Validation v2.0.0"
```

Do not move or overwrite existing tags.

## 9. Push

```bash
git push origin main
git push origin QH256_Validation_v0.1.0

git push origin QH256_Validation_v2.0.0
```

## 10. Publish GitHub releases

Create two GitHub releases from the corresponding tags.

For each release upload:

- the `.tar.gz` source archive;
- the `.zip` source archive;
- the `.SHA256SUMS` manifest.

Use the prepared release notes from `releases/`.

## 11. Final release verification

After publication, verify:

- release tag exists;
- release assets download correctly;
- SHA-256 manifests match;
- README links resolve;
- Zenodo reference is present;
- ORCID is correct;
- both validation generations are discoverable;
- historical alpha release remains unchanged;
- v2.0 validation result is stated with its exact scope.

## Recommended release order

Publish `QH256_Validation_v0.1.0` first as the historical validation checkpoint.

Publish `QH256_Validation_v2.0.0` second as the current validated implementation scope.
