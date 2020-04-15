#include "zutil.h"
#include <stdint.h>

void __wmpz_init (wmpz_ptr x) {
  ALLOC(x) = 1;
  SIZ(x) = 0;
  PTR(x) = malloc(sizeof(uint64_t));
  PTR(x)[0] = 0;
  return;
}

void wmpz_clear (wmpz_ptr x)
{
  free (PTR(x));
}

uint64_t * wmpz_do_realloc(wmpz_ptr x, int32_t sz) {
  uint64_t * p;
  uint64_t * q;
  p = PTR(x);
  q = realloc(p, sz * sizeof(uint64_t));
  assert (q);
  ALLOC(x) = sz;
  PTR(x) = q;
  return q;
}

uint64_t * wmpz_realloc(wmpz_ptr x, int32_t sz) {
  if (sz > ALLOC(x)) {
    return wmpz_do_realloc(x, sz);
  } else {
    return PTR(x);
  }
}
