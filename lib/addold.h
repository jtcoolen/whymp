#ifndef ADDOLD_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include "alias.h"
#include <stdint.h>

uint64_t wmpn_add_n1(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

uint64_t wmpn_add1(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                   int32_t sy);

uint64_t wmpn_add_n_in_place(uint64_t * x, uint64_t * y, int32_t sz);

uint64_t wmpn_add_in_place(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy);

#define ADDOLD_H_INCLUDED
#endif // ADDOLD_H_INCLUDED
