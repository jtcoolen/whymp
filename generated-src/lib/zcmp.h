#ifndef ZCMP_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
int32_t wmpz_cmp(wmpz_ptr u, wmpz_ptr v);

int32_t wmpz_cmp_ui(wmpz_ptr u, uint64_t v_digit);

#define ZCMP_H_INCLUDED
#endif // ZCMP_H_INCLUDED
