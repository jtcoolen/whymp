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

#include "map.h"

#include "types.h"

void wmpn_copyi(uint64_t * r, uint64_t * x, int32_t sz)
{
  int32_t i;
  uint64_t * xp;
  uint64_t * rp;
  i = 0;
  xp = x + 0;
  rp = r + 0;
  while (i < sz) {
    *rp = *xp;
    rp = rp + 1;
    xp = xp + 1;
    i = i + 1;
  }
}

int32_t wmpn_zero_p(uint64_t * x, int32_t sz)
{
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

void wmpn_zero(uint64_t * r, int32_t sz)
{
  int32_t i;
  uint64_t lzero;
  i = 0;
  lzero = UINT64_C(0);
  while (i < sz) {
    r[i] = lzero;
    i = i + 1;
  }
}

