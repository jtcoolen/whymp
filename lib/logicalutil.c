#include "logicalutil.h"
#include <stdint.h>
struct __lsld_ext_result;


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
