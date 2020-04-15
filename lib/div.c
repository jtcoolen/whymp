#include "div.h"
#include <stdint.h>

uint64_t invert_limb(uint64_t d) {
  return div64_2by1(0xffffffffffffffffUL, 0xffffffffffffffffUL - d, d);
}
struct __div2by1_inv_result;


struct __div2by1_inv_result div2by1_inv(uint64_t uh, uint64_t ul, uint64_t d,
                                        uint64_t v) {
  uint64_t l, h, sl, c;
  struct __mul64_double_result struct_res;
  struct __add64_with_carry_result struct_res1, struct_res2;
  uint64_t sh, p;
  uint64_t qh, ql, r;
  struct __div2by1_inv_result result;
  struct_res = mul64_double(v, uh);
  l = struct_res.__field_0;
  h = struct_res.__field_1;
  struct_res1 = add64_with_carry(l, ul, UINT64_C(0));
  sl = struct_res1.__field_0;
  c = struct_res1.__field_1;
  struct_res2 = add64_with_carry(uh, h, c);
  sh = struct_res2.__field_0;
  qh = sh;
  ql = sl;
  qh = qh + UINT64_C(1);
  p = qh * d;
  r = ul - p;
  if (r > ql) {
    qh = qh - UINT64_C(1);
    r = r + d;
  }
  if (r >= d) {
    qh = qh + UINT64_C(1);
    r = r - d;
  }
  result.__field_0 = qh;
  result.__field_1 = r;
  return result;
}

uint64_t wmpn_divrem_1(uint64_t * q, uint64_t * x, int32_t sz, uint64_t y) {
  int32_t msb;
  uint64_t lx, r;
  int32_t i;
  int32_t clz;
  uint64_t ry, v, l, h, qu, rem;
  struct __lsld_ext_result struct_res;
  struct __div2by1_inv_result struct_res1, struct_res2;
  uint64_t v1, qu1, rem1;
  msb = sz - 1;
  lx = UINT64_C(0);
  i = msb;
  r = UINT64_C(0);
  clz = __builtin_clzll(y);
  if (clz > 0) {
    ry = y << (uint64_t)clz;
    v = invert_limb(ry);
    while (i >= 0) {
      lx = x[i];
      struct_res = lsld_ext(lx, (uint64_t)clz);
      l = struct_res.__field_0;
      h = struct_res.__field_1;
      struct_res1 = div2by1_inv(r + h, l, ry, v);
      qu = struct_res1.__field_0;
      rem = struct_res1.__field_1;
      r = rem;
      q[i] = qu;
      i = i - 1;
    }
    return r >> (uint64_t)clz;
  } else {
    v1 = invert_limb(y);
    while (i >= 0) {
      lx = x[i];
      struct_res2 = div2by1_inv(r, lx, y, v1);
      qu1 = struct_res2.__field_0;
      rem1 = struct_res2.__field_1;
      r = rem1;
      q[i] = qu1;
      i = i - 1;
    }
    return r;
  }
}
struct __div3by2_inv_result;


