#pragma once

#ifdef WIN32
// #ifdef MAKEDLL
#  define EXPORT __declspec(dllexport)
#else
#  define EXPORT
#endif
// #else
// #  define EXPORT __declspec(dllimport)
// #endif