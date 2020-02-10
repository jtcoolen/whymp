#ifndef ZMUL_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
void wmpz_mul(wmpz_ptr w, wmpz_ptr u, wmpz_ptr v);

void wmpz_mul_si(wmpz_ptr prod, wmpz_ptr mult, int64_t small_mult);

void wmpz_mul_ui(wmpz_ptr prod, wmpz_ptr mult, uint64_t small_mult);

#define ZMUL_H_INCLUDED
#endif // ZMUL_H_INCLUDED
