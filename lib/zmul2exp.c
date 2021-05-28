#include "zmul2exp.h"
#include <stdint.h>

void wmpz_mul_2exp(wmpz_ptr r, wmpz_ptr u, uint64_t cnt) {
  int32_t un, limb_cnt;
  int32_t rn;
  uint64_t * rp;
  uint64_t c, rlimb;
  uint64_t * rl;
  uint64_t * up;
  uint64_t * rl1;
  uint64_t rlimb1;
  uint64_t * rl2;
  if (SIZ(u) >= 0) {
    un = SIZ(u);
  } else {
    un = -SIZ(u);
  }
  limb_cnt = (int32_t)(cnt / UINT64_C(64));
  rn = un + limb_cnt;
  if (un == 0) {
    SIZ(r) = 0;
    return;
  } else {
    rp = wmpz_realloc(r, rn + 1);
    c = cnt % UINT64_C(64);
    if (u == r) {
      if (!(c == UINT64_C(0))) {
        rl = rp + limb_cnt;
        rlimb = wmpn_lshift(rl, rp, un, c);
        rp[rn] = rlimb;
        rn = rn + !(rlimb == UINT64_C(0));
      } else {
        wmpn_copyd(rp + limb_cnt, rp, un);
      }
    } else {
      up = PTR(u);
      if (!(c == UINT64_C(0))) {
        rl1 = rp + limb_cnt;
        rlimb1 = wmpn_lshift1(rl1, up, un, c);
        rp[rn] = rlimb1;
        rn = rn + !(rlimb1 == UINT64_C(0));
      } else {
        rl2 = rp + limb_cnt;
        wmpn_copyi1(rl2, up, un);
      }
      (void)(u);
    }
    wmpn_zero(rp, limb_cnt);
    SIZ(r) = SIZ(u) >= 0 ? rn : -rn;
    (void)(r);
    return;
  }
}
