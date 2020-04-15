#ifndef ADD_1_H_INCLUDED

#include "uint64gmp.h"
#include "c.h"
#include <stdint.h>

uint64_t wmpn_add_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y);

void wmpn_incr(uint64_t * x, uint64_t y);

void wmpn_incr_1(uint64_t * x);

uint64_t wmpn_add_1_in_place(uint64_t * x, int32_t sz, uint64_t y);

#define ADD_1_H_INCLUDED
#endif // ADD_1_H_INCLUDED
