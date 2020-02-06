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

#include "util.h"

#include "add.h"

uint64_t wmpn_mul_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y)
{
  uint64_t cl, ul;
  int32_t n;
  uint64_t * up;
  uint64_t * rp;
  uint64_t l, h, lpl;
  struct __mul64_double_result struct_res;
  cl = UINT64_C(0);
  ul = UINT64_C(0);
  n = sz;
  up = x + 0;
  rp = r + 0;
  while (!(n == 0)) {
    ul = *up;
    up = up + 1;
    struct_res = mul64_double(ul, y);
    l = struct_res.__field_0;
    h = struct_res.__field_1;
    lpl = l + cl;
    cl = (lpl < cl ? UINT64_C(1) : UINT64_C(0)) + h;
    *rp = lpl;
    rp = rp + 1;
    n = n - 1;
  }
  return cl;
}

uint64_t wmpn_addmul_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y)
{
  uint64_t ul, rl, cl;
  int32_t n;
  uint64_t * rp;
  uint64_t * up;
  uint64_t l, h;
  struct __mul64_double_result struct_res;
  uint64_t lpl;
  ul = UINT64_C(0);
  rl = UINT64_C(0);
  cl = UINT64_C(0);
  n = sz;
  rp = r + 0;
  up = x + 0;
  while (!(n == 0)) {
    ul = *up;
    up = up + 1;
    struct_res = mul64_double(ul, y);
    l = struct_res.__field_0;
    h = struct_res.__field_1;
    lpl = l + cl;
    cl = (lpl < cl ? UINT64_C(1) : UINT64_C(0)) + h;
    rl = *rp;
    lpl = rl + lpl;
    cl = (lpl < rl ? UINT64_C(1) : UINT64_C(0)) + cl;
    *rp = lpl;
    rp = rp + 1;
    n = n - 1;
  }
  return cl;
}

uint64_t wmpn_addmul_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz)
{
  uint64_t * rp;
  uint64_t * vp;
  uint64_t lr, c;
  int32_t vn;
  uint64_t cqt, res, carry;
  struct __add64_with_carry_result struct_res;
  rp = r + 0;
  vp = y + 0;
  lr = UINT64_C(0);
  c = UINT64_C(0);
  vn = sz;
  while (!(vn == 0)) {
    cqt = wmpn_addmul_1(rp, x, sz, *vp);
    lr = rp[sz];
    struct_res = add64_with_carry(cqt, lr, c);
    res = struct_res.__field_0;
    carry = struct_res.__field_1;
    rp[sz] = res;
    c = carry;
    rp = rp + 1;
    vp = vp + 1;
    vn = vn - 1;
  }
  return c;
}

void wmpn_mul_basecase(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                       int32_t sy)
{
  uint64_t c;
  uint64_t * rp;
  uint64_t * vp;
  int32_t vn;
  uint64_t res;
  c = wmpn_mul_1(r, x, sx, *y);
  r[sx] = c;
  rp = r + 1;
  vp = y + 1;
  vn = sy - 1;
  while (vn >= 1) {
    res = wmpn_addmul_1(rp, x, sx, *vp);
    rp[sx] = res;
    rp = rp + 1;
    vp = vp + 1;
    vn = vn - 1;
  }
}

