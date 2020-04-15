#include "zget_str.h"
#include <stdint.h>
#include <string.h>

char * wmpz_get_str(char * sp, int32_t base, wmpz_ptr u) {
  char * digits;
  int32_t base1, i, sn;
  int32_t un;
  uint32_t bits;
  uint64_t * up;
  unsigned char * usp;
  unsigned char * uspi;
  uint32_t g;
  struct wmpn_base_info info;
  uint64_t * tp;
  uint32_t g1;
  int32_t j, o;
  unsigned char cj;
  char dc;
  if (base > 36) {
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  } else {
    if (base >= 0) {
      digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    } else {
      digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
  }
  base1 = base;
  if (base1 <= 0) {
    base1 = -base1;
  }
  if (base1 <= 1) {
    base1 = 10;
  }
  if (SIZ(u) >= 0) {
    un = SIZ(u);
  } else {
    un = -SIZ(u);
  }
  if (un == 0) {
    sp[0] = '0';
    sp[1] = '\0';
    return sp;
  }
  i = 0;
  sn = 0;
  if (SIZ(u) < 0) {
    sp[0] = '-';
    i = i + 1;
  }
  bits = wmpn_base_power_of_two_p((uint64_t)base1);
  up = PTR(u);
  usp = (unsigned char *)sp;
  uspi = usp + i;
  if (!(bits == 0U)) {
    g = wmpn_get_str_bits(uspi, bits, up, un);
    sn = i + (int32_t)g;
  } else {
    info = wmpn_get_base_info((uint64_t)base1);
    tp = alloca((uint32_t)un * sizeof(uint64_t));
    wmpn_copyd_sep(tp, up, un);
    g1 = wmpn_get_str_other(uspi, base1, info, tp, un);
    sn = i + (int32_t)g1;
  }
  IGNORE2(sp, usp);
  o = sn - 1;
  if (i <= o) {
    for (j = i; ; ++j) {
      cj = (unsigned char)sp[j];
      dc = digits[(int32_t)cj];
      sp[j] = dc;
      if (j == o) {
        break;
      }
    }
  }
  sp[sn] = '\0';
  (void)(u);
  return sp;
}
