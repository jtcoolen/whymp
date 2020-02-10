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

#include "mul.h"

void wmpn_mul_basecase(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                       int32_t sy) {
  uint64_t c;
  uint64_t * rp;
  uint64_t * vp;
  int32_t vn;
  uint64_t res, res1;
  c = wmpn_mul_1(r, x, sx, *y);
  r[sx] = c;
  rp = r + 1;
  vp = y + 1;
  vn = sy - 1;
  while (vn >= 2) {
    res = wmpn_addmul_2(rp, x, sx, vp);
    rp[sx + 1] = res;
    rp = rp + 2;
    vp = vp + 2;
    vn = vn - 2;
  }
  while (vn >= 1) {
    res1 = wmpn_addmul_1(rp, x, sx, *vp);
    rp[sx] = res1;
    rp = rp + 1;
    vp = vp + 1;
    vn = vn - 1;
  }
}

