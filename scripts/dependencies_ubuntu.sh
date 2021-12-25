#!/usr/bin/env bash

sudo apt update
sudo apt install build-essential libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev

bash scripts/common/googletest.sh
