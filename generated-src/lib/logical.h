#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
uint64_t lsl_mod_ext(uint64_t x, uint64_t cnt);

struct __lsld_ext_result
{ uint64_t __field_0;
  uint64_t __field_1;
};

struct __lsld_ext_result lsld_ext(uint64_t x, uint64_t cnt);

int32_t clz_ext(uint64_t x);

uint64_t wmpn_lshift(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_rshift(uint64_t * r, uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_lshift_in_place(uint64_t * x, int32_t sz, uint64_t cnt);

uint64_t wmpn_rshift_in_place(uint64_t * x, int32_t sz, uint64_t cnt);

