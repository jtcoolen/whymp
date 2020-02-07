#ifndef POWM_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <alloca.h>
void wmpn_redc_1(uint64_t * rp, uint64_t * up, uint64_t * mp, int32_t n,
                 uint64_t invm);

uint64_t binvert_limb(uint64_t n);

void wmpn_powm(uint64_t * rp, uint64_t * bp, int32_t bn, uint64_t * ep,
               int32_t en, uint64_t * mp, int32_t n, uint64_t * tp);

#define POWM_H_INCLUDED
#endif // POWM_H_INCLUDED
