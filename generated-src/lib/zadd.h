#ifndef ZADD_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
void wmpz_add(wmpz_ptr w, wmpz_ptr u, wmpz_ptr v);

void wmpz_add_ui(wmpz_ptr w, wmpz_ptr u, uint64_t v);

#define ZADD_H_INCLUDED
#endif // ZADD_H_INCLUDED
