#ifndef UINT32GMP_H_INCLUDED

#include <stdint.h>

struct __add32_with_carry_result
{ uint32_t __field_0;
  uint32_t __field_1;
};

struct __add32_with_carry_result
      add32_with_carry(uint32_t x, uint32_t y, uint32_t c);

struct __sub32_with_borrow_result
{ uint32_t __field_0;
  uint32_t __field_1;
};

struct __sub32_with_borrow_result
        sub32_with_borrow(uint32_t x, uint32_t y, uint32_t b);

struct __mul32_double_result
{ uint32_t __field_0;
  uint32_t __field_1;
};

struct __mul32_double_result mul32_double(uint32_t x, uint32_t y);

struct __add32_3_result
{ uint32_t __field_0;
  uint32_t __field_1;
};

struct __add32_3_result add32_3(uint32_t x, uint32_t y, uint32_t z);

struct __lsld32_result
{ uint32_t __field_0;
  uint32_t __field_1;
};
struct __lsld32_result lsld32(uint32_t x, uint32_t cnt);


#define UINT32GMP_H_INCLUDED
#endif // UINT32GMP_H_INCLUDED
