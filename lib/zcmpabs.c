#include "zcmpabs.h"
#include <stdint.h>

int32_t wmpz_cmpabs(wmpz_ptr u, wmpz_ptr v) {
  int32_t usize, vsize, dsize;
  uint64_t * up;
  uint64_t * vp;
  int32_t cmp;
  if (SIZ(u) >= 0) {
    usize = SIZ(u);
  } else {
    usize = -SIZ(u);
  }
  if (SIZ(v) >= 0) {
    vsize = SIZ(v);
  } else {
    vsize = -SIZ(v);
  }
  dsize = usize - vsize;
  if (!(dsize == 0)) {
    return dsize;
  }
  up = PTR(u);
  vp = PTR(v);
  cmp = wmpn_cmp(up, vp, usize);
  (void)(u);
  (void)(v);
  return cmp;
}

int32_t wmpz_cmpabs_ui(wmpz_ptr u, uint64_t v_digit) {
  int32_t un;
  uint64_t * up;
  uint64_t ul;
  un = SIZ(u);
  if (un == 0) {
    if (!(v_digit == UINT64_C(0))) {
      return -1;
    } else {
      return 0;
    }
  }
  if ((un >= 0 ? un : -un) == 1) {
    up = PTR(u);
    ul = *up;
    (void)(u);
    if (ul > v_digit) {
      return 1;
    }
    if (ul < v_digit) {
      return -1;
    }
    return 0;
  }
  return 1;
}
