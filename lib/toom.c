#include "toom.h"
#include <stdint.h>

int32_t toom22_threshold = 29;

void wmpn_toom22_mul(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                     int32_t sy, uint64_t * scratch);

void wmpn_toom22_mul_rec(uint64_t * r, uint64_t * x, int32_t sx,
                         uint64_t * y, int32_t sy, uint64_t * scratch);

void wmpn_toom22_mul_n_rec(uint64_t * r, uint64_t * x, uint64_t * y,
                           uint64_t * scratch, int32_t sz);

void wmpn_toom32_mul(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                     int32_t sy, uint64_t * scratch);

uint64_t wmpn_mul(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy);

void wmpn_toom22_mul(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                     int32_t sy, uint64_t * scratch) {
  int32_t s, n, t;
  uint64_t * x0;
  uint64_t * x1;
  uint64_t * y0;
  uint64_t * y1;
  uint64_t * rqt;
  uint64_t * ro;
  uint64_t * scratchqt;
  uint64_t * s_out;
  uint64_t * vinf;
  uint64_t * xsm1;
  uint64_t * ysm1;
  int vm1_neg;
  uint64_t b, lx;
  uint64_t * y0t;
  int c0, c1;
  uint64_t * ysm1t;
  uint64_t * v0;
  uint64_t * v0n;
  uint64_t * vinfn;
  uint64_t cy;
  uint64_t o, c, cy2, cqt, cqtqt, b1;
  uint64_t * vinf0;
  uint64_t * vinfn1;
  s = sx / 2;
  n = sx - s;
  t = sy - n;
  x0 = x;
  x1 = x + n;
  y0 = y;
  y1 = y + n;
  rqt = r - 0;
  ro = r + (sx + sy);
  scratchqt = scratch - 0;
  s_out = scratch + (n + n);
  vinf = r + (n + n);
  xsm1 = r;
  ysm1 = r + n;
  vm1_neg = 0;
  if (s == n) {
    if (wmpn_cmp(x0, x1, n) < 0) {
      wmpn_sub_n1(xsm1, x1, x0, n);
      vm1_neg = 1;
    } else {
      wmpn_sub_n1(xsm1, x0, x1, n);
    }
  } else {
    if (x0[s] == UINT64_C(0) && wmpn_cmp(x0, x1, s) < 0) {
      wmpn_sub_n1(xsm1, x1, x0, s);
      xsm1[s] = UINT64_C(0);
      vm1_neg = 1;
    } else {
      b = wmpn_sub_n1(xsm1, x0, x1, s);
      lx = x0[s];
      xsm1[s] = lx - b;
    }
  }
  if (t == n) {
    if (wmpn_cmp(y0, y1, n) < 0) {
      wmpn_sub_n1(ysm1, y1, y0, n);
      vm1_neg = !(vm1_neg);
    } else {
      wmpn_sub_n1(ysm1, y0, y1, n);
    }
  } else {
    y0t = y0 + t;
    c0 = wmpn_zero_p(y0t, n - t) == 1;
    c1 = wmpn_cmp(y0, y1, t) < 0;
    if (c0 && c1) {
      wmpn_sub_n1(ysm1, y1, y0, t);
      ysm1t = ysm1 + t;
      wmpn_zero(ysm1t, n - t);
      vm1_neg = !(vm1_neg);
    } else {
      wmpn_sub1(ysm1, y0, n, y1, t);
    }
  }
  wmpn_toom22_mul_n_rec(scratch, xsm1, ysm1, s_out, n);
  IGNORE2(r, ysm1);
  v0 = r;
  if (s > t) {
    wmpn_toom22_mul_rec(vinf, x1, s, y1, t, s_out);
  } else {
    wmpn_toom22_mul_n_rec(vinf, x1, y1, s_out, s);
  }
  wmpn_toom22_mul_n_rec(v0, x0, y0, s_out, n);
  v0n = v0 + n;
  vinfn = vinf + n;
  o = wmpn_add_n_in_place(vinf, v0n, n);
  cy = o;
  c = wmpn_add_n1(v0n, vinf, v0, n);
  cy2 = c + cy;
  cqt = wmpn_add_in_place(vinf, n, vinfn, s + t - n);
  cy = cy + cqt;
  IGNORE2(v0n, vinf);
  if (vm1_neg) {
    cqtqt = wmpn_add_n_in_place(v0n, scratch, n + n);
    cy = cy + cqtqt;
  } else {
    b1 = wmpn_sub_n_in_place(v0n, scratch, n + n);
    cy = cy - b1;
  }
  IGNORE2(r, v0n);
  IGNORE2(r, vinfn);
  IGNORE2(scratch, s_out);
  vinf0 = r + (n + n);
  wmpn_incr(vinf0, cy2);
  vinfn1 = r + 3 * n;
  if (cy <= UINT64_C(3)) {
    wmpn_incr(vinfn1, cy);
  } else {
    wmpn_decr_1(vinfn1);
  }
  IGNORE2(r, ro);
  IGNORE2(rqt, r);
  IGNORE2(scratchqt, scratch);
  return;
}

