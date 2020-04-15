#include "set_str.h"
#include <stdint.h>

int32_t wmpn_set_str_bits(uint64_t * rp, unsigned char * sp, uint32_t sn,
                          uint32_t bits) {
  int32_t rn, j;
  uint32_t shift;
  uint64_t sj, rlow, slow, nr, shigh;
  rn = 0;
  shift = 0U;
  j = (int32_t)sn;
  while (j > 0) {
    j = j - 1;
    sj = (uint64_t)sp[j];
    if (shift == 0U) {
      rp[rn] = sj;
      rn = rn + 1;
      shift = bits;
    } else {
      rlow = rp[rn - 1];
      slow = sj << (uint64_t)shift;
      nr = rlow + slow;
      rp[rn - 1] = nr;
      shift = shift + bits;
      if (shift >= 64U) {
        shift = shift - 64U;
        if (shift > 0U) {
          shigh = sj >> (uint64_t)(bits - shift);
          rp[rn] = shigh;
          rn = rn + 1;
        }
      }
    }
  }
  normalize(rp, &rn);
  return rn;
}

int32_t wmpn_set_str_other(uint64_t * rp, unsigned char * sp, uint32_t sn,
                           uint64_t b, struct wmpn_base_info info) {
  uint32_t k;
  uint64_t w;
  int32_t j;
  uint32_t o;
  uint64_t sj;
  int32_t rn;
  uint32_t k1, o1;
  uint64_t sj1, o2, cy1;
  uint64_t cy;
  k = 1U + (sn - 1U) % info.exp;
  w = (uint64_t)*sp;
  j = 1;
  while (1) {
    k = k - 1U;
    o = k;
    if (!(o > 0U)) {
      break;
    }
    sj = (uint64_t)sp[j];
    w = w * b + sj;
    j = j + 1;
  }
  *rp = w;
  rn = 1;
  while (j < (int32_t)sn) {
    w = (uint64_t)sp[j];
    j = j + 1;
    o1 = info.exp - 1U;
    if (1U <= o1) {
      for (k1 = 1U; ; ++k1) {
        sj1 = (uint64_t)sp[j];
        w = w * b + sj1;
        j = j + 1;
        if (k1 == o1) {
          break;
        }
      }
    }
    o2 = wmpn_mul_1_in_place(rp, rn, info.bb);
    cy = o2;
    cy1 = wmpn_add_1_in_place(rp, rn, w);
    cy = cy + cy1;
    if (cy > UINT64_C(0)) {
      rp[rn] = cy;
      rn = rn + 1;
    }
  }
  return rn;
}

int32_t wmpn_set_str(uint64_t * rp, unsigned char * sp, uint32_t sn,
                     int32_t base) {
  uint32_t bits;
  struct wmpn_base_info info;
  if (sn == 0U) {
    return 0;
  }
  bits = wmpn_base_power_of_two_p((uint64_t)base);
  if (!(bits == 0U)) {
    return wmpn_set_str_bits(rp, sp, sn, bits);
  } else {
    info = wmpn_get_base_info((uint64_t)base);
    return wmpn_set_str_other(rp, sp, sn, (uint64_t)base, info);
  }
}
