#include "baseinfo.h"
#include <stdint.h>

uint32_t wmpn_base_power_of_two_p(uint64_t b) {
  if (b == UINT64_C(2)) {
    return 1U;
  } else {
    if (b == UINT64_C(4)) {
      return 2U;
    } else {
      if (b == UINT64_C(8)) {
        return 3U;
      } else {
        if (b == UINT64_C(16)) {
          return 4U;
        } else {
          if (b == UINT64_C(32)) {
            return 5U;
          } else {
            if (b == UINT64_C(64)) {
              return 6U;
            } else {
              if (b == UINT64_C(128)) {
                return 7U;
              } else {
                if (b == UINT64_C(256)) {
                  return 8U;
                } else {
                  return 0U;
                }
              }
            }
          }
        }
      }
    }
  }
}
struct wmpn_base_info;


struct wmpn_base_info wmpn_get_base_info(uint64_t b) {
  uint64_t m;
  uint64_t p;
  uint32_t exp;
  struct wmpn_base_info wmpn_base_info;
  m = UINT64_C(0xFFFFFFFFFFFFFFFF) / b;
  p = b;
  exp = 1U;
  while (p <= m) {
    p = p * b;
    exp = exp + 1U;
  }
  wmpn_base_info.exp = exp;
  wmpn_base_info.bb = p;
  return wmpn_base_info;
}

uint64_t wmpn_limb_size_in_base_2(uint64_t u) {
  uint64_t shift;
  shift = (uint64_t)__builtin_clzll(u);
  return UINT64_C(64) - shift;
}
