#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
#include "array.h"

#include "map.h"

#include "c.h"

#include "int32.h"

#include "uint32gmp.h"

#include "uint64gmp.h"

#include "int.h"

#include "power.h"

#include "types.h"

#include "compare.h"

#include "util.h"

#include "utilold.h"

#include "addold.h"

#include "subold.h"

#include "mul.h"

#include "logicalutil.h"

#include "div.h"

#include "toom.h"

#include "euclideandivision.h"

#include "binverttab.h"

uint64_t binvert_limb_table (uint64_t n) {
return (uint64_t)binverttab[n];
}

void wmpn_redc_1(uint64_t * rp, uint64_t * up, uint64_t * mp, int32_t n,
                 uint64_t invm) {
  uint64_t cy;
  uint64_t * u;
  int32_t j, o;
  uint64_t m, o1, o2;
  uint64_t * uqt;
  cy = UINT64_C(0);
  u = up + 0;
  o = n - 1;
  if (0 <= o) {
    for (j = 0; ; ++j) {
      m = *u * invm;
      o1 = wmpn_addmul_1(u, mp, n, m);
      cy = o1;
      *u = cy;
      u = u + 1;
      if (j == o) {
        break;
      }
    }
  }
  uqt = u + -n;
  o2 = wmpn_add_n1(rp, u, u + -n, n);
  cy = o2;
  if (!(cy == UINT64_C(0))) {
    wmpn_sub_n_in_place(rp, mp, n);
    return;
  } else {
    return;
  }
}

uint64_t binvert_limb(uint64_t n) {
  uint64_t h;
  uint64_t inv;
  h = n / UINT64_C(2) % UINT64_C(128);
  inv = binvert_limb_table(h);
  inv = UINT64_C(2) * inv - inv * (inv * n);
  inv = UINT64_C(2) * inv - inv * (inv * n);
  inv = UINT64_C(2) * inv - inv * (inv * n);
  return inv;
}

