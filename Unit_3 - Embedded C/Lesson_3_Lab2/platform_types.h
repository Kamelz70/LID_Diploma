#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H
#include <stdint.h>
#include <stdbool.h>

#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE CPU_TYPE_32
#define CPU_BIT_ORDER LSB_FIRST
#define CPU_BYTE_ORDER LOW_BYTE_FIRST

typedef _Bool boolean;
typedef int8_t int8;
typedef uint8_t uint8;
typedef int8_t sint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int16_t sint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int32_t sint32;

typedef float float32;
typedef double double64;

typedef volatile int8_t vint8;
typedef volatile uint8_t vuint8;
typedef volatile int16_t vint16;
typedef volatile uint16_t vuint16;
typedef volatile int32_t vint32;
typedef volatile uint32_t vuint32;

#endif