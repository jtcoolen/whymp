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

int32_t wmpn_cmp(uint64_t * x, uint64_t * y, int32_t sz)
{
  int32_t i;
  uint64_t lx, ly;
  i = sz;
  while (i >= 1) {
    i = i - 1;
    lx = x[i];
    ly = y[i];
    if (!(lx == ly)) {
      if (lx > ly) {
        return 1;
      } else {
        return -1;
      }
    }
  }
  return 0;
}

