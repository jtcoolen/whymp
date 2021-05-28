#include "zneg.h"
#include <stdint.h>

void wmpz_neg(wmpz_ptr w, wmpz_ptr u) {
  int32_t usize, wsize, size;
  uint64_t * wp;
  uint64_t * up;
  usize = SIZ(u);
  wsize = -usize;
  if (!(u == w)) {
    if (usize >= 0) {
      size = usize;
    } else {
      size = -usize;
    }
    wp = wmpz_realloc(w, size);
    up = PTR(u);
    wmpn_copyd_sep(wp, up, size);
    (void)(u);
    SIZ(w) = wsize;
    (void)(w);
    return;
  } else {
    return;
  }
}
