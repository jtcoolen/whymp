#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
#include "int.h"

#include "int32.h"

#include "uint64gmp.h"

#include "power.h"

#include "c.h"

#include "array.h"

#include "map.h"

#include "types.h"

#include "euclideandivision.h"

uint64_t lsl_mod_ext(uint64_t x, uint64_t cnt)
{ return x << cnt;
}

struct __lsld_ext_result
{ uint64_t __field_0;
  uint64_t __field_1;
};

struct __lsld_ext_result lsld_ext(uint64_t x, uint64_t cnt)
{
  struct __lsld_ext_result result;
  uint64_t r, d;
  struct __lsld64_result struct_res;
  struct __lsld_ext_result result1;
  if (cnt == UINT64_C(0)) {
    result.__field_0 = x;
    result.__field_1 = UINT64_C(0);
    return result;
  } else {
    struct_res = lsld64(x, cnt);
    r = struct_res.__field_0;
    d = struct_res.__field_1;
    result1.__field_0 = r;
    result1.__field_1 = d;
    return result1;
  }
}

int32_t clz_ext(uint64_t x)
{ return __builtin_clzll(x);
}

uint64_t wmpn_lshift(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt)
{
  int32_t msb;
  uint64_t * xp;
  uint64_t * rp;
  uint64_t high, low;
  int32_t i;
  uint64_t l, retval, l1, h;
  struct __lsld_ext_result struct_res, struct_res1;
  msb = sz - 1;
  xp = x + msb;
  rp = r + msb;
  high = UINT64_C(0);
  low = *xp;
  i = msb;
  struct_res = lsld_ext(low, cnt);
  l = struct_res.__field_0;
  retval = struct_res.__field_1;
  high = l;
  while (i > 0) {
    xp = xp + -1;
    low = *xp;
    struct_res1 = lsld_ext(low, cnt);
    l1 = struct_res1.__field_0;
    h = struct_res1.__field_1;
    *rp = high + h;
    rp = rp + -1;
    high = l1;
    i = i - 1;
  }
  *r = high;
  return retval;
}

uint64_t wmpn_rshift(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt)
{
  uint64_t tnc;
  int32_t msb;
  uint64_t * xp;
  uint64_t * rp;
  uint64_t high;
  uint64_t retval, h;
  struct __lsld_ext_result struct_res;
  uint64_t low;
  int32_t i;
  uint64_t l, h1;
  struct __lsld_ext_result struct_res1;
  tnc = UINT64_C(64) - cnt;
  msb = sz - 1;
  xp = x + 0;
  rp = r + 0;
  high = *xp;
  struct_res = lsld_ext(high, tnc);
  retval = struct_res.__field_0;
  h = struct_res.__field_1;
  low = h;
  i = 0;
  while (i < msb) {
    xp = xp + 1;
    high = *xp;
    struct_res1 = lsld_ext(high, tnc);
    l = struct_res1.__field_0;
    h1 = struct_res1.__field_1;
    *rp = low + l;
    low = h1;
    i = i + 1;
    rp = rp + 1;
  }
  *rp = low;
  return retval;
}

uint64_t wmpn_lshift_in_place(uint64_t * x, int32_t sz, uint64_t cnt)
{
  int32_t msb;
  uint64_t * xp;
  uint64_t high, low;
  int32_t i;
  uint64_t l, retval, l1, h;
  struct __lsld_ext_result struct_res, struct_res1;
  msb = sz - 1;
  xp = x + msb;
  high = UINT64_C(0);
  low = *xp;
  i = msb;
  struct_res = lsld_ext(low, cnt);
  l = struct_res.__field_0;
  retval = struct_res.__field_1;
  high = l;
  while (i > 0) {
    xp = xp + -1;
    low = *xp;
    struct_res1 = lsld_ext(low, cnt);
    l1 = struct_res1.__field_0;
    h = struct_res1.__field_1;
    xp[1] = high + h;
    high = l1;
    i = i - 1;
  }
  *x = high;
  return retval;
}

uint64_t wmpn_rshift_in_place(uint64_t * x, int32_t sz, uint64_t cnt)
{
  uint64_t tnc;
  int32_t msb;
  uint64_t * xp;
  uint64_t high;
  uint64_t retval, h;
  struct __lsld_ext_result struct_res;
  uint64_t low;
  int32_t i;
  uint64_t l, h1;
  struct __lsld_ext_result struct_res1;
  tnc = UINT64_C(64) - cnt;
  msb = sz - 1;
  xp = x + 0;
  high = *xp;
  struct_res = lsld_ext(high, tnc);
  retval = struct_res.__field_0;
  h = struct_res.__field_1;
  low = h;
  i = 0;
  while (i < msb) {
    xp = xp + 1;
    high = *xp;
    struct_res1 = lsld_ext(high, tnc);
    l = struct_res1.__field_0;
    h1 = struct_res1.__field_1;
    xp[-1] = low + l;
    low = h1;
    i = i + 1;
  }
  x[msb] = low;
  return retval;
}

