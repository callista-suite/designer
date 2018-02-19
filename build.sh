#!/bin/sh
rm -rf bin                                                                                 2>/dev/null
mkdir bin
BUILD_DIR=build
if [[ -d "$DEV_RAMDISK" ]]; then
	BUILD_DIR="$DEV_RAMDISK/callista/designer/build"
fi
mkdir -p "$BUILD_DIR"
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
if [[ -d "$DEV_RAMDISK" ]]; then
	# I'm so, so sorry. This is probably horrible
	# practice, but I'm impatient.
	echo "Mounting ramdisk include dir to /usr/include."
	sudo mount --bind $DEV_RAMDISK/usr_include /usr/include
fi
meson $BUILD_DIR $@
pushd $BUILD_DIR
ninja
popd
if [[ -d "$DEV_RAMDISK" ]]; then
	echo "Unmounting ramdisk include dir."
	sudo umount /usr/include
fi
cp $BUILD_DIR/callista-designer* ./bin/
cp $BUILD_DIR/*.dll bin/                                                                   2>/dev/null
cp $BUILD_DIR/*.pdb bin/                                                                   2>/dev/null
cp res/* bin/                                                                              2>/dev/null