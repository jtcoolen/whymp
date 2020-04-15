#ifndef ZUTIL_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include "z.h"
#include <stdint.h>

void __wmpz_init (wmpz_ptr);
void wmpz_clear (wmpz_ptr);

uint64_t * wmpz_do_realloc(wmpz_ptr x, int32_t sz);

uint64_t * wmpz_realloc(wmpz_ptr x, int32_t sz);

#define ZUTIL_H_INCLUDED
#endif // ZUTIL_H_INCLUDED
