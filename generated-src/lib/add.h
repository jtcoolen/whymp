#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
uint64_t wmpn_add_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y);

uint64_t wmpn_add_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

uint64_t wmpn_add(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy);

uint64_t wmpn_add_in_place(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy);

void wmpn_incr(uint64_t * x, uint64_t y);

void wmpn_incr_1(uint64_t * x);

uint64_t wmpn_add_1_in_place(uint64_t * x, int32_t sz, uint64_t y);

