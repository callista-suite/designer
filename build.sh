#!/bin/sh
rm -rf bin                     2>/dev/null
mkdir bin
mkdir build                    2>/dev/null
meson build
cd build
ninja
cd ..
cp build/shapesplash* bin/
cp build/*.dll bin/            2>/dev/null
cp build/*.pdb bin/            2>/dev/null
cp res/* bin/                  2>/dev/null