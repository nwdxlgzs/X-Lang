#ifndef XLANGCONF_H
#define XLANGCONF_H
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
typedef uint8_t x_u8;
typedef int8_t x_s8;
typedef uint16_t x_u16;
typedef int16_t x_s16;
typedef uint32_t x_u32;
typedef int32_t x_s32;
typedef uint64_t x_u64;
typedef int64_t x_s64;
typedef double x_double;


#if defined(__GNUC__) && ((__GNUC__*100 + __GNUC_MINOR__) >= 302) &&  defined(__ELF__)
#define XLANG_IFUNC	    __attribute__((visibility("hidden"))) extern
#define XLANG_API       __attribute__((visibility("default"))) extern
#else	
#define XLANG_IFUNC     extern
#define XLANG_API       extern
#endif


#endif // XLANGCONF_H