struct __div3by2_inv_result div3by2_inv(uint64_t uh, uint64_t um,
                                        uint64_t ul, uint64_t dh,
                                        uint64_t dl, uint64_t v) {
  uint64_t q1, r0, r1;
  uint64_t l, h, sl, c;
  struct __mul64_double_result struct_res;
  struct __add64_with_carry_result struct_res1, struct_res2;
  uint64_t sh, p, tl, th, il, b;
  struct __mul64_double_result struct_res3;
  struct __sub64_with_borrow_result struct_res4, struct_res5, struct_res6,
                                  struct_res7;
  uint64_t ih, bl, b2, bh, rl, c1, rh, bl1, b1;
  struct __add64_with_carry_result struct_res8, struct_res9;
  struct __sub64_with_borrow_result struct_res10, struct_res11;
  uint64_t bh1;
  struct __div3by2_inv_result result;
  q1 = UINT64_C(0);
  r0 = UINT64_C(0);
  r1 = UINT64_C(0);
  struct_res = mul64_double(v, uh);
  l = struct_res.__field_0;
  h = struct_res.__field_1;
  struct_res1 = add64_with_carry(um, l, UINT64_C(0));
  sl = struct_res1.__field_0;
  c = struct_res1.__field_1;
  struct_res2 = add64_with_carry(uh, h, c);
  sh = struct_res2.__field_0;
  q1 = sh;
  q1 = q1 + UINT64_C(1);
  p = dh * sh;
  r1 = um - p;
  struct_res3 = mul64_double(sh, dl);
  tl = struct_res3.__field_0;
  th = struct_res3.__field_1;
  struct_res4 = sub64_with_borrow(ul, tl, UINT64_C(0));
  il = struct_res4.__field_0;
  b = struct_res4.__field_1;
  struct_res5 = sub64_with_borrow(r1, th, b);
  ih = struct_res5.__field_0;
  struct_res6 = sub64_with_borrow(il, dl, UINT64_C(0));
  bl = struct_res6.__field_0;
  b2 = struct_res6.__field_1;
  struct_res7 = sub64_with_borrow(ih, dh, b2);
  bh = struct_res7.__field_0;
  r1 = bh;
  r0 = bl;
  if (r1 >= sl) {
    q1 = q1 - UINT64_C(1);
    struct_res8 = add64_with_carry(r0, dl, UINT64_C(0));
    rl = struct_res8.__field_0;
    c1 = struct_res8.__field_1;
    struct_res9 = add64_with_carry(r1, dh, c1);
    rh = struct_res9.__field_0;
    r1 = rh;
    r0 = rl;
  }
  if (__builtin_expect(r1 > dh || (r1 == dh && r0 >= dl),0)) {
    struct_res10 = sub64_with_borrow(r0, dl, UINT64_C(0));
    bl1 = struct_res10.__field_0;
    b1 = struct_res10.__field_1;
    struct_res11 = sub64_with_borrow(r1, dh, b1);
    bh1 = struct_res11.__field_0;
    q1 = q1 + UINT64_C(1);
    r1 = bh1;
    r0 = bl1;
  }
  result.__field_0 = q1;
  result.__field_1 = r0;
  result.__field_2 = r1;
  return result;
}

uint64_t reciprocal_word_3by2(uint64_t dh, uint64_t dl) {
  uint64_t v, p;
  uint64_t tl, th;
  struct __mul64_double_result struct_res;
  v = invert_limb(dh);
  p = dh * v;
  p = p + dl;
  if (p < dl) {
    if (p >= dh) {
      v = v - UINT64_C(1);
      p = p - dh;
    }
    v = v - UINT64_C(1);
    p = p - dh;
  }
  struct_res = mul64_double(v, dl);
  tl = struct_res.__field_0;
  th = struct_res.__field_1;
  p = p + th;
  if (p < th) {
    if (p > dh || (p == dh && tl >= dl)) {
      v = v - UINT64_C(1);
    }
    v = v - UINT64_C(1);
  }
  return v;
}

uint64_t div_sb_qr(uint64_t * q, uint64_t * x, int32_t sx, uint64_t * y,
                   int32_t sy) {
  uint64_t * xp;
  uint64_t * qp;
  uint64_t dh, dl, v;
  int32_t i;
  int32_t mdn;
  uint64_t ql, x1, x0;
  uint64_t * xd;
  int32_t r;
  uint64_t qh, nx0, xp0, xp1, qu, rl, rh;
  uint64_t * xd1;
  struct __div3by2_inv_result struct_res;
  uint64_t cy, cy1, cy2, c;
  xp = x + (sx - 2);
  qp = q + (sx - sy);
  dh = y[sy - 1];
  dl = y[sy - 2];
  v = reciprocal_word_3by2(dh, dl);
  i = sx - sy;
  mdn = 2 - sy;
  ql = UINT64_C(0);
  xd = xp + mdn;
  x1 = UINT64_C(0);
  x0 = UINT64_C(0);
  r = wmpn_cmp(xd, y, sy);
  if (r >= 0) {
    qh = UINT64_C(1);
  } else {
    qh = UINT64_C(0);
  }
  if (!(qh == UINT64_C(0))) {
    wmpn_sub_n_in_place(xd, y, sy);
  }
  x1 = (xp)[1];
  while (i > 0) {
    i = i - 1;
    xp = xp + -1;
    xd1 = xp + mdn;
    nx0 = (xp)[1];
    if (__builtin_expect(x1 == dh && nx0 == dl,0)) {
      ql = 0xffffffffffffffffUL;
      wmpn_submul_1(xd1, y, sy, ql);
      x1 = (xp)[1];
      qp = qp + -1;
      *qp = ql;
    } else {
      xp0 = *xp;
      xp1 = (xp)[1];
      struct_res = div3by2_inv(x1, xp1, xp0, dh, dl, v);
      qu = struct_res.__field_0;
      rl = struct_res.__field_1;
      rh = struct_res.__field_2;
      ql = qu;
      x1 = rh;
      x0 = rl;
      cy = wmpn_submul_1(xd1, y, sy - 2, ql);
      if (x0 < cy) {
        cy1 = UINT64_C(1);
      } else {
        cy1 = UINT64_C(0);
      }
      x0 = x0 - cy;
      if (x1 < cy1) {
        cy2 = UINT64_C(1);
      } else {
        cy2 = UINT64_C(0);
      }
      x1 = x1 - cy1;
      *xp = x0;
      if (__builtin_expect(!(cy2 == UINT64_C(0)),0)) {
        c = wmpn_add_n_in_place(xd1, y, sy - 1);
        x1 = x1 + (dh + c);
        ql = ql - UINT64_C(1);
        qp = qp + -1;
        *qp = ql;
      } else {
        qp = qp + -1;
        *qp = ql;
      }
    }
  }
  xp[1] = x1;
  return qh;
}

