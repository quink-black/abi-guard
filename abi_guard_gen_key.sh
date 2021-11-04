#!/bin/sh

set -e

git_repo_version=$(git rev-parse --short HEAD)

cat abi_guard_key.in | sed "s|@GIT_REPO_VERSION@|$git_repo_version|" > abi_guard_key.h
