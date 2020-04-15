#ifndef ZCMP_H_INCLUDED

#include "c.h"
#include "compare.h"
#include "alias.h"
#include "compare.h"
#include "uint64gmp.h"
#include "z.h"
#include "zutil.h"
#include "set.h"
#include <stdint.h>

int32_t wmpz_cmp(wmpz_ptr u, wmpz_ptr v);

int32_t wmpz_cmp_ui(wmpz_ptr u, uint64_t v_digit);

int32_t wmpz_cmp_si(wmpz_ptr u, int64_t v_digit);

int32_t wmpz_sgn(wmpz_ptr u);

#define ZCMP_H_INCLUDED
#endif // ZCMP_H_INCLUDED
