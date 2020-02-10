#ifndef ZSUB_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
void wmpz_sub(wmpz_ptr w, wmpz_ptr u, wmpz_ptr v);

void wmpz_sub_ui(wmpz_ptr w, wmpz_ptr u, uint64_t v);

void wmpz_ui_sub(wmpz_ptr w, uint64_t uval, wmpz_ptr v);

#define ZSUB_H_INCLUDED
#endif // ZSUB_H_INCLUDED
