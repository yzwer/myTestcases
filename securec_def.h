#ifndef __MY_SECUREC_DEF_H__
#define __MY_SECUREC_DEF_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef errno_t
typedef int errno_t;
#endif

errno_t memcpy_s(void* dest, size_t destMax, const void* src, size_t count);
errno_t strcpy_s(char* strDest, size_t destMax, const char* strSrc);
errno_t sprintf_s(char* strDest, size_t destMax, const char* format, ...);
errno_t snprintf_s(char* strDest, size_t destMax, size_t count, const char* format, ...);
errno_t memset_s(void* dest, size_t destMax, int c, size_t count);
errno_t strncpy_s(char* strDest, size_t destMax, const char* strSrc, size_t count);


#endif