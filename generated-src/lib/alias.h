#ifndef ALIAS_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>

struct __open_sep_result
{ uint64_t *__field_0;
uint64_t *__field_1;
uint64_t *__field_2;
};

struct __open_rx_result
{ uint64_t *__field_0;
uint64_t *__field_1;
uint64_t *__field_2;
};

struct __open_shift_sep_result
{ uint64_t *__field_0;
uint64_t *__field_1;
};

static inline struct __open_sep_result
open_sep (uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y, int32_t sy)
{
struct __open_sep_result result;
result.__field_0 = r;
result.__field_1 = x;
result.__field_2 = y;
return result;
}

static inline struct __open_rx_result
open_rx (uint64_t * x, int32_t sx, uint64_t * y, int32_t sy)
{
struct __open_rx_result result;
result.__field_0 = x;
result.__field_1 = x;
result.__field_2 = y;
return result;
}

static inline struct __open_shift_sep_result
open_shift_sep (uint64_t * r, uint64_t * x, int32_t sz)
{
struct __open_shift_sep_result result;
result.__field_0 = r;
result.__field_1 = x;
return result;
}

#define ALIAS_H_INCLUDED
#endif // ALIAS_H_INCLUDED
