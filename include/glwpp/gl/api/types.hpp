#pragma once

#include "KHR/khrplatform.h"

struct __GLsync;

namespace glwpp::gl {

using GLenum = unsigned int;
using GLboolean = unsigned char;
using GLbitfield = unsigned int;
using GLvoid = void;
using GLbyte = khronos_int8_t;
using GLubyte = khronos_uint8_t;
using GLshort = khronos_int16_t;
using GLushort = khronos_uint16_t;
using GLint = int;
using GLuint = unsigned int;
using GLsizei = int;
using GLfloat = khronos_float_t;
using GLdouble = double;
using GLchar = char;

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
using GLintptr = khronos_intptr_t;
#else
using GLintptr = khronos_intptr_t;
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
using GLsizeiptr = khronos_ssize_t;
#else
using GLsizeiptr = khronos_ssize_t;
#endif

using GLint64 = khronos_int64_t;
using GLuint64 = khronos_uint64_t;

typedef struct __GLsync *GLsync;
using GLdebugProc = void (*)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);

using ApiProc = void (*)(void);
using LoadFunc = ApiProc (*)(const char *name);

bool LoadGl_glad(LoadFunc func);

}