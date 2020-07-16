#include "sqrt.h"
#include <stdint.h>

uint64_t wmpn_sqrtrem2(uint64_t * sp, uint64_t * rp, uint64_t * np) {
  uint64_t np0, o, prec, nph, rq, u, uh;
  uint64_t sp0, rp0, q;
  int64_t cc;
  uint64_t npl, ul, q2;
  np0 = *np;
  o = sqrt1(rp, np[1]);
  sp0 = o;
  rp0 = *rp;
  prec = 64 / UINT64_C(2);
  nph = np0 >> (prec + UINT64_C(1));
  rp0 = (rp0 << (prec - UINT64_C(1))) + nph;
  q = rp0 / sp0;
  rq = q >> prec;
  q = q - rq;
  u = rp0 - q * sp0;
  sp0 = (sp0 << prec) + q;
  uh = u >> (prec - UINT64_C(1));
  cc = (int64_t)uh;
  npl = np0 % (UINT64_C(1) << (prec + UINT64_C(1)));
  ul = u << (prec + UINT64_C(1));
  rp0 = ul + npl;
  q2 = q * q;
  if (rp0 < q2) {
    cc = cc - INT64_C(1);
  }
  rp0 = rp0 - q2;
  if (cc < INT64_C(0)) {
    rp0 = rp0 + sp0;
    if (rp0 < sp0) {
      cc = cc + INT64_C(1);
    }
    sp0 = sp0 - UINT64_C(1);
    rp0 = rp0 + sp0;
    if (rp0 < sp0) {
      cc = cc + INT64_C(1);
    }
  }
  *rp = rp0;
  *sp = sp0;
  return (uint64_t)cc;
}

uint64_t wmpn_dc_sqrtrem(uint64_t * sp, uint64_t * np, int32_t n,
                         uint64_t * scratch);

uint64_t wmpn_dc_sqrtrem(uint64_t * sp, uint64_t * np, int32_t n,
                         uint64_t * scratch) {
  uint64_t r;
  int32_t l, h;
  uint64_t * npqt;
  uint64_t * spl;
  uint64_t q;
  uint64_t o, sl, sh;
  uint64_t * npl;
  int64_t c;
  uint64_t * nr;
  uint64_t * nx;
  struct __open_shift_sep_result struct_res;
  uint64_t res, st, ql, qh, cqt;
  uint64_t * npn;
  int32_t ll;
  uint64_t bo, b, bo1, o1, cqt1;
  uint64_t * nll;
  int64_t o2, o3;
  uint64_t o4, bo2;
  if (n == 1) {
    r = wmpn_sqrtrem2(sp, scratch, np);
    *np = *scratch;
    return r;
  } else {
    l = n / 2;
    h = n - l;
    npqt = np + (l + l);
    spl = sp + l;
    o = wmpn_dc_sqrtrem(spl, npqt, h, scratch);
    q = o;
    if (!(q == UINT64_C(0))) {
      wmpn_sub_n_in_place(npqt, spl, h);
    }
    IGNORE2(np, npqt);
    npl = np + l;
    wmpn_tdiv_qr_in_place(scratch, 0, npl, n, spl, h);
    sl = scratch[l];
    q = q + sl;
    sh = *scratch;
    c = (int64_t)(sh % UINT64_C(2));
    struct_res = open_shift_sep(sp, scratch);
    nr = struct_res.__field_0;
    nx = struct_res.__field_1;
    res = wmpn_rshift(nr, nx, l, UINT64_C(1));
    IGNORE2(sp, scratch);
    res;
    st = sp[l - 1];
    ql = q << (64 - UINT64_C(1));
    qh = q >> UINT64_C(1);
    sp[l - 1] = st + ql;
    q = qh;
    if (!(c == INT64_C(0))) {
      cqt = wmpn_add_n_in_place(npl, spl, h);
      c = (int64_t)cqt;
    }
    IGNORE2(np, npl);
    npn = np + n;
    wmpn_mul(npn, sp, l, sp, l);
    ll = 2 * l;
    bo = wmpn_sub_n_in_place(np, npn, ll);
    b = q + bo;
    if (l == h) {
      c = c - (int64_t)b;
    } else {
      nll = np + ll;
      bo1 = wmpn_sub_1_in_place(nll, 1, b);
      c = c - (int64_t)bo1;
    }
    if (c < INT64_C(0)) {
      o1 = wmpn_add_1_in_place(spl, h, q);
      q = o1;
      IGNORE2(sp, spl);
      cqt1 = wmpn_addmul_1(np, sp, n, UINT64_C(2));
      c = c + (int64_t)(UINT64_C(2) * q + cqt1);
      o4 = wmpn_sub_1_in_place(np, n, UINT64_C(1));
      o3 = (int64_t)o4;
      o2 = c - o3;
      c = o2;
      bo2 = wmpn_sub_1_in_place(sp, n, UINT64_C(1));
      q = q - bo2;
    } else {
      IGNORE2(sp, spl);
    }
    IGNORE2(np, npn);
    return (uint64_t)c;
  }
}

