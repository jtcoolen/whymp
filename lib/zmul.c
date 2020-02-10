#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
#include "int.h"

#include "power.h"

#include "map.h"

#include "c.h"

#include "util.h"

#include "utilold.h"

#include "alias.h"

#include "compare.h"

#include "uint64gmp.h"

#include "add.h"

#include "sub.h"

#include "mul.h"

#include "toom.h"

#include "abs.h"

#include "z.h"

#include "zutil.h"

#include "int64.h"

#include "set.h"

#include "bool.h"

void wmpz_mul(wmpz_ptr w, wmpz_ptr u, wmpz_ptr v) {
  wmpz_ptr u1, v1;
  int32_t usize, vsize;
  int32_t sign_product, z;
  wmpz_ptr z1;
  int uw, vw;
  uint64_t * vp;
  uint64_t v0, cy;
  uint64_t * wp;
  uint64_t * up;
  uint64_t cy1;
  int32_t wsize;
  int freew;
  int32_t wsize1;
  wmpz_ptr uqt, vqt, wqt;
  wmpz_ptr o;
  uint64_t * wpqt;
  uint64_t * wp1;
  uint64_t * up1;
  wmpz_ptr o1;
  uint64_t * wp2;
  uint64_t * vp1;
  wmpz_ptr o2;
  uint64_t * upqt;
  uint64_t * vpqt;
  uint64_t * wpqt1;
  uint64_t cy2;
  uint64_t * wp3;
  u1 = u;
  v1 = v;
  usize = SIZ(u1);
  vsize = SIZ(v1);
  sign_product = usize ^ vsize;
  usize = usize >= 0 ? usize : -usize;
  vsize = vsize >= 0 ? vsize : -vsize;
  if (usize < vsize) {
    z1 = u1;
    u1 = v1;
    v1 = z1;
    z = usize;
    usize = vsize;
    vsize = z;
  }
  if (vsize == 0) {
    SIZ(w) = 0;
    return;
  }
  uw = u1 == w;
  vw = v1 == w;
  if (vsize == 1) {
    vp = PTR(v1);
    v0 = *vp;
    (void)(v1);
    wp = wmpz_realloc(w, usize + 1);
    if (uw) {
      cy = wmpn_mul_1_in_place(wp, usize, v0);
    } else {
      up = PTR(u1);
      cy1 = wmpn_mul_1(wp, up, usize, v0);
      (void)(u1);
      cy = cy1;
    }
    wp[usize] = cy;
    usize = usize + (!(cy == UINT64_C(0)) ? 1 : 0);
    if (sign_product >= 0) {
      wsize = usize;
    } else {
      wsize = -usize;
    }
    SIZ(w) = wsize;
    (void)(w);
    return;
  }
  freew = 0;
  wsize1 = usize + vsize;
  uqt = u1;
  vqt = v1;
  wqt = w;
  if (ALLOC(w) < wsize1) {
    freew = 1;
    o = __wmpz_init();
    wqt = o;
    wpqt = wmpz_realloc(wqt, wsize1);
    (void)(wqt);
  } else {
    if (uw) {
      wp1 = PTR(w);
      up1 = alloca((uint32_t)usize * sizeof(uint64_t));
      o1 = __wmpz_init();
      uqt = o1;
      ALLOC(uqt) = usize;
      wmpn_copyi1(up1, wp1, usize);
      PTR(uqt) = up1;
      SIZ(uqt) = usize;
      (void)(uqt);
      if (vw) {
        vqt = uqt;
      }
      (void)(w);
    } else {
      if (vw) {
        wp2 = PTR(w);
        vp1 = alloca((uint32_t)vsize * sizeof(uint64_t));
        o2 = __wmpz_init();
        vqt = o2;
        ALLOC(vqt) = vsize;
        wmpn_copyi1(vp1, wp2, vsize);
        PTR(vqt) = vp1;
        SIZ(vqt) = vsize;
        (void)(vqt);
        (void)(w);
      }
    }
  }
  upqt = PTR(uqt);
  vpqt = PTR(vqt);
  wpqt1 = PTR(wqt);
  cy2 = wmpn_mul(wpqt1, upqt, usize, vpqt, vsize);
  (void)(uqt);
  (void)(vqt);
  if (freew) {
    wp3 = PTR(w);
    free(wp3);
  }
  wsize1 = wsize1 - (cy2 == UINT64_C(0) ? 1 : 0);
  wsize1 = sign_product < 0 ? -wsize1 : wsize1;
  PTR(w) = wpqt1;
  SIZ(w) = wsize1;
  (void)(w);
  return;
}

void wmpz_mul_si(wmpz_ptr prod, wmpz_ptr mult, int64_t small_mult) {
  int32_t sign_product;
  int32_t size;
  uint64_t sml, cy;
  uint64_t * pp;
  uint64_t * mp;
  uint64_t cy1;
  sign_product = SIZ(mult);
  if (sign_product == 0 || small_mult == INT64_C(0)) {
    SIZ(prod) = 0;
    return;
  }
  size = sign_product >= 0 ? sign_product : -sign_product;
  sml = abs_cast(small_mult);
  pp = wmpz_realloc(prod, size + 1);
  if (prod == mult) {
    cy = wmpn_mul_1_in_place(pp, size, sml);
  } else {
    mp = PTR(mult);
    cy1 = wmpn_mul_1(pp, mp, size, sml);
    (void)(mult);
    cy = cy1;
  }
  pp[size] = cy;
  size = size + (!(cy == UINT64_C(0)) ? 1 : 0);
  size = (sign_product < 0) ^ (small_mult < INT64_C(0)) ? -size : size;
  SIZ(prod) = size;
  (void)(prod);
  return;
}

void wmpz_mul_ui(wmpz_ptr prod, wmpz_ptr mult, uint64_t small_mult) {
  int32_t sign_product;
  int32_t size;
  uint64_t * pp;
  uint64_t cy, cy1;
  uint64_t * mp;
  sign_product = SIZ(mult);
  if (sign_product == 0 || small_mult == UINT64_C(0)) {
    SIZ(prod) = 0;
    return;
  }
  size = sign_product >= 0 ? sign_product : -sign_product;
  pp = wmpz_realloc(prod, size + 1);
  if (prod == mult) {
    cy = wmpn_mul_1_in_place(pp, size, small_mult);
  } else {
    mp = PTR(mult);
    cy1 = wmpn_mul_1(pp, mp, size, small_mult);
    (void)(mult);
    cy = cy1;
  }
  pp[size] = cy;
  size = size + (!(cy == UINT64_C(0)) ? 1 : 0);
  size = sign_product < 0 ? -size : size;
  SIZ(prod) = size;
  (void)(prod);
  return;
}

