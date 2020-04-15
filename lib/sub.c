#include "sub.h"
#include <stdint.h>

uint64_t wmpn_sub_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz) {
  uint64_t lx, ly, b;
  int32_t i;
  uint64_t res, borrow;
  struct __sub64_with_borrow_result struct_res;
  lx = UINT64_C(0);
  ly = UINT64_C(0);
  b = UINT64_C(0);
  i = 0;
  while (i < sz) {
    lx = x[i];
    ly = y[i];
    struct_res = sub64_with_borrow(lx, ly, b);
    res = struct_res.__field_0;
    borrow = struct_res.__field_1;
    r[i] = res;
    b = borrow;
    i = i + 1;
  }
  return b;
}

uint64_t wmpn_sub(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y,
                  int32_t sy) {
  uint64_t lx, b;
  uint64_t o, res;
  int32_t i;
  lx = UINT64_C(0);
  o = wmpn_sub_n(r, x, y, sy);
  b = o;
  i = sy;
  if (!(b == UINT64_C(0))) {
    while (i < sx) {
      lx = x[i];
      res = lx - UINT64_C(1);
      r[i] = res;
      i = i + 1;
      if (!(lx == UINT64_C(0))) {
        b = UINT64_C(0);
        break;
      }
    }
  }
  while (i < sx) {
    lx = x[i];
    r[i] = lx;
    i = i + 1;
  }
  return b;
}

uint64_t sub_n(uint64_t * r, uint64_t * x, uint64_t * y, int32_t sz) {
  uint64_t * nr;
  uint64_t * nx;
  uint64_t * ny;
  struct __open_sep_result struct_res;
  uint64_t res;
  struct_res = open_sep(r, x, sz, y, sz);
  nr = struct_res.__field_0;
  nx = struct_res.__field_1;
  ny = struct_res.__field_2;
  res = wmpn_sub_n(nr, nx, ny, sz);
  IGNORE3(r,x,y);
  return res;
}

uint64_t sub_n_rx(uint64_t * x, uint64_t * y, int32_t sz) {
  uint64_t * nr;
  uint64_t * nx;
  uint64_t * ny;
  struct __open_rx_result struct_res;
  uint64_t res;
  struct_res = open_rx(x, sz, y, sz);
  nr = struct_res.__field_0;
  nx = struct_res.__field_1;
  ny = struct_res.__field_2;
  res = wmpn_sub_n(nr, nx, ny, sz);
  IGNORE3(x,sz,sz);
  return res;
}

uint64_t sub_n_ry(uint64_t * x, uint64_t * y, int32_t sz) {
  uint64_t * nr;
  uint64_t * ny;
  uint64_t * nx;
  struct __open_rx_result struct_res;
  uint64_t res;
  struct_res = open_rx(y, sz, x, sz);
  nr = struct_res.__field_0;
  ny = struct_res.__field_1;
  nx = struct_res.__field_2;
  res = wmpn_sub_n(nr, nx, ny, sz);
  IGNORE3(y,sz,sz);
  return res;
}

uint64_t sub(uint64_t * r, uint64_t * x, int32_t sx, uint64_t * y, int32_t sy) {
  uint64_t * nr;
  uint64_t * nx;
  uint64_t * ny;
  struct __open_sep_result struct_res;
  uint64_t res;
  struct_res = open_sep(r, x, sx, y, sy);
  nr = struct_res.__field_0;
  nx = struct_res.__field_1;
  ny = struct_res.__field_2;
  res = wmpn_sub(nr, nx, sx, ny, sy);
  IGNORE3(r,x,y);
  return res;
}

uint64_t sub_rx(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy) {
  uint64_t * nr;
  uint64_t * nx;
  uint64_t * ny;
  struct __open_rx_result struct_res;
  uint64_t res;
  struct_res = open_rx(x, sx, y, sy);
  nr = struct_res.__field_0;
  nx = struct_res.__field_1;
  ny = struct_res.__field_2;
  res = wmpn_sub(nr, nx, sx, ny, sy);
  IGNORE3(x,sx,sy);
  return res;
}

uint64_t sub_ry(uint64_t * x, int32_t sx, uint64_t * y, int32_t sy) {
  uint64_t * nr;
  uint64_t * ny;
  uint64_t * nx;
  struct __open_rx_result struct_res;
  uint64_t res;
  struct_res = open_rx(y, sx, x, sx);
  nr = struct_res.__field_0;
  ny = struct_res.__field_1;
  nx = struct_res.__field_2;
  res = wmpn_sub(nr, nx, sx, ny, sy);
  IGNORE3(y,sx,sx);
  return res;
}
