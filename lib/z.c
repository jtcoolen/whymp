#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
#include "int.h"

#include "abs.h"

#include "int32.h"

#include "c.h"

#include "map.h"

#include "types.h"

#include "uint64gmp.h"

#include "power.h"


typedef struct
{
int _alloc;
int _size;
uint64_t * _ptr;
} __wmpz_struct;

typedef __wmpz_struct *wmpz_ptr;

#define SIZ(x) ((x)->_size)
#define ALLOC(x) ((x)->_alloc)
#define PTR(x) ((x)->_ptr)


int32_t abs(int32_t x) {
  if (x >= 0) {
    return x;
  } else {
    return -x;
  }
}

int32_t abs_size_of(wmpz_ptr x) {
  if (SIZ(x) >= 0) {
    return SIZ(x);
  } else {
    return -SIZ(x);
  }
}

