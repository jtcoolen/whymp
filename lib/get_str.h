#ifndef GET_STR_H_INCLUDED

#include "uint64gmp.h"
#include "c.h"
#include "powm.h"
#include "logical.h"
#include "baseinfo.h"
#include "div.h"
#include "utilold.h"
#include <stdint.h>

uint32_t wmpn_get_str_bits(unsigned char * sp, uint32_t bits, uint64_t * up,
                           int32_t un);

uint32_t wmpn_limb_get_str(unsigned char * sp, uint64_t * w, uint64_t d1,
                           uint64_t di, uint64_t shift);

uint32_t wmpn_get_str_other(unsigned char * sp, int32_t base,
                            struct wmpn_base_info info, uint64_t * up,
                            int32_t un);

uint32_t wmpn_get_str(unsigned char * sp, int32_t base, uint64_t * up,
                      int32_t un);

#define GET_STR_H_INCLUDED
#endif // GET_STR_H_INCLUDED
