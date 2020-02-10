#ifndef SUB_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
uint64_t wmpn_sub_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

uint64_t wmpn_sub(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy);

uint64_t sub_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz);

uint64_t sub_n_rx(uint64_t * x, uint64_t * y, int32_t sz);

uint64_t sub_n_ry(uint64_t * x, uint64_t * y, int32_t sz);

uint64_t sub(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y, int32_t sy);

uint64_t sub_rx(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy);

uint64_t sub_ry(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy);

#define SUB_H_INCLUDED
#endif // SUB_H_INCLUDED
