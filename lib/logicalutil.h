#ifndef LOGICALUTIL_H_INCLUDED

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

#define LOGICALUTIL_H_INCLUDED
#endif // LOGICALUTIL_H_INCLUDED