void wmpn_toom22_mul_rec(uint64_t * r, uint64_t * x, int32_t sx,
                         uint64_t * y, int32_t sy, uint64_t * scratch) {
  if (sy <= toom22_threshold) {
    wmpn_mul_basecase(r, x, sx, y, sy);
    return;
  } else {
    if (4 * sx < 5 * sy) {
      wmpn_toom22_mul(r, x, sx, y, sy, scratch);
      return;
    } else {
      wmpn_toom32_mul(r, x, sx, y, sy, scratch);
      return;
    }
  }
}

void wmpn_toom22_mul_n_rec(uint64_t * r, uint64_t * x, uint64_t * y,
                           uint64_t * scratch, int32_t sz) {
  if (sz <= toom22_threshold) {
    wmpn_mul_basecase(r, x, sz, y, sz);
    return;
  } else {
    wmpn_toom22_mul(r, x, sz, y, sz, scratch);
    return;
  }
}

void wmpn_toom32_mul(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                     int32_t sy, uint64_t * scratch) {
  int32_t n, s, t;
  uint64_t * x0;
  uint64_t * x1;
  uint64_t * x2;
  uint64_t * y0;
  uint64_t * y1;
  uint64_t * rol;
  uint64_t * ror;
  uint64_t * sol;
  uint64_t * sor;
  uint64_t * xp1;
  uint64_t * yp1;
  uint64_t * xm1;
  uint64_t * ym1;
  uint64_t * v1;
  uint64_t * vm1;
  uint64_t xp1_hi, yp1_hi, hi;
  int vm1_neg;
  uint64_t o, b, c, o1, o2;
  int32_t cmp, cmp1;
  uint64_t * y0t;
  int c0, c1;
  int32_t cmp2;
  uint64_t * ym1t;
  uint64_t cy;
  uint64_t * sn;
  uint64_t c2, c3;
  uint64_t * sn1;
  uint64_t * sn2;
  uint64_t c4, c5, b1, r1;
  uint64_t * vm1n;
  struct __sub64_with_borrow_result struct_res;
  uint64_t c6, r2;
  struct __add64_with_carry_result struct_res1;
  int32_t s1;
  uint64_t * vy0;
  uint64_t * vy1;
  uint64_t * vy2;
  uint64_t t02, c7, c11, c21, c31, b11, b2, b3;
  uint64_t * vm1n1;
  uint64_t * r3n;
  uint64_t * r1n;
  uint64_t * r4n;
  uint64_t * r2n;
  uint64_t bo1, ly2;
  uint64_t bo;
  int64_t h;
  uint64_t bo2, bo2qt, bo3, bo3qt, c8;
  int32_t rs;
  uint64_t * r2n1;
  uint64_t b4;
  n = 1 + (2 * sx >= 3 * sy ? (sx - 1) / 3 : (sy - 1) / 2);
  s = sx - 2 * n;
  t = sy - n;
  x0 = x;
  x1 = x + n;
  x2 = x1 + n;
  y0 = y;
  y1 = y + n;
  rol = r - 0;
  ror = r + (sx + sy);
  sol = scratch - 0;
  sor = scratch + (n + n + 1);
  xp1 = r;
  yp1 = r + n;
  xm1 = yp1 + n;
  ym1 = xm1 + n;
  v1 = scratch;
  vm1 = r;
  xp1_hi = UINT64_C(0);
  yp1_hi = UINT64_C(0);
  hi = UINT64_C(0);
  vm1_neg = 0;
  o = wmpn_add1(xp1, x0, n, x2, s);
  xp1_hi = o;
  cmp = wmpn_cmp(xp1, x1, n);
  if (xp1_hi == UINT64_C(0) && cmp < 0) {
    wmpn_sub_n1(xm1, x1, xp1, n);
    hi = UINT64_C(0);
    vm1_neg = 1;
  } else {
    b = wmpn_sub_n1(xm1, xp1, x1, n);
    hi = xp1_hi - b;
  }
  c = wmpn_add_n_in_place(xp1, x1, n);
  xp1_hi = xp1_hi + c;
  if (t == n) {
    o1 = wmpn_add_n1(yp1, y0, y1, n);
    yp1_hi = o1;
    cmp1 = wmpn_cmp(y0, y1, n);
    if (cmp1 < 0) {
      wmpn_sub_n1(ym1, y1, y0, n);
      vm1_neg = !(vm1_neg);
    } else {
      wmpn_sub_n1(ym1, y0, y1, n);
    }
  } else {
    o2 = wmpn_add1(yp1, y0, n, y1, t);
    yp1_hi = o2;
    y0t = y0 + t;
    c0 = wmpn_zero_p(y0t, n - t) == 1;
    cmp2 = wmpn_cmp(y0, y1, t);
    c1 = cmp2 < 0;
    if (c0 && c1) {
      wmpn_sub_n1(ym1, y1, y0, t);
      ym1t = ym1 + t;
      wmpn_zero(ym1t, n - t);
      vm1_neg = !(vm1_neg);
    } else {
      wmpn_sub1(ym1, y0, n, y1, t);
    }
  }
  wmpn_toom22_mul_n_rec(v1, xp1, yp1, sor, n);
  cy = UINT64_C(0);
  if (xp1_hi == UINT64_C(1)) {
    sn = scratch + n;
    c2 = wmpn_add_n_in_place(sn, yp1, n);
    cy = c2;
  } else {
    if (xp1_hi == UINT64_C(2)) {
      sn1 = scratch + n;
      c3 = wmpn_addmul_1(sn1, yp1, n, UINT64_C(2));
      cy = c3;
    }
  }
  if (!(yp1_hi == UINT64_C(0))) {
    sn2 = scratch + n;
    c4 = wmpn_add_n_in_place(sn2, xp1, n);
    cy = xp1_hi * yp1_hi + c4 + cy;
  }
  IGNORE2(vm1, yp1);
  wmpn_toom22_mul_n_rec(vm1, xm1, ym1, sor, n);
  if (!(hi == UINT64_C(0))) {
    vm1n = vm1 + n;
    c5 = wmpn_add_n_in_place(vm1n, ym1, n);
    IGNORE2(vm1, vm1n);
    hi = c5;
  }
  if (vm1_neg) {
    b1 = wmpn_sub_n_in_place(scratch, vm1, 2 * n);
    struct_res = sub64_with_borrow(cy, hi, b1);
    r1 = struct_res.__field_0;
    scratch[2 * n] = r1;
  } else {
    c6 = wmpn_add_n_in_place(scratch, vm1, 2 * n);
    struct_res1 = add64_with_carry(cy, hi, c6);
    r2 = struct_res1.__field_0;
    scratch[2 * n] = r2;
  }
  s1 = 2 * n + 1;
  wmpn_rshift(scratch, scratch, s1, UINT64_C(1));
  IGNORE2(xm1, ym1);
  vy0 = scratch;
  vy1 = xm1;
  vy2 = scratch + n;
  t02 = vy2[n];
  c7 = wmpn_add_n1(vy1, vy0, vy2, n);
  wmpn_incr(vy2, c7 + t02);
  vm1n1 = vm1 + n;
  if (vm1_neg) {
    c11 = wmpn_add_n_in_place(scratch, vm1, n);
    c21 = wmpn_add_n_in_place(vy1, vm1n1, n);
    hi = hi + c21;
    c31 = wmpn_add_1_in_place(vy1, n, c11);
    hi = hi + c31;
    wmpn_incr(vy2, hi);
  } else {
    b11 = wmpn_sub_n_in_place(scratch, vm1, n);
    b2 = wmpn_sub_n_in_place(vy1, vm1n1, n);
    hi = hi + b2;
    b3 = wmpn_sub_1_in_place(vy1, n, b11);
    hi = hi + b3;
    wmpn_decr(vy2, hi);
  }
  wmpn_toom22_mul_n_rec(r, x, y, sor, n);
  r3n = xm1 + n;
  if (s > t) {
    wmpn_mul(r3n, x2, s, y1, t);
  } else {
    wmpn_mul(r3n, y1, t, x2, s);
  }
  r1n = r + n;
  r4n = r3n + n;
  r2n = xm1;
  bo1 = wmpn_sub_n_in_place(r1n, r3n, n);
  bo = bo1;
  ly2 = vy2[n];
  h = (int64_t)(ly2 + bo1);
  bo2 = wmpn_sub_n_in_place(r2n, r, n);
  bo2qt = wmpn_sub_1_in_place(r2n, n, bo);
  bo = bo2 + bo2qt;
  bo3 = wmpn_sub_n1(r3n, vy2, r1n, n);
  bo3qt = wmpn_sub_1_in_place(r3n, n, bo);
  bo = bo3 + bo3qt;
  h = h - (int64_t)bo;
  IGNORE2(r2n, r3n);
  IGNORE2(r1n, r2n);
  c8 = wmpn_add_in_place(r1n, 3 * n, scratch, n);
  h = h + (int64_t)c8;
  IGNORE2(r, r1n);
  rs = s + t - n;
  if (__builtin_expect(s + t > n,1)) {
    r2n1 = r + 2 * n;
    b4 = wmpn_sub_in_place(r2n1, 2 * n, r4n, rs);
    h = h - (int64_t)b4;
    if (h < INT64_C(0)) {
      wmpn_decr(r4n, (uint64_t)-(h));
    } else {
      wmpn_incr(r4n, (uint64_t)h);
    }
  }
  IGNORE2(r, r4n);
  IGNORE2(scratch, vy2);
  IGNORE2(scratch, sor);
  IGNORE2(sol, scratch);
  IGNORE2(r, ror);
  IGNORE2(rol, r);
  return;
}

