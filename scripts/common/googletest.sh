#!/usr/bin/env bash

TEMP_FOLDER=temp_gtest

echo "Installing Google Tests..."
git clone https://github.com/google/googletest $TEMP_FOLDER
cd $TEMP_FOLDER || exit
mkdir build
cd build || exit
cmake .. -DCMAKE_CXX_STANDARD=17
make
make install
rm -rf $TEMP_FOLDER
