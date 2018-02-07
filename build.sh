#!/bin/sh
echo "for i in "
mkdir build
meson build
cd build
ninja
cd ..
cp build/shapesplash* bin/
cp build/*.dll bin/
cp build/*.pdb bin/
cp res/* bin/