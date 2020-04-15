#include "utilold.h"
#include <stdint.h>

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
