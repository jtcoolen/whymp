#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
uint64_t wmpn_mul_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y);

uint64_t wmpn_addmul_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y);

uint64_t wmpn_addmul_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

void wmpn_mul_basecase(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                       int32_t sy);

