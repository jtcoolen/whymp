#ifndef SUB_1_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
uint64_t wmpn_sub_1(uint64_t * r, uint64_t * x, int32_t sz, uint64_t y);

void wmpn_decr(uint64_t * x, uint64_t y);

void wmpn_decr_1(uint64_t * x);

uint64_t wmpn_sub_1_in_place(uint64_t * x, int32_t sz, uint64_t y);

#define SUB_1_H_INCLUDED
#endif // SUB_1_H_INCLUDED
