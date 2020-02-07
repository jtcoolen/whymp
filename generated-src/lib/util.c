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

#include "alias.h"

int32_t wmpn_zero_p(uint64_t * x, int32_t sz) {
  int32_t i;
  uint64_t uzero;
  uint64_t lx;
  i = sz;
  uzero = UINT64_C(0);
  lx = uzero;
  while (i >= 1) {
    i = i - 1;
    lx = x[i];
    if (!(lx == uzero)) {
      return 0;
    }
  }
  return 1;
}

void wmpn_zero(uint64_t * r, int32_t sz) {
  int32_t i;
  uint64_t lzero;
  i = 0;
  lzero = UINT64_C(0);
  while (i < sz) {
    r[i] = lzero;
    i = i + 1;
  }
}

void normalize(uint64_t * p, int32_t * n) {
  while (*n > 0) {
    if (!(p[*n - 1] == UINT64_C(0))) {
      break;
    }
    *n = *n - 1;
  }
}

void wmpn_copyd(uint64_t * rp, uint64_t * up, int32_t n) {
  int32_t i, o;
  uint64_t lu;
  o = n - 1;
  for (i = o; i >= 0; --i) {
    lu = up[i];
    rp[i] = lu;
  }
}

void wmpn_copyd_sep(uint64_t * rp, uint64_t * up, int32_t n) {
  uint64_t * nr;
  uint64_t * nx;
  struct __open_shift_sep_result struct_res;
  struct_res = open_shift_sep(rp, up, n);
  nr = struct_res.__field_0;
  nx = struct_res.__field_1;
  wmpn_copyd(nr, nx, n);
  IGNORE2(rp,up);
  return;
}

void wmpn_copyi(uint64_t * rp, uint64_t * up, int32_t n) {
  int32_t i, o;
  uint64_t lu;
  o = n - 1;
  if (0 <= o) {
    for (i = 0; ; ++i) {
      lu = up[i];
      rp[i] = lu;
      if (i == o) {
        break;
      }
    }
  }
}

