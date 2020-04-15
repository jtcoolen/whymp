#ifndef SET_STR_H_INCLUDED

#include "uint64gmp.h"
#include "c.h"
#include "powm.h"
#include "logical.h"
#include "util.h"
#include "baseinfo.h"
#include "mul.h"
#include "add_1.h"
#include <stdint.h>

int32_t wmpn_set_str_bits(uint64_t * rp, unsigned char * sp, uint32_t sn,
                          uint32_t bits);

int32_t wmpn_set_str_other(uint64_t * rp, unsigned char * sp, uint32_t sn,
                           uint64_t b, struct wmpn_base_info info);

int32_t wmpn_set_str(uint64_t * rp, unsigned char * sp, uint32_t sn,
                     int32_t base);

#define SET_STR_H_INCLUDED
#endif // SET_STR_H_INCLUDED
