#!/bin/sh
rm -rf bin                                                                                 2>/dev/null
mkdir bin
mkdir build                                                                                2>/dev/null
LIBNAME="libcallistashared"
LIB_SUBPROJ="subprojects/$LIBNAME"
if [ -d "$LIB_SUBPROJ" ]; then
	# We don't need to do anything.
	echo "We already have $LIB_SUBPROJ, continuing..."
elif [ -d "../$LIBNAME" ]; then
	mkdir subprojects                                                                      2>/dev/null
	echo "Linking ../$LIBNAME to $LIB_SUBPROJ"
	ln -s "../../$LIBNAME" "$LIB_SUBPROJ"
	CALLISTA_SHARED_PATH="../$LIBNAME"
else
	mkdir subprojects                                                                      2>/dev/null
	cd subprojects
	echo "Cloning https://github.com/callista-suite/$LIBNAME into ./subprojects/"
	git clone     https://github.com/callista-suite/$LIBNAME
	cd ..
fi
meson build $@
cd build
ninja
cd ..
cp build/callista-designer* bin/
cp build/*.dll bin/                                                                        2>/dev/null
cp build/*.pdb bin/                                                                        2>/dev/null
cp res/* bin/                                                                              2>/dev/null