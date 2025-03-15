#ifndef _TYPES_H
#define _TYPES_H

#include "psyq/sys/types.h"

#ifndef NULL
#define NULL 0
#endif

typedef signed char 	   byte;
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

#ifndef __cplusplus
typedef enum { false, true } bool;
#endif

#define NO_VALUE -1

// Slightly modified VECTOR with padding int removed. Seems to be used through much of SH code.
typedef struct
{
    long vx;
    long vy;
    long vz;
} VECTOR3;

#endif
