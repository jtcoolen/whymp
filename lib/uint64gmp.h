#ifndef UINT64GMP_H_INCLUDED

#include <stdint.h>

typedef unsigned __int128 uint128_t;

struct __mul64_double_result {
  uint64_t __field_0;
  uint64_t __field_1;
};

static inline struct __mul64_double_result
mul64_double(uint64_t x, uint64_t y)
{
  uint128_t z = (uint128_t)x * (uint128_t)y;
  struct __mul64_double_result result = { z, z >> 64 };
  return result;
}

static inline uint64_t
div64_2by1(uint64_t ul, uint64_t uh, uint64_t d)
{
  return (((uint128_t)uh << 64) | ul) / d;
}

struct __add64_with_carry_result {
  uint64_t __field_0;
  uint64_t __field_1;
};

static inline struct __add64_with_carry_result
add64_with_carry(uint64_t x, uint64_t y, uint64_t c)
{
  struct __add64_with_carry_result result;
  uint64_t r = x + y + c;
  result.__field_0 = r;
  if (r == x) result.__field_1 = c;
  else result.__field_1 = (r < x);
  return result;
}

struct __sub64_with_borrow_result {
  uint64_t __field_0;
  uint64_t __field_1;
};

static inline struct __sub64_with_borrow_result
sub64_with_borrow(uint64_t x, uint64_t y, uint64_t b)
{
  struct __sub64_with_borrow_result result;
  uint64_t r = x - y - b;
  result.__field_0 = r;
  if (r > x) result.__field_1 = 1;
  else if (r == x) result.__field_1 = b;
  else result.__field_1 = 0;
  return result;
}

struct __add64_3_result {
  uint64_t __field_0;
  uint64_t __field_1;
};

static inline struct __add64_3_result
add64_3(uint64_t x, uint64_t y, uint64_t z)
{
  struct __add64_3_result result;
  uint64_t r, c1, c2;
  r = x + y;
  c1 = r < y;
  r += z;
  c2 = r < z;
  result.__field_1 = c1 + c2;
  result.__field_0 = r;
  return result;
}

struct __lsld64_result {
  uint64_t __field_0;
  uint64_t __field_1;
};

static inline struct __lsld64_result
lsld64(uint64_t x, uint64_t cnt)
{
  struct __lsld64_result result;
  result.__field_1 = x >> (64 - cnt);
  result.__field_0 = x << cnt;
  return result;
}


#define UINT64GMP_H_INCLUDED
#endif // UINT64GMP_H_INCLUDED
