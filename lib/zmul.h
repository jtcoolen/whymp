#ifndef ZMUL_H_INCLUDED

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
#include "z.h"
#include "zutil.h"
#include "set.h"
#include <stdint.h>

void wmpz_mul(wmpz_ptr w, wmpz_ptr u, wmpz_ptr v);

void wmpz_mul_si(wmpz_ptr prod, wmpz_ptr mult, int64_t small_mult);

void wmpz_mul_ui(wmpz_ptr prod, wmpz_ptr mult, uint64_t small_mult);

#define ZMUL_H_INCLUDED
#endif // ZMUL_H_INCLUDED
