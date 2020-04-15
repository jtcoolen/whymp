#include "zdiv.h"
#include <stdint.h>

void wmpz_tdiv_qr(wmpz_ptr quot, wmpz_ptr rem, wmpz_ptr num, wmpz_ptr den) {
  int32_t ns, ds, nl;
  int32_t dl, ql;
  uint64_t * np;
  uint64_t * rp;
  wmpz_ptr dqt, nqt;
  uint64_t * dp;
  wmpz_ptr nd;
  __wmpz_struct t = { 0, 0, NULL };
  uint64_t * tdp;
  uint64_t * np1;
  wmpz_ptr nn;
  __wmpz_struct t1 = { 0, 0, NULL };
  uint64_t * tnp;
  uint64_t * qp;
  uint64_t * rp1;
  uint64_t * np2;
  uint64_t * dp1;
  uint64_t qh;
  int32_t qs, rs;
  ns = SIZ(num);
  ds = SIZ(den);
  if (ns >= 0) {
    nl = ns;
  } else {
    nl = -ns;
  }
  dl = ds >= 0 ? ds : -ds;
  ql = nl - dl + 1;
  if (ql <= 0) {
    if (!(num == rem)) {
      np = PTR(num);
      rp = wmpz_realloc(rem, dl);
      wmpn_copyd_sep(rp, np, nl);
      SIZ(rem) = ns;
      (void)(num);
      (void)(rem);
    }
    SIZ(quot) = 0;
    return;
  }
  dqt = den;
  nqt = num;
  if (den == rem || den == quot) {
    dp = PTR(den);
    nd = &t;
    dqt = nd;
    tdp = alloca((uint32_t)dl * sizeof(uint64_t));
    ALLOC(dqt) = dl;
    wmpn_copyd_sep(tdp, dp, dl);
    PTR(dqt) = tdp;
    SIZ(dqt) = ds;
    (void)(dqt);
    (void)(den);
  }
  if (num == rem || num == quot) {
    np1 = PTR(num);
    nn = &t1;
    nqt = nn;
    tnp = alloca((uint32_t)nl * sizeof(uint64_t));
    ALLOC(nqt) = nl;
    wmpn_copyd_sep(tnp, np1, nl);
    PTR(nqt) = tnp;
    SIZ(nqt) = ns;
    (void)(nqt);
    (void)(num);
  }
  qp = wmpz_realloc(quot, ql);
  rp1 = wmpz_realloc(rem, dl);
  np2 = PTR(nqt);
  dp1 = PTR(dqt);
  wmpn_tdiv_qr(qp, rp1, 0, np2, nl, dp1, dl);
  qh = qp[ql - 1];
  ql = ql - (qh == UINT64_C(0));
  normalize(rp1, &dl);
  if ((ns ^ ds) >= 0) {
    qs = ql;
  } else {
    qs = -ql;
  }
  if (ns >= 0) {
    rs = dl;
  } else {
    rs = -dl;
  }
  SIZ(quot) = qs;
  SIZ(rem) = rs;
  (void)(rem);
  (void)(quot);
  (void)(nqt);
  (void)(dqt);
  return;
}

uint64_t wmpz_tdiv_qr_ui(wmpz_ptr quot, wmpz_ptr rem, wmpz_ptr dividend,
                         uint64_t divisor) {
  int32_t ns, nn;
  uint64_t * qp;
  int32_t qn;
  uint64_t rl;
  uint64_t * np;
  uint64_t o, o1;
  uint64_t * np1;
  int32_t rs;
  uint64_t * rp;
  uint64_t qh;
  int32_t qs;
  ns = SIZ(dividend);
  if (ns == 0) {
    SIZ(quot) = 0;
    SIZ(rem) = 0;
    return UINT64_C(0);
  }
  if (ns >= 0) {
    nn = ns;
  } else {
    nn = -ns;
  }
  qp = wmpz_realloc(quot, nn);
  qn = nn;
  rl = UINT64_C(0);
  if (quot == dividend) {
    np = alloca((uint32_t)nn * sizeof(uint64_t));
    wmpn_copyd_sep(np, qp, nn);
    o = wmpn_divrem_1(qp, np, nn, divisor);
    rl = o;
  } else {
    np1 = PTR(dividend);
    o1 = wmpn_divrem_1(qp, np1, nn, divisor);
    rl = o1;
    (void)(dividend);
  }
  if (rl == UINT64_C(0)) {
    SIZ(rem) = 0;
  } else {
    if (ns >= 0) {
      rs = 1;
    } else {
      rs = -1;
    }
    rp = PTR(rem);
    *rp = rl;
    SIZ(rem) = rs;
    (void)(rem);
  }
  qh = qp[nn - 1];
  qn = qn - (qh == UINT64_C(0));
  if (ns >= 0) {
    qs = qn;
  } else {
    qs = -qn;
  }
  SIZ(quot) = qs;
  (void)(quot);
  return rl;
}
