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

uint64_t wmpn_sub_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y)
{
  uint64_t b, lx;
  int32_t i;
  uint64_t res, res1;
  b = UINT64_C(0);
  lx = *x;
  i = 1;
  res = lx - y;
  *r = res;
  if (lx < y) {
    b = UINT64_C(1);
    while (i < sz) {
      lx = x[i];
      res1 = lx - UINT64_C(1);
      r[i] = res1;
      i = i + 1;
      if (!(lx == UINT64_C(0))) {
        b = UINT64_C(0);
        break;
      }
    }
  }
  while (i < sz) {
    lx = x[i];
    r[i] = lx;
    i = i + 1;
  }
  return b;
}

uint64_t wmpn_sub_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz)
{
  uint64_t lx, ly, b;
  int32_t i;
  uint64_t res, borrow;
  struct __sub64_with_borrow_result struct_res;
  lx = UINT64_C(0);
  ly = UINT64_C(0);
  b = UINT64_C(0);
  i = 0;
  while (i < sz) {
    lx = x[i];
    ly = y[i];
    struct_res = sub64_with_borrow(lx, ly, b);
    res = struct_res.__field_0;
    borrow = struct_res.__field_1;
    r[i] = res;
    b = borrow;
    i = i + 1;
  }
  return b;
}

uint64_t wmpn_sub(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy)
{
  uint64_t lx, ly, b;
  int32_t i;
  uint64_t res, borrow, res1;
  struct __sub64_with_borrow_result struct_res;
  lx = UINT64_C(0);
  ly = UINT64_C(0);
  b = UINT64_C(0);
  i = 0;
  while (i < sy) {
    lx = x[i];
    ly = y[i];
    struct_res = sub64_with_borrow(lx, ly, b);
    res = struct_res.__field_0;
    borrow = struct_res.__field_1;
    r[i] = res;
    b = borrow;
    i = i + 1;
  }
  if (!(b == UINT64_C(0))) {
    while (i < sx) {
      lx = x[i];
      res1 = lx - UINT64_C(1);
      r[i] = res1;
      i = i + 1;
      if (!(lx == UINT64_C(0))) {
        b = UINT64_C(0);
        break;
      }
    }
  }
  while (i < sx) {
    lx = x[i];
    r[i] = lx;
    i = i + 1;
  }
  return b;
}

uint64_t wmpn_sub_in_place(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy)
{
  uint64_t lx, ly, b;
  int32_t i;
  uint64_t res, borrow, res1;
  struct __sub64_with_borrow_result struct_res;
  lx = UINT64_C(0);
  ly = UINT64_C(0);
  b = UINT64_C(0);
  i = 0;
  while (i < sy) {
    lx = x[i];
    ly = y[i];
    struct_res = sub64_with_borrow(lx, ly, b);
    res = struct_res.__field_0;
    borrow = struct_res.__field_1;
    x[i] = res;
    b = borrow;
    i = i + 1;
  }
  if (!(b == UINT64_C(0))) {
    while (i < sx) {
      lx = x[i];
      res1 = lx - UINT64_C(1);
      x[i] = res1;
      i = i + 1;
      if (!(lx == UINT64_C(0))) {
        b = UINT64_C(0);
        break;
      }
    }
  }
  return b;
}

void wmpn_decr(uint64_t * x, uint64_t y)
{
  uint64_t b, lx;
  uint64_t * xp;
  uint64_t res, res1;
  b = UINT64_C(0);
  lx = *x;
  xp = x + 1;
  res = lx - y;
  *x = res;
  if (res > lx) {
    b = UINT64_C(1);
    while (!(b == UINT64_C(0))) {
      lx = *xp;
      res1 = lx - UINT64_C(1);
      *xp = res1;
      xp = xp + 1;
      if (!(lx == UINT64_C(0))) {
        b = UINT64_C(0);
        break;
      }
    }
  } else {
    return;
  }
}

void wmpn_decr_1(uint64_t * x)
{
  uint64_t lx;
  uint64_t * xp;
  uint64_t res;
  lx = UINT64_C(0);
  xp = x + 0;
  while (lx == UINT64_C(0)) {
    lx = *xp;
    res = lx - UINT64_C(1);
    *xp = res;
    xp = xp + 1;
  }
}

uint64_t wmpn_sub_1_in_place(uint64_t * x, int32_t sz, uint64_t y)
{
  uint64_t b, lx;
  int32_t i;
  uint64_t res, res1;
  b = UINT64_C(0);
  lx = *x;
  i = 1;
  res = lx - y;
  *x = res;
  if (lx < y) {
    b = UINT64_C(1);
    while (i < sz) {
      lx = x[i];
      res1 = lx - UINT64_C(1);
      x[i] = res1;
      i = i + 1;
      if (!(lx == UINT64_C(0))) {
        b = UINT64_C(0);
        break;
      }
    }
  }
  return b;
}