static inline int32_t win_size(int32_t eb) {
  if (eb == 0) {
    return 0;
  } else {
    if (eb <= 7) {
      return 1;
    } else {
      if (eb <= 25) {
        return 2;
      } else {
        if (eb <= 81) {
          return 3;
        } else {
          if (eb <= 214) {
            return 4;
          } else {
            if (eb <= 673) {
              return 5;
            } else {
              if (eb <= 1793) {
                return 6;
              } else {
                if (eb <= 4609) {
                  return 7;
                } else {
                  if (eb <= 11521) {
                    return 8;
                  } else {
                    if (eb <= 28161) {
                      return 9;
                    } else {
                      return 10;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

static inline void redcify(uint64_t * rp, uint64_t * up, int32_t un,
                           uint64_t * mp, int32_t n) {
  uint64_t * tp;
  uint64_t * qp;
  int32_t i;
  uint64_t lzero;
  tp = alloca((uint32_t)(un + n) * sizeof(uint64_t));
  qp = alloca((uint32_t)(un + 1) * sizeof(uint64_t));
  i = 0;
  lzero = UINT64_C(0);
  while (i < n) {
    tp[i] = lzero;
    i = i + 1;
  }
  wmpn_copyi1(tp + n, up, un);
  wmpn_tdiv_qr(qp, rp, 0, tp, un + n, mp, n);
  return;
}

static inline uint64_t getbit(uint64_t * p, int32_t bi) {
  int32_t i;
  uint64_t mi, lp, lps;
  i = (bi - 1) / 64;
  mi = (uint64_t)(bi - 1) % UINT64_C(64);
  lp = p[i];
  lps = lp >> mi;
  return lps % UINT64_C(2);
}

static inline uint64_t getbits(uint64_t * p, int32_t bi, int32_t nbits) {
  int32_t bi1, i;
  uint64_t pr;
  uint64_t r;
  int32_t nbits_in_r;
  uint64_t prqt, prs;
  if (bi < nbits) {
    return *p % (UINT64_C(1) << (uint64_t)bi);
  } else {
    bi1 = bi - nbits;
    i = bi1 / 64;
    bi1 = bi1 % 64;
    pr = p[i];
    r = pr >> (uint64_t)bi1;
    nbits_in_r = 64 - bi1;
    if (nbits_in_r < nbits) {
      prqt = p[i + 1];
      prs = prqt << (uint64_t)nbits_in_r;
      r = r + prs;
    }
    return r % (UINT64_C(1) << (uint64_t)nbits);
  }
}

void wmpn_powm(uint64_t * rp, uint64_t * bp, int32_t bn, uint64_t * ep,
               int32_t en, uint64_t * mp, int32_t n, uint64_t * tp) {
  uint64_t le;
  int32_t cnt, ebi;
  int32_t windowsize;
  uint64_t m0, im, mip;
  uint64_t * pp;
  uint64_t * this_pp;
  uint32_t i, o;
  uint64_t expbits;
  int32_t ebh;
  uint64_t * ppn;
  int32_t this_windowsize;
  int32_t ebh1;
  uint64_t * ppn1;
  uint64_t * o1;
  int32_t i1;
  uint64_t lzero;
  le = ep[en - 1];
  cnt = __builtin_clzll(le);
  ebi = 64 * en - cnt;
  windowsize = win_size(ebi);
  m0 = *mp;
  im = binvert_limb(m0);
  mip = -im;
  pp = alloca(((uint32_t)n << ((uint32_t)windowsize - 1U)) * sizeof(uint64_t));
  this_pp = pp + 0;
  redcify(this_pp, bp, bn, mp, n);
  wmpn_mul_n(tp, this_pp, this_pp, n);
  wmpn_redc_1(rp, tp, mp, n, mip);
  o = (1U << ((uint32_t)windowsize - 1U)) - 1U;
  for (i = o; i >= 1U; --i) {
    wmpn_mul_n(tp, this_pp, rp, n);
    this_pp = this_pp + n;
    wmpn_redc_1(this_pp, tp, mp, n, mip);
  }
  expbits = getbits(ep, ebi, windowsize);
  if (ebi < windowsize) {
    ebi = 0;
  } else {
    ebi = ebi - windowsize;
  }
  cnt = __builtin_ctzll(expbits);
  ebi = ebi + cnt;
  expbits = expbits >> (uint64_t)cnt;
  ebh = (int32_t)(expbits >> UINT64_C(1));
  ppn = pp + n * ebh;
  wmpn_copyi1(rp, ppn, n);
  this_windowsize = windowsize;
  while (!(ebi == 0)) {
    while (getbit(ep, ebi) == UINT64_C(0)) {
      wmpn_mul_n(tp, rp, rp, n);
      wmpn_redc_1(rp, tp, mp, n, mip);
      ebi = ebi - 1;
      if (ebi == 0) {
        break;
      }
    }
    if (ebi == 0) {
      break;
    }
    expbits = getbits(ep, ebi, windowsize);
    this_windowsize = windowsize;
    if (ebi < windowsize) {
      this_windowsize = this_windowsize - (windowsize - ebi);
      ebi = 0;
    } else {
      ebi = ebi - windowsize;
    }
    cnt = __builtin_ctzll(expbits);
    this_windowsize = this_windowsize - cnt;
    ebi = ebi + cnt;
    expbits = expbits >> (uint64_t)cnt;
    while (!(this_windowsize == 0)) {
      wmpn_mul_n(tp, rp, rp, n);
      wmpn_redc_1(rp, tp, mp, n, mip);
      this_windowsize = this_windowsize - 1;
    }
    ebh1 = (int32_t)(expbits >> UINT64_C(1));
    ppn1 = pp + n * ebh1;
    wmpn_mul_n(tp, rp, ppn1, n);
    wmpn_redc_1(rp, tp, mp, n, mip);
  }
  wmpn_copyi1(tp, rp, n);
  o1 = tp + n;
  i1 = 0;
  lzero = UINT64_C(0);
  while (i1 < n) {
    o1[i1] = lzero;
    i1 = i1 + 1;
  }
  wmpn_redc_1(rp, tp, mp, n, mip);
  if (wmpn_cmp(rp, mp, n) >= 0) {
    wmpn_sub_n_in_place(rp, mp, n);
    return;
  } else {
    return;
  }
}

