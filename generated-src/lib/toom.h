#ifndef TOOM_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
int32_t toom22_threshold();

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
