#ifndef SQRT_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include "compare.h"
#include "utilold.h"
#include "add_1.h"
#include "addold.h"
#include "sub_1.h"
#include "subold.h"
#include "mul.h"
#include "logicalutil.h"
#include "logical.h"
#include "div.h"
#include "sqrt1.h"
#include "alias.h"
#include "toom.h"
#include <stdint.h>

uint64_t wmpn_sqrtrem2(uint64_t * sp, uint64_t * rp, uint64_t * np);

uint64_t wmpn_dc_sqrtrem(uint64_t * sp, uint64_t * np, int32_t n,
                         uint64_t * scratch);

int32_t wmpn_sqrtrem(uint64_t * sp, uint64_t * rp, uint64_t * np, int32_t n);

#define SQRT_H_INCLUDED
#endif // SQRT_H_INCLUDED
