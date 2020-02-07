#ifndef LOGICALOLD_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
uint64_t wmpn_lshift1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_rshift1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_lshift_in_place(uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_rshift_in_place(uint64_t * x, int32_t sz, uint64_t cnt);

#define LOGICALOLD_H_INCLUDED
#endif // LOGICALOLD_H_INCLUDED
