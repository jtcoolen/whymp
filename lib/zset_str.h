#ifndef ZSET_STR_H_INCLUDED

#include "c.h"
#include "uint64gmp.h"
#include "util.h"
#include "z.h"
#include "zutil.h"
#include "baseinfo.h"
#include "set_str.h"
#include <stdint.h>
#include <string.h>

int32_t wmpz_set_str(wmpz_ptr r, char * sp, int32_t base);

#define ZSET_STR_H_INCLUDED
#endif // ZSET_STR_H_INCLUDED
