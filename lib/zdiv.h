#ifndef ZDIV_H_INCLUDED

#include "c.h"
#include "util.h"
#include "utilold.h"
#include "alias.h"
#include "compare.h"
#include "uint64gmp.h"
#include "div.h"
#include "z.h"
#include "zutil.h"
#include <stdint.h>

void wmpz_tdiv_qr(wmpz_ptr quot, wmpz_ptr rem, wmpz_ptr num, wmpz_ptr den);

uint64_t wmpz_tdiv_qr_ui(wmpz_ptr quot, wmpz_ptr rem, wmpz_ptr dividend,
                         uint64_t divisor);

#define ZDIV_H_INCLUDED
#endif // ZDIV_H_INCLUDED
