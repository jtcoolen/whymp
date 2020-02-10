#ifndef SET_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
void wmpz_set_ui(wmpz_ptr dst, uint64_t src);

uint64_t abs_cast(int64_t x);

void wmpz_set_si(wmpz_ptr dst, int64_t src);

uint64_t wmpz_get_ui(wmpz_ptr src);

#define SET_H_INCLUDED
#endif // SET_H_INCLUDED
