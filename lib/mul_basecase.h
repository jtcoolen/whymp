#ifndef MUL_BASECASE_H_INCLUDED

#include "uint64gmp.h"
#include "c.h"
#include "util.h"
#include "add.h"
#include "mul.h"
#include <stdint.h>

void wmpn_mul_basecase(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                       int32_t sy);

#define MUL_BASECASE_H_INCLUDED
#endif // MUL_BASECASE_H_INCLUDED
