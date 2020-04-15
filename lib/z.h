#ifndef Z_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include <stdint.h>

typedef struct
{
  int _alloc;
  int _size;
  uint64_t * _ptr;
} __wmpz_struct;

typedef __wmpz_struct *wmpz_ptr;
typedef __wmpz_struct wmpz_t[1];

#define SIZ(x) ((x)->_size)
#define ALLOC(x) ((x)->_alloc)
#define PTR(x) ((x)->_ptr)


#define Z_H_INCLUDED
#endif // Z_H_INCLUDED
