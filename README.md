# Callista Designer


### Building
Designer is built with [Meson](//mesonbuild.com). That said, building doesn't work through plain Meson commands; instead, a build.sh file is used. Yup, even on Windows. The only supported Windows build environment is MSYS2 with Visual Studio 2017.

_Why_ doesn't it use plain old Meson? Good question - because I really care about clean build directories. Also, it makes pulling in [`libcallistashared`](//github.com/callista-suite/libcallistashared) a bit easier, since I can force git commands to run.

Also, because forcing the programmer to update a list of source files is trash, I dynamically generate the list of source files in the `meson.build` file - this means that Meson has to run every build anyway.

Anyway, enough justifying my decisions - here's a quick explanation for those of you who don't use Meson on how and why my build system works.

1. You call `build.sh`
2. `bin` and `build` are created, and `bin` is cleared if it isn't already
3. If you have `libcallistashared` in the directory above _this_ repo (`../libcallistashared`), then it's soft-linked into `subprojects/`   
   Otherwise, `libcallistashared` is cloned from the repo and put into `subprojects`
4. Meson is finally called.
	1. It builds the `libcallistashared` library
	2. It builds the application.
5. The final executable and any `dll` or `pdb`s are pulled into `bin`