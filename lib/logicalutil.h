#ifndef LOGICALUTIL_H_INCLUDED

#include "uint64gmp.h"
#include "c.h"
#include <stdint.h>

struct __lsld_ext_result {
  uint64_t __field_0;
  uint64_t __field_1;
};

struct __lsld_ext_result lsld_ext(uint64_t x, uint64_t cnt);

#define LOGICALUTIL_H_INCLUDED
#endif // LOGICALUTIL_H_INCLUDED
