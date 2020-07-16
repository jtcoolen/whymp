#include "add.h"
#include <stdint.h>

uint64_t wmpn_add_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz) {
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
                  int32_t sy) {
  uint64_t lx, c;
  uint64_t o, res;
  int32_t i;
  lx = UINT64_C(0);
  o = wmpn_add_n(r, x, y, sy);
  c = o;
  i = sy;
  if (!(c == UINT64_C(0))) {
    while (i < sx) {
      lx = x[i];
      res = lx + UINT64_C(1);
      r[i] = res;
      i = i + 1;
      if (!(res == UINT64_C(0))) {
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