int32_t wmpn_sqrtrem(uint64_t * sp, uint64_t * rp, uint64_t * np, int32_t n);

int32_t wmpn_sqrtrem(uint64_t * sp, uint64_t * rp, uint64_t * np, int32_t n) {
  uint64_t high, s, nh, ncc, cc;
  uint64_t c;
  int32_t res, adj;
  int32_t tn, rn;
  uint64_t * scratch;
  uint64_t * tp;
  uint64_t * o;
  uint64_t * tpa;
  uint64_t * nr;
  uint64_t * nx;
  struct __open_shift_sep_result struct_res;
  uint64_t res1, o1;
  uint64_t rl;
  uint64_t * s0;
  uint64_t s00, rc, o2;
  uint64_t cc1;
  uint64_t * tp1;
  uint64_t o3;
  uint64_t c2;
  uint64_t * tp11;
  uint64_t * o4;
  uint64_t * nr1;
  uint64_t * nx1;
  struct __open_shift_sep_result struct_res1;
  uint64_t res2, h;
  high = np[n - 1];
  c = (uint64_t)__builtin_clzll(high) / UINT64_C(2);
  if (n == 1) {
    if (c == UINT64_C(0)) {
      s = sqrt1(rp, high);
      *sp = s;
    } else {
      nh = high << (UINT64_C(2) * c);
      ncc = sqrt1(rp, nh);
      cc = ncc >> c;
      *sp = cc;
      *rp = high - cc * cc;
    }
    if (*rp == UINT64_C(0)) {
      res = 0;
    } else {
      res = 1;
    }
    return res;
  }
  tn = (n + 1) / 2;
  rn = 0;
  adj = (int32_t)((uint64_t)n % UINT64_C(2));
  scratch = alloca(((uint32_t)tn / 2U + 1U) * sizeof(uint64_t));
  if (!(adj == 0) || !(c == UINT64_C(0))) {
    o = alloca(2U * (uint32_t)tn * sizeof(uint64_t));
    tp = o;
    *tp = UINT64_C(0);
    tpa = tp + adj;
    if (!(c == UINT64_C(0))) {
      struct_res = open_shift_sep(tpa, np);
      nr = struct_res.__field_0;
      nx = struct_res.__field_1;
      res1 = wmpn_lshift(nr, nx, n, UINT64_C(2) * c);
      IGNORE2(tpa, np);
      res1;
    } else {
      wmpn_copyi1(tpa, np, n);
    }
    IGNORE2(tp, tpa);
    c = c + (!(adj == 0) ? UINT64_C(32) : UINT64_C(0));
    o1 = wmpn_dc_sqrtrem(sp, tp, tn, scratch);
    rl = o1;
    s0 = alloca(1U * sizeof(uint64_t));
    s00 = *sp % (UINT64_C(1) << c);
    *s0 = s00;
    rc = wmpn_addmul_1(tp, sp, tn, UINT64_C(2) * s00);
    rl = rl + rc;
    o2 = wmpn_submul_1(tp, s0, 1, s00);
    cc1 = o2;
    if (tn > 1) {
      tp1 = tp + 1;
      o3 = wmpn_sub_1_in_place(tp1, tn - 1, cc1);
      cc1 = o3;
    }
    rl = rl - cc1;
    wmpn_rshift(sp, sp, tn, c);
    tp[tn] = rl;
    c2 = c << UINT64_C(1);
    if (c2 < UINT64_C(64)) {
      tn = tn + 1;
    } else {
      tp11 = tp + 1;
      c2 = c2 - UINT64_C(64);
      tp = tp11;
    }
    if (!(c2 == UINT64_C(0))) {
      o4 = tp;
      struct_res1 = open_shift_sep(rp, o4);
      nr1 = struct_res1.__field_0;
      nx1 = struct_res1.__field_1;
      res2 = wmpn_rshift(nr1, nx1, tn, c2);
      IGNORE2(rp, o4);
      res2;
    } else {
      wmpn_copyi1(rp, tp, tn);
    }
    rn = tn;
  } else {
    wmpn_copyi1(rp, np, n);
    h = wmpn_dc_sqrtrem(sp, rp, tn, scratch);
    rp[tn] = h;
    rn = tn + (int32_t)h;
  }
  while (rp[rn - 1] == UINT64_C(0)) {
    rn = rn - 1;
    if (rn == 0) {
      break;
    }
  }
  return rn;
}
