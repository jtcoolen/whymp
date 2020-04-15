#include "compare.h"
#include <stdint.h>

int32_t wmpn_cmp(uint64_t * x, uint64_t * y, int32_t sz) {
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
