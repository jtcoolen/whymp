#ifndef ZUTIL_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>

wmpz_ptr __wmpz_init ();
void wmpz_clear (wmpz_ptr x);

uint64_t * wmpz_do_realloc(wmpz_ptr x, int32_t sz);

uint64_t * wmpz_realloc(wmpz_ptr x, int32_t sz);

void mpz_ptr_swap(wmpz_ptr * x, wmpz_ptr * y);

#define ZUTIL_H_INCLUDED
#endif // ZUTIL_H_INCLUDED
