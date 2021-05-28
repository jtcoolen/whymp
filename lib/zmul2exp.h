#ifndef ZMUL2EXP_H_INCLUDED

#include "c.h"
#include "util.h"
#include "utilold.h"
#include "alias.h"
#include "compare.h"
#include "uint64gmp.h"
#include "logical.h"
#include "logicalold.h"
#include "z.h"
#include "zutil.h"
#include <stdint.h>

void wmpz_mul_2exp(wmpz_ptr r, wmpz_ptr u, uint64_t cnt);

#define ZMUL2EXP_H_INCLUDED
#endif // ZMUL2EXP_H_INCLUDED
