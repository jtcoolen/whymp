#include "zdiv2exp.h"
#include <stdint.h>

void wmpz_tdiv_q_2exp(wmpz_ptr r, wmpz_ptr u, uint64_t cnt) {
  int32_t un, limb_cnt;
  int32_t rn;
  uint64_t * rp;
  uint64_t c;
  uint64_t * up;
  uint64_t * up0;
  uint64_t * up1;
  un = SIZ(u);
  limb_cnt = (int32_t)(cnt / UINT64_C(64));
  rn = (un >= 0 ? un : -un) - limb_cnt;
  if (rn <= 0) {
    SIZ(r) = 0;
    return;
  } else {
    rp = wmpz_realloc(r, rn);
    c = cnt % UINT64_C(64);
    if (u == r) {
      up = rp + limb_cnt;
      if (!(c == UINT64_C(0))) {
        wmpn_rshift(rp, up, rn, c);
        rn = rn - (rp[rn - 1] == UINT64_C(0));
      } else {
        wmpn_copyi(rp, up, rn);
      }
    } else {
      up0 = PTR(u);
      up1 = up0 + limb_cnt;
      if (!(c == UINT64_C(0))) {
        wmpn_rshift1(rp, up1, rn, c);
        rn = rn - (rp[rn - 1] == UINT64_C(0));
      } else {
        wmpn_copyi1(rp, up1, rn);
      }
      (void)(u);
    }
    SIZ(r) = SIZ(u) >= 0 ? rn : -rn;
    (void)(r);
    return;
  }
}
