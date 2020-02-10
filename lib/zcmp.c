#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
#include "int.h"

#include "power.h"

#include "map.h"

#include "c.h"

#include "compare.h"

#include "alias.h"

#include "compare.h"

#include "uint64gmp.h"

#include "abs.h"

#include "z.h"

#include "zutil.h"

#include "types.h"

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

