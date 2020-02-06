#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
uint64_t wmpn_sqrtrem2(uint64_t * sp, uint64_t * rp, uint64_t * np);

uint64_t wmpn_dc_sqrtrem(uint64_t * sp, uint64_t * np, int32_t n,
                         uint64_t * scratch);

int32_t wmpn_sqrtrem(uint64_t * sp, uint64_t * rp, uint64_t * np, int32_t n);

