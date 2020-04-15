#ifndef ZGET_STR_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include "util.h"
#include "z.h"
#include "zutil.h"
#include "baseinfo.h"
#include "get_str.h"
#include <stdint.h>
#include <string.h>

char * wmpz_get_str(char * sp, int32_t base, wmpz_ptr u);

#define ZGET_STR_H_INCLUDED
#endif // ZGET_STR_H_INCLUDED
