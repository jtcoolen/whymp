#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
#include "int.h"

#include "int32.h"

#include "uint64gmp.h"

#include "power.h"

#include "c.h"

#include "array.h"

#include "map.h"

#include "types.h"

#include "euclideandivision.h"

uint64_t lsl_mod_ext(uint64_t x, uint64_t cnt) {
  return x << cnt;
}

struct __lsld_ext_result
{ uint64_t __field_0;
  uint64_t __field_1;
};

struct __lsld_ext_result lsld_ext(uint64_t x, uint64_t cnt) {
  struct __lsld_ext_result result;
  uint64_t r, d;
  struct __lsld64_result struct_res;
  struct __lsld_ext_result result1;
  if (cnt == UINT64_C(0)) {
    result.__field_0 = x;
    result.__field_1 = UINT64_C(0);
    return result;
  } else {
    struct_res = lsld64(x, cnt);
    r = struct_res.__field_0;
    d = struct_res.__field_1;
    result1.__field_0 = r;
    result1.__field_1 = d;
    return result1;
  }
}

int32_t clz_ext(uint64_t x) {
  return __builtin_clzll(x);
}

