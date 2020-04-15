#ifndef LOGICAL_H_INCLUDED

#include "uint64gmp.h"
#include "c.h"
#include "logicalutil.h"
#include "alias.h"
#include <stdint.h>

uint64_t wmpn_lshift(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_rshift(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

#define LOGICAL_H_INCLUDED
#endif // LOGICAL_H_INCLUDED
