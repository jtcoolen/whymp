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

uint64_t wmpn_add_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y)
{
  uint64_t lx;
  uint64_t res;
  int32_t i;
  uint64_t c;
  uint64_t res1;
  lx = *x;
  res = lx + y;
  i = 1;
  c = UINT64_C(0);
  *r = res;
  if (res < lx) {
    c = UINT64_C(1);
    while (i < sz) {
      lx = x[i];
      res1 = lx + UINT64_C(1);
      r[i] = res1;
      i = i + 1;
      if (!(res1 == UINT64_C(0))) {
        c = UINT64_C(0);
        break;
      }
    }
  }
  while (i < sz) {
    lx = x[i];
    r[i] = lx;
    i = i + 1;
  }
  return c;
}

uint64_t wmpn_add_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz)
{
  uint64_t lx, ly, c;
  int32_t i;
  uint64_t res, carry;
  struct __add64_with_carry_result struct_res;
  lx = UINT64_C(0);
  ly = UINT64_C(0);
  c = UINT64_C(0);
  i = 0;
  while (i < sz) {
    lx = x[i];
    ly = y[i];
    struct_res = add64_with_carry(lx, ly, c);
    res = struct_res.__field_0;
    carry = struct_res.__field_1;
    r[i] = res;
    c = carry;
    i = i + 1;
  }
  return c;
}

uint64_t wmpn_add(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy)
{
  uint64_t lx, ly, c;
  int32_t i;
  uint64_t res, carry, res1;
  struct __add64_with_carry_result struct_res;
  lx = UINT64_C(0);
  ly = UINT64_C(0);
  c = UINT64_C(0);
  i = 0;
  while (i < sy) {
    lx = x[i];
    ly = y[i];
    struct_res = add64_with_carry(lx, ly, c);
    res = struct_res.__field_0;
    carry = struct_res.__field_1;
    r[i] = res;
    c = carry;
    i = i + 1;
  }
  if (!(c == UINT64_C(0))) {
    while (i < sx) {
      lx = x[i];
      res1 = lx + UINT64_C(1);
      r[i] = res1;
      i = i + 1;
      if (!(res1 == UINT64_C(0))) {
        c = UINT64_C(0);
        break;
      }
    }
  }
  while (i < sx) {
    lx = x[i];
    r[i] = lx;
    i = i + 1;
  }
  return c;
}

uint64_t wmpn_add_in_place(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy)
{
  uint64_t lx, ly, c;
  int32_t i;
  uint64_t res, carry, res1;
  struct __add64_with_carry_result struct_res;
  lx = UINT64_C(0);
  ly = UINT64_C(0);
  c = UINT64_C(0);
  i = 0;
  while (i < sy) {
    lx = x[i];
    ly = y[i];
    struct_res = add64_with_carry(lx, ly, c);
    res = struct_res.__field_0;
    carry = struct_res.__field_1;
    x[i] = res;
    c = carry;
    i = i + 1;
  }
  if (!(c == UINT64_C(0))) {
    while (i < sx) {
      lx = x[i];
      res1 = lx + UINT64_C(1);
      x[i] = res1;
      i = i + 1;
      if (!(res1 == UINT64_C(0))) {
        c = UINT64_C(0);
        break;
      }
    }
  }
  return c;
}

void wmpn_incr(uint64_t * x, uint64_t y)
{
  uint64_t c, lx;
  uint64_t * xp;
  uint64_t res, res1;
  c = UINT64_C(0);
  lx = *x;
  xp = x + 1;
  res = lx + y;
  *x = res;
  if (res < lx) {
    c = UINT64_C(1);
    while (!(c == UINT64_C(0))) {
      lx = *xp;
      res1 = lx + UINT64_C(1);
      *xp = res1;
      xp = xp + 1;
      if (!(res1 == UINT64_C(0))) {
        c = UINT64_C(0);
        break;
      }
    }
  } else {
    return;
  }
}

void wmpn_incr_1(uint64_t * x)
{
  uint64_t r, lx;
  uint64_t * xp;
  uint64_t res;
  r = UINT64_C(0);
  lx = UINT64_C(0);
  xp = x + 0;
  while (r == UINT64_C(0)) {
    lx = *xp;
    res = lx + UINT64_C(1);
    r = res;
    *xp = res;
    xp = xp + 1;
  }
}

uint64_t wmpn_add_1_in_place(uint64_t * x, int32_t sz, uint64_t y)
{
  uint64_t c, lx;
  int32_t i;
  uint64_t res, res1;
  c = UINT64_C(0);
  lx = *x;
  i = 1;
  res = lx + y;
  *x = res;
  if (res < lx) {
    c = UINT64_C(1);
    while (i < sz) {
      lx = x[i];
      res1 = lx + UINT64_C(1);
      x[i] = res1;
      i = i + 1;
      if (!(res1 == UINT64_C(0))) {
        c = UINT64_C(0);
        break;
      }
    }
  }
  return c;
}

