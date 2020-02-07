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

void wmpn_copyi1(uint64_t * r, uint64_t * x, int32_t sz) {
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

