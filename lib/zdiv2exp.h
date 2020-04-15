#ifndef ZDIV2EXP_H_INCLUDED

#include "c.h"
#include "util.h"
#include "utilold.h"
#include "alias.h"
#include "compare.h"
#include "uint64gmp.h"
#include "logicalutil.h"
#include "logical.h"
#include "logicalold.h"
#include "z.h"
#include "zutil.h"
#include <stdint.h>

void wmpz_tdiv_q_2exp(wmpz_ptr r, wmpz_ptr u, uint64_t cnt);

#define ZDIV2EXP_H_INCLUDED
#endif // ZDIV2EXP_H_INCLUDED
