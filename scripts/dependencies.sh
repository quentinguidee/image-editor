#!/usr/bin/env bash

if [[ $(uname) == "Darwin" ]]; then
    bash scripts/dependencies_macos.sh
else
    bash scripts/dependencies_ubuntu.sh
fi
