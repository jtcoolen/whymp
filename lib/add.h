#ifndef ADD_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include "alias.h"
#include <stdint.h>

uint64_t wmpn_add_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

uint64_t wmpn_add(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy);

uint64_t add_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

uint64_t add_n_rx(uint64_t * x, uint64_t * y, int32_t sz);

uint64_t add(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y, int32_t sy);

uint64_t add_rx(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy);

uint64_t add_ry(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy);

uint64_t add_n_rxy(uint64_t * x, int32_t sx);

#define ADD_H_INCLUDED
#endif // ADD_H_INCLUDED
