#ifndef BASEINFO_H_INCLUDED

#include "logical.h"
#include <stdint.h>

uint32_t wmpn_base_power_of_two_p(uint64_t b);

struct wmpn_base_info {
  uint32_t exp;
  uint64_t bb;
};

struct wmpn_base_info wmpn_get_base_info(uint64_t b);

uint64_t wmpn_limb_size_in_base_2(uint64_t u);

#define BASEINFO_H_INCLUDED
#endif // BASEINFO_H_INCLUDED
