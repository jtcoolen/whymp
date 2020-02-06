#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
#include "int.h"

#include "euclideandivision.h"

#include "realinfix.h"

#include "uint64.h"

#include "power.h"

#include "map.h"

#include "c.h"

#include "fxp.h"


#include "sqrtinit.h"

uint64_t rsa_estimate (uint64_t a) {
  uint64_t abits, x0;
  abits = a >> 55;
  x0 = 0x100 | invsqrttab[abits - 0x80];
  return x0;
}

uint64_t sqrt1(uint64_t * rp, uint64_t a0)
{
  uint64_t a, x0, a1, m1, t1qt, t1, x1, a2, u1, u2, m2, t2qt, t2, x2, x;
  uint64_t c, s;
  a = a0;
  x0 = rsa_estimate(a);
  a1 = a >> UINT64_C(31);
  m1 = UINT64_C(0x2000000000000) - UINT64_C(0x30000);
  t1qt = m1 - x0 * x0 * a1;
  t1 = (uint64_t)((int64_t)t1qt >> UINT64_C(16));
  x1 = (x0 << UINT64_C(16)) + (uint64_t)((int64_t)(x0 * t1) >> UINT64_C(18));
  a2 = a >> UINT64_C(24);
  u1 = x1 * a2;
  u2 = u1 >> UINT64_C(25);
  m2 = UINT64_C(0x24000000000);
  t2qt = (a << UINT64_C(14)) - u2 * u2 - m2;
  t2 = (uint64_t)((int64_t)t2qt >> UINT64_C(24));
  x2 = u1 + (uint64_t)((int64_t)(x1 * t2) >> UINT64_C(15));
  x = x2 >> UINT64_C(32);
  c = x;
  s = c * c;
  if (s + UINT64_C(2) * c <= a0 - UINT64_C(1)) {
    s = s + UINT64_C(2) * c + UINT64_C(1);
    c = c + UINT64_C(1);
  }
  *rp = a0 - s;
  return c;
}