uint64_t wmpn_mul(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy) {
  uint64_t * scratch;
  uint64_t * rol;
  uint64_t * ror;
  int32_t un;
  int32_t su;
  uint64_t * ws;
  uint64_t * up;
  uint64_t * rp;
  uint64_t cy;
  uint64_t * rpn;
  uint64_t * wsy;
  uint64_t cy1;
  uint64_t * rpn1;
  uint64_t * wsy1;
  if (sy <= toom22_threshold) {
    wmpn_mul_basecase(r, x, sx, y, sy);
  } else {
    scratch = alloca((uint32_t)(5 * sy + 128) * sizeof(uint64_t));
    rol = r - 0;
    ror = r + (sx + sy);
    if (2 * sx >= 5 * sy) {
      un = sx;
      su = 3 * sy / 2;
      ws = alloca((uint32_t)(4 * sy) * sizeof(uint64_t));
      wmpn_toom32_mul(r, x, su, y, sy, scratch);
      un = un - su;
      up = x + su;
      rp = r + su;
      while (un >= 2 * sy) {
        wmpn_toom32_mul(ws, up, su, y, sy, scratch);
        cy = wmpn_add_n_in_place(rp, ws, sy);
        rpn = rp + sy;
        wsy = ws + sy;
        wmpn_copyi1(rpn, wsy, su);
        wmpn_incr(rpn, cy);
        un = un - su;
        up = up + su;
        rp = rp + su;
      }
      if (sy <= un) {
        if (4 * un < 5 * sy) {
          wmpn_toom22_mul(ws, up, un, y, sy, scratch);
        } else {
          wmpn_toom32_mul(ws, up, un, y, sy, scratch);
        }
      } else {
        wmpn_mul(ws, y, sy, up, un);
      }
      cy1 = wmpn_add_n_in_place(rp, ws, sy);
      rpn1 = rp + sy;
      wsy1 = ws + sy;
      wmpn_copyi1(rpn1, wsy1, un);
      wmpn_incr(rpn1, cy1);
      (void)ws;
    } else {
      if (4 * sx < 5 * sy) {
        wmpn_toom22_mul(r, x, sx, y, sy, scratch);
      } else {
        wmpn_toom32_mul(r, x, sx, y, sy, scratch);
      }
    }
    (void)scratch;
    IGNORE2(r, ror);
    IGNORE2(rol, r);
  }
  return r[sx + sy - 1];
}

void wmpn_mul_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz) {
  uint64_t * ws;
  if (sz <= toom22_threshold) {
    wmpn_mul_basecase(r, x, sz, y, sz);
    return;
  } else {
    ws = alloca((uint32_t)(2 * (sz + 64)) * sizeof(uint64_t));
    wmpn_toom22_mul(r, x, sz, y, sz, ws);
    return;
  }
}
