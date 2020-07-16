#ifndef ALIAS_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include <stdint.h>

struct __open_sep_result {
  uint64_t *__field_0;
  uint64_t *__field_1;
  uint64_t *__field_2;
};

struct __open_rx_result {
  uint64_t *__field_0;
  uint64_t *__field_1;
  uint64_t *__field_2;
};

struct __open_shift_sep_result {
  uint64_t *__field_0;
  uint64_t *__field_1;
};

static inline struct __open_sep_result
open_sep (uint64_t *r, uint64_t *x, uint64_t *y)
{
  struct __open_sep_result result;
  result.__field_0 = r;
  result.__field_1 = x;
  result.__field_2 = y;
  return result;
}

static inline struct __open_rx_result
open_rx (uint64_t *x, uint64_t *y)
{
  struct __open_rx_result result;
  result.__field_0 = x;
  result.__field_1 = x;
  result.__field_2 = y;
  return result;
}

static inline struct __open_shift_sep_result
open_shift_sep (uint64_t *r, uint64_t *x)
{
  struct __open_shift_sep_result result;
  result.__field_0 = r;
  result.__field_1 = x;
  return result;
}

#define ALIAS_H_INCLUDED
#endif // ALIAS_H_INCLUDED
