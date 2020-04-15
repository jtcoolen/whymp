#ifndef MUL_H_INCLUDED

#include "uint64gmp.h"
#include "c.h"
#include "util.h"
#include "add.h"
#include <stdint.h>

uint64_t wmpn_mul_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y);

uint64_t wmpn_addmul_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y);

uint64_t wmpn_addmul_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

uint64_t wmpn_mul_1_in_place(uint64_t * x, int32_t sz, uint64_t y);

uint64_t wmpn_submul_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y);

uint64_t wmpn_addmul_2(uint64_t * r, uint64_t * x, int32_t sz, uint64_t * y);

#define MUL_H_INCLUDED
#endif // MUL_H_INCLUDED
