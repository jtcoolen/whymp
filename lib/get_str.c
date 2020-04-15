#include "get_str.h"
#include <stdint.h>

uint32_t wmpn_get_str_bits(unsigned char * sp, uint32_t bits, uint64_t * up,
                           int32_t un) {
  uint64_t um, sb, b;
  int32_t e, sn;
  int32_t i, j;
  uint64_t shift, digit;
  uint64_t lu, luqt, high, sj;
  um = up[un - 1];
  sb = wmpn_limb_size_in_base_2(um);
  e = 64 * (un - 1) + (int32_t)sb + (int32_t)bits - 1;
  sn = e / (int32_t)bits;
  b = UINT64_C(1) << (uint64_t)bits;
  i = 0;
  j = sn;
  shift = UINT64_C(0);
  while (j > 0) {
    j = j - 1;
    lu = up[i];
    digit = lu >> shift;
    shift = shift + (uint64_t)bits;
    if (shift >= UINT64_C(64)) {
      i = i + 1;
      if (i < un) {
        shift = shift - UINT64_C(64);
        luqt = up[i];
        high = luqt << ((uint64_t)bits - shift);
        digit = digit + high;
      }
    }
    sj = digit % b;
    sp[j] = (unsigned char)sj;
  }
  return (uint32_t)sn;
}

uint32_t wmpn_limb_get_str(unsigned char * sp, uint64_t * w, uint64_t d1,
                           uint64_t di, uint64_t shift) {
  int32_t i;
  uint64_t h, l, q, r;
  struct __div2by1_inv_result struct_res;
  i = 0;
  while (*w > UINT64_C(0)) {
    h = *w >> (UINT64_C(64) - shift);
    l = *w << shift;
    struct_res = div2by1_inv(h, l, d1, di);
    q = struct_res.__field_0;
    r = struct_res.__field_1;
    sp[i] = (unsigned char)(r >> shift);
    *w = q;
    i = i + 1;
  }
  return (uint32_t)i;
}

uint32_t wmpn_get_str_other(unsigned char * sp, int32_t base,
                            struct wmpn_base_info info, uint64_t * up,
                            int32_t un) {
  uint64_t shift, d1, di;
  int32_t sn, n;
  uint64_t * tp;
  uint64_t w;
  uint64_t o;
  unsigned char * spn;
  uint32_t sdone;
  uint32_t o1;
  uint64_t lu;
  unsigned char * spn1;
  uint32_t sdone1;
  int32_t i;
  unsigned char t;
  shift = (uint64_t)__builtin_clzll((uint64_t)base);
  d1 = (uint64_t)base << shift;
  di = invert_limb(d1);
  sn = 0;
  n = un;
  if (n > 1) {
    tp = alloca((uint32_t)n * sizeof(uint64_t));
    while (n > 1) {
      o = wmpn_divrem_1(tp, up, n, info.bb);
      w = o;
      wmpn_copyi1(up, tp, n);
      n = n - (up[n - 1] == UINT64_C(0));
      spn = sp + sn;
      o1 = wmpn_limb_get_str(spn, &w, d1, di, shift);
      sdone = o1;
      sn = sn + (int32_t)sdone;
      while (sdone < info.exp) {
        sp[sn] = 0;
        sn = sn + 1;
        sdone = sdone + 1U;
      }
    }
  }
  lu = *up;
  spn1 = sp + sn;
  sdone1 = wmpn_limb_get_str(spn1, &lu, d1, di, shift);
  sn = sn + (int32_t)sdone1;
  i = 0;
  while (2 * i + 1 < sn) {
    t = sp[i];
    sp[i] = sp[sn - i - 1];
    sp[sn - i - 1] = t;
    i = i + 1;
  }
  return (uint32_t)sn;
}

uint32_t wmpn_get_str(unsigned char * sp, int32_t base, uint64_t * up,
                      int32_t un) {
  uint32_t bits;
  struct wmpn_base_info info;
  bits = wmpn_base_power_of_two_p((uint64_t)base);
  if (!(bits == 0U)) {
    return wmpn_get_str_bits(sp, bits, up, un);
  } else {
    info = wmpn_get_base_info((uint64_t)base);
    return wmpn_get_str_other(sp, base, info, up, un);
  }
}