uint64_t wmpn_divrem_2(uint64_t * q, uint64_t * x, uint64_t * y, int32_t sx) {
  uint64_t * xp;
  uint64_t dh, dl;
  uint64_t rh, rl, qh, lx;
  int32_t i;
  uint64_t dinv, r0, b, r1, qu, r01, r11;
  struct __sub64_with_borrow_result struct_res, struct_res1;
  struct __div3by2_inv_result struct_res2;
  xp = x + (sx - 2);
  dh = y[1];
  dl = *y;
  rh = (xp)[1];
  rl = *xp;
  qh = UINT64_C(0);
  lx = UINT64_C(0);
  i = sx - 2;
  dinv = reciprocal_word_3by2(dh, dl);
  if (rh >= dh && (rh > dh || rl >= dl)) {
    struct_res = sub64_with_borrow(rl, dl, UINT64_C(0));
    r0 = struct_res.__field_0;
    b = struct_res.__field_1;
    struct_res1 = sub64_with_borrow(rh, dh, b);
    r1 = struct_res1.__field_0;
    rh = r1;
    rl = r0;
    qh = UINT64_C(1);
  }
  while (i > 0) {
    xp = xp + -1;
    lx = *xp;
    struct_res2 = div3by2_inv(rh, rl, lx, dh, dl, dinv);
    qu = struct_res2.__field_0;
    r01 = struct_res2.__field_1;
    r11 = struct_res2.__field_2;
    rh = r11;
    rl = r01;
    i = i - 1;
    q[i] = qu;
  }
  x[1] = rh;
  *x = rl;
  return qh;
}

void div_qr(uint64_t * q, uint64_t * r, uint64_t * x, uint64_t * y,
            uint64_t * nx, uint64_t * ny, int32_t sx, int32_t sy) {
  uint64_t lr, h, h1;
  int32_t clz, adjust, clz1;
  if (sy == 1) {
    lr = wmpn_divrem_1(q, x, sx, *y);
    *r = lr;
    return;
  } else {
    if (sy == 2) {
      clz = __builtin_clzll(y[sy - 1]);
      if (clz == 0) {
        wmpn_copyi1(nx, x, sx);
        nx[sx] = UINT64_C(0);
        wmpn_divrem_2(q, nx, y, sx + 1);
        wmpn_copyi1(r, nx, sy);
        return;
      } else {
        wmpn_lshift1(ny, y, sy, (uint64_t)clz);
        h = wmpn_lshift1(nx, x, sx, (uint64_t)clz);
        nx[sx] = h;
        wmpn_divrem_2(q, nx, ny, sx + 1);
        wmpn_rshift1(r, nx, sy, (uint64_t)clz);
        return;
      }
    } else {
      if (x[sx - 1] >= y[sy - 1]) {
        adjust = 1;
      } else {
        adjust = 0;
      }
      clz1 = __builtin_clzll(y[sy - 1]);
      if (clz1 == 0) {
        wmpn_copyi1(nx, x, sx);
        nx[sx] = UINT64_C(0);
        div_sb_qr(q, nx, sx + adjust, y, sy);
        wmpn_copyi1(r, nx, sy);
        if (adjust == 0) {
          q[sx - sy] = UINT64_C(0);
          return;
        } else {
          return;
        }
      } else {
        wmpn_lshift1(ny, y, sy, (uint64_t)clz1);
        h1 = wmpn_lshift1(nx, x, sx, (uint64_t)clz1);
        nx[sx] = h1;
        div_sb_qr(q, nx, sx + adjust, ny, sy);
        wmpn_rshift1(r, nx, sy, (uint64_t)clz1);
        if (adjust == 0) {
          q[sx - sy] = UINT64_C(0);
          return;
        } else {
          return;
        }
      }
    }
  }
}

