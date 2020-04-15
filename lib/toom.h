#ifndef TOOM_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include "compare.h"
#include "util.h"
#include "utilold.h"
#include "add_1.h"
#include "addold.h"
#include "sub_1.h"
#include "subold.h"
#include "mul.h"
#include "mul_basecase.h"
#include "logical.h"
#include <stdint.h>

extern int32_t toom22_threshold;

void wmpn_toom22_mul(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                     int32_t sy, uint64_t * scratch);

void wmpn_toom22_mul_rec(uint64_t * r, uint64_t * x, int32_t sx,
                         uint64_t * y, int32_t sy, uint64_t * scratch);

void wmpn_toom22_mul_n_rec(uint64_t * r, uint64_t * x, uint64_t * y,
                           uint64_t * scratch, int32_t sz);

void wmpn_toom32_mul(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                     int32_t sy, uint64_t * scratch);

uint64_t wmpn_mul(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy);

void wmpn_mul_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

#define TOOM_H_INCLUDED
#endif // TOOM_H_INCLUDED
