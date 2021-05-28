#include "sub.h"
#include <stdint.h>

uint64_t wmpn_sub_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz) {
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
                  int32_t sy) {
  uint64_t lx, b;
  uint64_t result, res;
  int32_t i;
  lx = UINT64_C(0);
  result = wmpn_sub_n(r, x, y, sy);
  b = result;
  i = sy;
  if (!(b == UINT64_C(0))) {
    while (i < sx) {
      lx = x[i];
      res = lx - UINT64_C(1);
      r[i] = res;
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