void wmpn_tdiv_qr(uint64_t * q, uint64_t * r, int32_t qxn, uint64_t * x,
                  int32_t sx, uint64_t * y, int32_t sy) {
  uint64_t * nx;
  uint64_t * ny;
  nx = malloc(((uint32_t)sx + 1U) * sizeof(uint64_t));
  assert (nx);
  ny = malloc((uint32_t)sy * sizeof(uint64_t));
  assert (ny);
  div_qr(q, r, x, y, nx, ny, sx, sy);
  free(nx);
  free(ny);
  return;
}

void div_qr_in_place(uint64_t * q, uint64_t * x, uint64_t * y, uint64_t * nx,
                     uint64_t * ny, int32_t sx, int32_t sy) {
  uint64_t lr, h, h1;
  int32_t clz, adjust, clz1;
  if (sy == 1) {
    lr = wmpn_divrem_1(q, x, sx, *y);
    *x = lr;
    return;
  } else {
    if (sy == 2) {
      clz = __builtin_clzll(y[sy - 1]);
      if (clz == 0) {
        wmpn_copyi1(nx, x, sx);
        nx[sx] = UINT64_C(0);
        wmpn_divrem_2(q, nx, y, sx + 1);
        wmpn_copyi1(x, nx, sy);
        return;
      } else {
        wmpn_lshift1(ny, y, sy, (uint64_t)clz);
        h = wmpn_lshift1(nx, x, sx, (uint64_t)clz);
        nx[sx] = h;
        wmpn_divrem_2(q, nx, ny, sx + 1);
        wmpn_rshift1(x, nx, sy, (uint64_t)clz);
        return;
      }
    } else {
      if (x[sx - 1] >= y[sy - 1]) {
        adjust = 1;
      } else {
        adjust = 0;
      }
      clz1 = __builtin_clzll(y[sy - 1]);
      if (clz1 == 0) {
        wmpn_copyi1(nx, x, sx);
        nx[sx] = UINT64_C(0);
        div_sb_qr(q, nx, sx + adjust, y, sy);
        wmpn_copyi1(x, nx, sy);
        if (adjust == 0) {
          q[sx - sy] = UINT64_C(0);
          return;
        } else {
          return;
        }
      } else {
        wmpn_lshift1(ny, y, sy, (uint64_t)clz1);
        h1 = wmpn_lshift1(nx, x, sx, (uint64_t)clz1);
        nx[sx] = h1;
        div_sb_qr(q, nx, sx + adjust, ny, sy);
        wmpn_rshift1(x, nx, sy, (uint64_t)clz1);
        if (adjust == 0) {
          q[sx - sy] = UINT64_C(0);
          return;
        } else {
          return;
        }
      }
    }
  }
}

void wmpn_tdiv_qr_in_place(uint64_t * q, int32_t qxn, uint64_t * x,
                           int32_t sx, uint64_t * y, int32_t sy) {
  uint64_t * nx;
  uint64_t * ny;
  nx = malloc(((uint32_t)sx + 1U) * sizeof(uint64_t));
  assert (nx);
  ny = malloc((uint32_t)sy * sizeof(uint64_t));
  assert (ny);
  div_qr_in_place(q, x, y, nx, ny, sx, sy);
  free(nx);
  free(ny);
  return;
}
