#pragma once

// Just include build_info.hpp.

// Massive mess of platform-detection macros.
//
//             Windows: SS_OS_WIN32
//               Apple: SS_OS_APPLE    SS_OS_NIX  (SS_OS_IOS | SS_OS_MACOS)
//             Android: SS_OS_ANDROID  SS_OS_NIX
//               Linux: SS_OS_LINUX    SS_OS_NIX  SS_OS_GTK
//                 BSD: SS_OS_BSD      SS_OS_NIX  SS_OS_GTK
//  Generic POSIX/Unix: SS_OS_NIX                 SS_OS_GTK
//
#ifdef _WIN32
	#define SS_OS_WIN32 1
#elif __APPLE__
	#define SS_OS_APPLE 1
	#define SS_OS_NIX 1
	#include "TargetConditionals.h"
	#if TARGET_IPHONE_SIMULATOR
		#define SS_OS_IOS 1
	#elif TARGET_OS_IPHONE
		#define SS_OS_IOS 1
	#elif TARGET_OS_MAC
		#define SS_OS_MACOS 1
	#else
		#error "Unknown Apple platform"
	#endif
#elif __ANDROID__
	#define SS_OS_ANDROID 1
	#define SS_OS_NIX 1
#elif __linux__
	#define SS_OS_NIX 1
	#define SS_OS_LINUX 1
	#define SS_OS_GTK 1
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
	#define SS_OS_NIX 1
	#define SS_OS_BSD 1
	#define SS_OS_GTK 1
#elif __unix__
	#define SS_OS_NIX 1
	#define SS_OS_GTK 1
#elif defined(_POSIX_VERSION)
	#define SS_OS_NIX 1
	#define SS_OS_GTK 1
#else
	#error "Unknown platform."
#endif

// Clearing out unused defines.

#ifndef SS_OS_WIN32
#define SS_OS_WIN32 0
#endif

#ifndef SS_OS_APPLE
#define SS_OS_APPLE 0
#endif

#ifndef SS_OS_IOS
#define SS_OS_IOS 0
#endif

#ifndef SS_OS_MACOS
#define SS_OS_MACOS 0
#endif

#ifndef SS_OS_ANDROID
#define SS_OS_ANDROID 0
#endif

#ifndef SS_OS_LINUX
#define SS_OS_LINUX 0
#endif

#ifndef SS_OS_BSD
#define SS_OS_BSD 0
#endif

#ifndef SS_OS_NIX
#define SS_OS_NIX 0
#endif

#ifndef SS_OS_GTK
#define SS_OS_GTK 0
#endif
