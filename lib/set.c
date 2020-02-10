#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
#include "int.h"

#include "euclideandivision.h"

#include "abs.h"

#include "map.h"

#include "c.h"

#include "int32.h"

#include "int64.h"

#include "uint64gmp.h"

#include "z.h"

#include "zutil.h"

void wmpz_set_ui(wmpz_ptr dst, uint64_t src) {
  uint64_t * dstp;
  int32_t size;
  dstp = wmpz_realloc(dst, 1);
  *dstp = src;
  if (!(src == UINT64_C(0))) {
    size = 1;
  } else {
    size = 0;
  }
  SIZ(dst) = size;
  (void)(dst);
  return;
}

uint64_t abs_cast(int64_t x) {
  if (x >= INT64_C(0)) {
    return (uint64_t)x;
  } else {
    return (uint64_t)-(x + INT64_C(1)) + UINT64_C(1);
  }
}

void wmpz_set_si(wmpz_ptr dst, int64_t src) {
  uint64_t * dstp;
  uint64_t abs_src;
  int32_t size, size1;
  dstp = wmpz_realloc(dst, 1);
  abs_src = abs_cast(src);
  *dstp = abs_src;
  if (!(abs_src == UINT64_C(0))) {
    size = 1;
  } else {
    size = 0;
  }
  if (src >= INT64_C(0)) {
    size1 = size;
  } else {
    size1 = -size;
  }
  SIZ(dst) = size1;
  (void)(dst);
  return;
}

uint64_t wmpz_get_ui(wmpz_ptr src) {
  uint64_t * srcp;
  uint64_t v;
  if (SIZ(src) == 0) {
    return UINT64_C(0);
  }
  srcp = PTR(src);
  v = *srcp;
  (void)(src);
  return v;
}

