#ifndef ZADD_H_INCLUDED

#include "c.h"
#include "util.h"
#include "alias.h"
#include "compare.h"
#include "uint64gmp.h"
#include "add.h"
#include "sub.h"
#include "z.h"
#include "zutil.h"
#include "add_1.h"
#include "sub_1.h"
#include <stdint.h>

void wmpz_add(wmpz_ptr w, wmpz_ptr u, wmpz_ptr v);

void wmpz_add_ui(wmpz_ptr w, wmpz_ptr u, uint64_t v);

#define ZADD_H_INCLUDED
#endif // ZADD_H_INCLUDED
