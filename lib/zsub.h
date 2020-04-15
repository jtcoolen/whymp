#ifndef ZSUB_H_INCLUDED

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

void wmpz_sub(wmpz_ptr w, wmpz_ptr u, wmpz_ptr v);

void wmpz_sub_ui(wmpz_ptr w, wmpz_ptr u, uint64_t v);

void wmpz_ui_sub(wmpz_ptr w, uint64_t uval, wmpz_ptr v);

#define ZSUB_H_INCLUDED
#endif // ZSUB_H_INCLUDED
