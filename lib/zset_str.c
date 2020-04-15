#include "zset_str.h"
#include <stdint.h>
#include <string.h>

int32_t wmpz_set_str(wmpz_ptr r, char * sp, int32_t base) {
  int32_t sign;
  char * spi;
  unsigned char * dp;
  unsigned char digit;
  int32_t dn;
  char c;
  uint32_t bits;
  int32_t alloc, rn, rn1;
  uint64_t * rp;
  struct wmpn_base_info info;
  int32_t alloc1, rn2, rn3, rn4;
  uint64_t * rp1;
  if (*sp == '-') {
    sign = 1;
  } else {
    sign = 0;
  }
  spi = sp + sign;
  if (*spi == '\0') {
    SIZ(r) = 0;
    return -1;
  }
  dp = alloca(strlen(sp) * sizeof(unsigned char));
  digit = 0;
  dn = 0;
  while (!(*spi == '\0')) {
    c = *spi;
    if (36 < base) {
      if ('0' <= c && c <= '9') {
        digit = (unsigned char)(c - '0');
      } else {
        if ('a' <= c && c <= 'z') {
          digit = (unsigned char)(c - 'a' + 36);
        } else {
          if ('A' <= c && c <= 'Z') {
            digit = (unsigned char)(c - 'A' + 10);
          } else {
            digit = (unsigned char)base;
          }
        }
      }
    } else {
      if ('0' <= c && c <= '9') {
        digit = (unsigned char)(c - '0');
      } else {
        if ('a' <= c && c <= 'z') {
          digit = (unsigned char)(c - 'a' + 10);
        } else {
          if ('A' <= c && c <= 'Z') {
            digit = (unsigned char)(c - 'A' + 10);
          } else {
            digit = (unsigned char)base;
          }
        }
      }
    }
    if (digit >= (unsigned char)base) {
      SIZ(r) = 0;
      return -1;
    }
    dp[dn] = digit;
    dn = dn + 1;
    spi = spi + 1;
  }
  if (dn == 0) {
    SIZ(r) = 0;
    return -1;
  }
  bits = wmpn_base_power_of_two_p((uint64_t)base);
  if (bits > 0U) {
    alloc = (dn * (int32_t)bits + 63) / 64;
    rp = wmpz_realloc(r, alloc);
    rn = wmpn_set_str_bits(rp, dp, (uint32_t)dn, bits);
    if (!(sign == 0)) {
      rn1 = -rn;
    } else {
      rn1 = rn;
    }
    SIZ(r) = rn1;
    (void)(r);
  } else {
    info = wmpn_get_base_info((uint64_t)base);
    alloc1 = (dn + (int32_t)info.exp - 1) / (int32_t)info.exp;
    rp1 = wmpz_realloc(r, alloc1);
    rn2 = wmpn_set_str_other(rp1, dp, (uint32_t)dn, (uint64_t)base, info);
    rn3 = rn2 - (rp1[rn2 - 1] == UINT64_C(0));
    if (!(sign == 0)) {
      rn4 = -rn3;
    } else {
      rn4 = rn3;
    }
    SIZ(r) = rn4;
    (void)(r);
  }
  return 0;
}
