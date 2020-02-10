#ifndef Z_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>

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


int32_t abs(int32_t x);

int32_t abs_size_of(wmpz_ptr x);

#define Z_H_INCLUDED
#endif // Z_H_INCLUDED
