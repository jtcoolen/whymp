#include "zcmp.h"
#include <stdint.h>

int32_t wmpz_cmp(wmpz_ptr u, wmpz_ptr v) {
  int32_t usize, vsize, dsize, asize;
  uint64_t * up;
  uint64_t * vp;
  int32_t cmp;
  usize = SIZ(u);
  vsize = SIZ(v);
  dsize = usize - vsize;
  if (!(dsize == 0)) {
    return dsize;
  }
  if (usize >= 0) {
    asize = usize;
  } else {
    asize = -usize;
  }
  up = PTR(u);
  vp = PTR(v);
  cmp = wmpn_cmp(up, vp, asize);
  (void)(u);
  (void)(v);
  if (usize >= 0) {
    return cmp;
  } else {
    return -cmp;
  }
}

int32_t wmpz_cmp_ui(wmpz_ptr u, uint64_t v_digit) {
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
  if (un == 1) {
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
  if (un > 0) {
    return 1;
  } else {
    return -1;
  }
}

int32_t wmpz_cmp_si(wmpz_ptr u, int64_t v_digit) {
  int32_t usize, vsize;
  uint64_t * up;
  uint64_t ul, vl;
  usize = SIZ(u);
  vsize = (v_digit > INT64_C(0)) - (v_digit < INT64_C(0));
  if (usize == 0 || !(usize == vsize)) {
    return usize - vsize;
  } else {
    up = PTR(u);
    ul = *up;
    vl = abs_cast(v_digit);
    (void)(u);
    if (ul == vl) {
      return 0;
    }
    if (ul > vl) {
      return usize;
    } else {
      return -usize;
    }
  }
}

int32_t wmpz_sgn(wmpz_ptr u) {
  if (SIZ(u) < 0) {
    return -1;
  } else {
    if (SIZ(u) > 0) {
      return 1;
    } else {
      return 0;
    }
  }
}
