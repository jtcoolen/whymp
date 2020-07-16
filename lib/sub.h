#ifndef SUB_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include "alias.h"
#include <stdint.h>

uint64_t wmpn_sub_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

uint64_t wmpn_sub(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy);

#define SUB_H_INCLUDED
#endif // SUB_H_INCLUDED
