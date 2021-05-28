#ifndef ZREALLOC2_H_INCLUDED

#include "c.h"
#include "util.h"
#include "compare.h"
#include "uint64gmp.h"
#include "z.h"
#include "zutil.h"
#include <stdint.h>

void wmpz_realloc2(wmpz_ptr x, uint64_t bits);

#define ZREALLOC2_H_INCLUDED
#endif // ZREALLOC2_H_INCLUDED
