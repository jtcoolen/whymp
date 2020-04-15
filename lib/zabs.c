#include "zabs.h"
#include <stdint.h>

void wmpz_abs(wmpz_ptr w, wmpz_ptr u) {
  int32_t size;
  uint64_t * wp;
  uint64_t * up;
  if (SIZ(u) >= 0) {
    size = SIZ(u);
  } else {
    size = -SIZ(u);
  }
  if (!(u == w)) {
    wp = wmpz_realloc(w, size);
    up = PTR(u);
    wmpn_copyd_sep(wp, up, size);
    (void)(u);
    SIZ(w) = size;
    (void)(w);
    return;
  } else {
    return;
  }
}
