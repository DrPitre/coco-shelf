#!/usr/bin/env bash
# Run from any directory to commit, push, and open the integration PR.
set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")/.."
command -v gh >/dev/null
gh auth status

branch=integrate-nitros9-c-libs
current_branch=$(git branch --show-current)
if [[ "$current_branch" != "$branch" ]]; then
    git switch -c "$branch"
fi

files=(.gitignore Makefile README.md conf.mk scripts/pr-nitros9-c-libs.sh)
# Keep any unrelated staged work out of this commit.
git add -- "${files[@]}"
git diff --cached --check -- "${files[@]}"
if ! git diff --quiet HEAD -- "${files[@]}"; then
    git commit --only -m "Integrate nitros9-c-libs into shelf builds" -- "${files[@]}"
fi
git push -u origin "$branch"

existing_pr=$(gh pr list --repo DrPitre/coco-shelf --head "$branch" --base main --state open --json url --jq '.[0].url // empty')
if [[ -n "$existing_pr" ]]; then
    printf '%s\n' "$existing_pr"
    exit 0
fi

body_file=$(mktemp)
trap 'rm -f "$body_file"' EXIT
cat > "$body_file" <<'EOF'
Switch the shelf's C library integration from cmoc_os9 to nitros9-c-libs, including fetching, default builds, cleanup, and ignored checkout files. Preserve the former make targets as compatibility aliases, use recursive make, update CMOC to 0.1.100, and document the generated archives.

Validation: fetched and built with `make ANON=1 nitros9-c-libs.done`; confirmed libc.a, libcf.a, and libcgfx.a were generated and the former cmoc_os9 targets resolve successfully. The build completed with upstream compiler warnings. `git diff --check` passed.
EOF
gh pr create --repo DrPitre/coco-shelf --base main --head "$branch" \
    --title "Integrate nitros9-c-libs into shelf builds" --body-file "$body_file"
