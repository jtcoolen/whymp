#ifndef ZNEG_H_INCLUDED

#include "c.h"
#include "util.h"
#include "compare.h"
#include "uint64gmp.h"
#include "z.h"
#include "zutil.h"
#include <stdint.h>

void wmpz_neg(wmpz_ptr w, wmpz_ptr u);

#define ZNEG_H_INCLUDED
#endif // ZNEG_H_INCLUDED
