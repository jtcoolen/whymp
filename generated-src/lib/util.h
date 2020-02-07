#ifndef UTIL_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
int32_t wmpn_zero_p(uint64_t * x, int32_t sz);

void wmpn_zero(uint64_t * r, int32_t sz);

void normalize(uint64_t * p, int32_t * n);

void wmpn_copyd(uint64_t * rp, uint64_t * up, int32_t n);

void wmpn_copyd_sep(uint64_t * rp, uint64_t * up, int32_t n);

void wmpn_copyi(uint64_t * rp, uint64_t * up, int32_t n);

#define UTIL_H_INCLUDED
#endif // UTIL_H_INCLUDED
