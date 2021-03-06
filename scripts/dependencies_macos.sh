#!/usr/bin/env bash
if [ "$(command -v brew)" ]; then
    echo "Installing sdl2 and sdl2_ttf with homebrew..."
    brew install sdl2 sdl2_ttf sdl2_image
else
    echo "Brew is not installed. Cannot install dependencies."
    exit 1
fi

bash scripts/common/googletest.sh
