#ifndef LOGICAL_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
uint64_t wmpn_lshift(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_lshift_sep(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_rshift(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_rshift_sep(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

#define LOGICAL_H_INCLUDED
#endif // LOGICAL_H_INCLUDED
