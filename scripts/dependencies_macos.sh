#!/usr/bin/env bash
if [ "$(command -v brew)" ]; then
    echo "Installing sdl2 and sdl2_ttf with homebrew..."
    brew install sdl2 sdl2_ttf sdl2_image

    # Install Google Test
    echo "Installing Google Tests..."
    git clone https://github.com/google/googletest
    cd googletest
    mkdir build
    cd build
    cmake .. -DCMAKE_CXX_STANDARD=17
    make
    make install
    rm -rf googletest
else
    echo "Brew is not installed. Cannot install dependencies."
fi
