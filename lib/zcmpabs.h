#ifndef ZCMPABS_H_INCLUDED

#include "c.h"
#include "compare.h"
#include "alias.h"
#include "compare.h"
#include "uint64gmp.h"
#include "z.h"
#include "zutil.h"
#include <stdint.h>

int32_t wmpz_cmpabs(wmpz_ptr u, wmpz_ptr v);

int32_t wmpz_cmpabs_ui(wmpz_ptr u, uint64_t v_digit);

#define ZCMPABS_H_INCLUDED
#endif // ZCMPABS_H_INCLUDED
