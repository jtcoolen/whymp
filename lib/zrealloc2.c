#include "zrealloc2.h"
#include <stdint.h>

void wmpz_realloc2(wmpz_ptr x, uint64_t bits) {
  uint64_t bits1;
  int32_t new_alloc;
  uint64_t * p;
  uint64_t * q;
  bits1 = bits - !(bits == UINT64_C(0));
  new_alloc = (int32_t)(UINT64_C(1) + bits1 / UINT64_C(64));
  p = PTR(x);
  q = realloc(p, new_alloc * sizeof(uint64_t));
  assert (q);
  ALLOC(x) = new_alloc;
  PTR(x) = q;
  (void)(x);
  return;
}
