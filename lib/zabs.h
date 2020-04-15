#ifndef ZABS_H_INCLUDED

#include "c.h"
#include "util.h"
#include "compare.h"
#include "uint64gmp.h"
#include "z.h"
#include "zutil.h"
#include <stdint.h>

void wmpz_abs(wmpz_ptr w, wmpz_ptr u);

#define ZABS_H_INCLUDED
#endif // ZABS_H_INCLUDED
