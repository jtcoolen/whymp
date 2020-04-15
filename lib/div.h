#ifndef DIV_H_INCLUDED

#include "uint64gmp.h"
#include "c.h"
#include "compare.h"
#include "utilold.h"
#include "addold.h"
#include "subold.h"
#include "logicalutil.h"
#include "logicalold.h"
#include "mul.h"
#include <stdint.h>

uint64_t invert_limb(uint64_t d);

struct __div2by1_inv_result
{ uint64_t __field_0;
  uint64_t __field_1;
};

struct __div2by1_inv_result div2by1_inv(uint64_t uh, uint64_t ul, uint64_t d,
                                        uint64_t v);

uint64_t wmpn_divrem_1(uint64_t * q, uint64_t * x, int32_t sz, uint64_t y);

struct __div3by2_inv_result
{ uint64_t __field_0;
  uint64_t __field_1;
  uint64_t __field_2;
};

struct __div3by2_inv_result div3by2_inv(uint64_t uh, uint64_t um,
                                        uint64_t ul, uint64_t dh,
                                        uint64_t dl, uint64_t v);

uint64_t reciprocal_word_3by2(uint64_t dh, uint64_t dl);

uint64_t div_sb_qr(uint64_t * q, uint64_t * x, int32_t sx, uint64_t * y,
                   int32_t sy);

uint64_t wmpn_divrem_2(uint64_t * q, uint64_t * x, uint64_t * y, int32_t sx);

void div_qr(uint64_t * q, uint64_t * r, uint64_t * x, uint64_t * y,
            uint64_t * nx, uint64_t * ny, int32_t sx, int32_t sy);

void wmpn_tdiv_qr(uint64_t * q, uint64_t * r, int32_t qxn, uint64_t * x,
                  int32_t sx, uint64_t * y, int32_t sy);

void div_qr_in_place(uint64_t * q, uint64_t * x, uint64_t * y, uint64_t * nx,
                     uint64_t * ny, int32_t sx, int32_t sy);

void wmpn_tdiv_qr_in_place(uint64_t * q, int32_t qxn, uint64_t * x,
                           int32_t sx, uint64_t * y, int32_t sy);

#define DIV_H_INCLUDED
#endif // DIV_H_INCLUDED
