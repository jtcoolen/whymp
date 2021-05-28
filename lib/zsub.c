#include "zsub.h"
#include <stdint.h>

void wmpz_sub(wmpz_ptr w, wmpz_ptr u, wmpz_ptr v) {
  wmpz_ptr u1, v1;
  int32_t usize, vsize, abs_usize, abs_vsize, tmp_size, wsize;
  wmpz_ptr z;
  int uw, vw;
  uint64_t * wp;
  uint64_t * vp;
  uint64_t usb;
  uint64_t * nr;
  uint64_t * nx;
  uint64_t * ny;
  struct __open_rx_result struct_res;
  uint64_t res, usb1;
  uint64_t * up;
  uint64_t * nr1;
  uint64_t * ny1;
  uint64_t * nx1;
  struct __open_rx_result struct_res1;
  uint64_t res1;
  uint64_t * up1;
  uint64_t * vp1;
  uint64_t usb2;
  uint64_t * nr2;
  uint64_t * nx2;
  uint64_t * ny2;
  struct __open_sep_result struct_res2;
  uint64_t res2, usb3;
  uint64_t * vp2;
  uint64_t * nr3;
  uint64_t * ny3;
  uint64_t * nx3;
  struct __open_rx_result struct_res3;
  uint64_t res3, usb4;
  uint64_t * nr4;
  uint64_t * nx4;
  uint64_t * ny4;
  struct __open_rx_result struct_res4;
  uint64_t res4, usb5;
  uint64_t * up2;
  uint64_t * nr5;
  uint64_t * nx5;
  uint64_t * ny5;
  struct __open_rx_result struct_res5;
  uint64_t res5, usb6;
  uint64_t * nr6;
  uint64_t * ny6;
  uint64_t * nx6;
  struct __open_rx_result struct_res6;
  uint64_t res6;
  uint64_t * up3;
  uint64_t * vp3;
  uint64_t usb7;
  uint64_t * nr7;
  uint64_t * nx7;
  uint64_t * ny7;
  struct __open_sep_result struct_res7;
  uint64_t res7, usb8;
  uint64_t * nr8;
  uint64_t * nx8;
  uint64_t * ny8;
  struct __open_sep_result struct_res8;
  uint64_t res8;
  uint64_t cy;
  uint64_t * vp4;
  uint64_t o;
  uint64_t * nr9;
  uint64_t * nx9;
  uint64_t * ny9;
  struct __open_rx_result struct_res9;
  uint64_t res9, o1;
  uint64_t * up4;
  uint64_t * nr10;
  uint64_t * ny10;
  uint64_t * nx10;
  struct __open_rx_result struct_res10;
  uint64_t res10;
  uint64_t * up5;
  uint64_t * vp5;
  uint64_t o2;
  uint64_t * nr11;
  uint64_t * nx11;
  uint64_t * ny11;
  struct __open_sep_result struct_res11;
  uint64_t res11;
  u1 = u;
  v1 = v;
  if (u1 == v1) {
    SIZ(w) = 0;
    return;
  }
  usize = SIZ(u1);
  vsize = -SIZ(v1);
  abs_usize = usize >= 0 ? usize : -usize;
  abs_vsize = vsize >= 0 ? vsize : -vsize;
  if (abs_usize < abs_vsize) {
    z = u1;
    u1 = v1;
    v1 = z;
    tmp_size = vsize;
    vsize = usize;
    usize = tmp_size;
    tmp_size = abs_vsize;
    abs_vsize = abs_usize;
    abs_usize = tmp_size;
  }
  wsize = abs_usize + 1;
  uw = u1 == w;
  vw = v1 == w;
  wp = wmpz_realloc(w, wsize);
  if ((usize ^ vsize) < 0) {
    if (!(abs_usize == abs_vsize)) {
      if (uw) {
        vp = PTR(v1);
        struct_res = open_rx(wp, vp);
        nr = struct_res.__field_0;
        nx = struct_res.__field_1;
        ny = struct_res.__field_2;
        res = wmpn_sub(nr, nx, abs_usize, ny, abs_vsize);
        IGNORE2(wp, vp);
        usb = res;
        (void)(v1);
      } else {
        if (vw) {
          up = PTR(u1);
          struct_res1 = open_rx(wp, up);
          nr1 = struct_res1.__field_0;
          ny1 = struct_res1.__field_1;
          nx1 = struct_res1.__field_2;
          res1 = wmpn_sub(nr1, nx1, abs_usize, ny1, abs_vsize);
          IGNORE2(wp, up);
          usb1 = res1;
          (void)(u1);
        } else {
          up1 = PTR(u1);
          vp1 = PTR(v1);
          struct_res2 = open_sep(wp, up1, vp1);
          nr2 = struct_res2.__field_0;
          nx2 = struct_res2.__field_1;
          ny2 = struct_res2.__field_2;
          res2 = wmpn_sub(nr2, nx2, abs_usize, ny2, abs_vsize);
          IGNORE3(wp, up1, vp1);
          usb2 = res2;
          (void)(u1);
          (void)(v1);
        }
      }
      wsize = abs_usize;
      normalize(wp, &wsize);
      if (usize < 0) {
        wsize = -wsize;
      }
    } else {
      wsize = abs_usize;
      if (uw) {
        vp2 = PTR(v1);
        if (wmpn_cmp(wp, vp2, abs_usize) < 0) {
          struct_res3 = open_rx(wp, vp2);
          nr3 = struct_res3.__field_0;
          ny3 = struct_res3.__field_1;
          nx3 = struct_res3.__field_2;
          res3 = wmpn_sub_n(nr3, nx3, ny3, abs_usize);
          IGNORE2(wp, vp2);
          usb3 = res3;
          normalize(wp, &wsize);
          if (usize >= 0) {
            wsize = -wsize;
          }
        } else {
          struct_res4 = open_rx(wp, vp2);
          nr4 = struct_res4.__field_0;
          nx4 = struct_res4.__field_1;
          ny4 = struct_res4.__field_2;
          res4 = wmpn_sub_n(nr4, nx4, ny4, abs_usize);
          IGNORE2(wp, vp2);
          usb4 = res4;
          normalize(wp, &wsize);
          if (usize < 0) {
            wsize = -wsize;
          }
        }
        (void)(v1);
      } else {
        if (vw) {
          up2 = PTR(u1);
          if (wmpn_cmp(up2, wp, abs_usize) < 0) {
            struct_res5 = open_rx(wp, up2);
            nr5 = struct_res5.__field_0;
            nx5 = struct_res5.__field_1;
            ny5 = struct_res5.__field_2;
            res5 = wmpn_sub_n(nr5, nx5, ny5, abs_usize);
            IGNORE2(wp, up2);
            usb5 = res5;
            normalize(wp, &wsize);
            if (usize >= 0) {
              wsize = -wsize;
            }
          } else {
            struct_res6 = open_rx(wp, up2);
            nr6 = struct_res6.__field_0;
            ny6 = struct_res6.__field_1;
            nx6 = struct_res6.__field_2;
            res6 = wmpn_sub_n(nr6, nx6, ny6, abs_usize);
            IGNORE2(wp, up2);
            usb6 = res6;
            normalize(wp, &wsize);
            if (usize < 0) {
              wsize = -wsize;
            }
          }
          (void)(u1);
        } else {
          up3 = PTR(u1);
          vp3 = PTR(v1);
          if (wmpn_cmp(up3, vp3, abs_usize) < 0) {
            struct_res7 = open_sep(wp, vp3, up3);
            nr7 = struct_res7.__field_0;
            nx7 = struct_res7.__field_1;
            ny7 = struct_res7.__field_2;
            res7 = wmpn_sub_n(nr7, nx7, ny7, abs_usize);
            IGNORE3(wp, vp3, up3);
            usb7 = res7;
            normalize(wp, &wsize);
            if (usize >= 0) {
              wsize = -wsize;
            }
          } else {
            struct_res8 = open_sep(wp, up3, vp3);
            nr8 = struct_res8.__field_0;
            nx8 = struct_res8.__field_1;
            ny8 = struct_res8.__field_2;
            res8 = wmpn_sub_n(nr8, nx8, ny8, abs_usize);
            IGNORE3(wp, up3, vp3);
            usb8 = res8;
            normalize(wp, &wsize);
            if (usize < 0) {
              wsize = -wsize;
            }
          }
          (void)(u1);
          (void)(v1);
        }
      }
    }
  } else {
    cy = UINT64_C(0);
    if (uw) {
      vp4 = PTR(v1);
      struct_res9 = open_rx(wp, vp4);
      nr9 = struct_res9.__field_0;
      nx9 = struct_res9.__field_1;
      ny9 = struct_res9.__field_2;
      res9 = wmpn_add(nr9, nx9, abs_usize, ny9, abs_vsize);
      IGNORE2(wp, vp4);
      o = res9;
      cy = o;
      (void)(v1);
    } else {
      if (vw) {
        up4 = PTR(u1);
        struct_res10 = open_rx(wp, up4);
        nr10 = struct_res10.__field_0;
        ny10 = struct_res10.__field_1;
        nx10 = struct_res10.__field_2;
        res10 = wmpn_add(nr10, nx10, abs_usize, ny10, abs_vsize);
        IGNORE2(wp, up4);
        o1 = res10;
        cy = o1;
        (void)(u1);
      } else {
        up5 = PTR(u1);
        vp5 = PTR(v1);
        struct_res11 = open_sep(wp, up5, vp5);
        nr11 = struct_res11.__field_0;
        nx11 = struct_res11.__field_1;
        ny11 = struct_res11.__field_2;
        res11 = wmpn_add(nr11, nx11, abs_usize, ny11, abs_vsize);
        IGNORE3(wp, up5, vp5);
        o2 = res11;
        cy = o2;
        (void)(u1);
        (void)(v1);
      }
    }
    wp[abs_usize] = cy;
    wsize = abs_usize + (int32_t)cy;
    if (usize < 0) {
      wsize = -wsize;
    }
  }
  SIZ(w) = wsize;
  (void)(w);
  return;
}

void wmpz_sub_ui(wmpz_ptr w, wmpz_ptr u, uint64_t v) {
  int32_t usize, abs_usize;
  uint64_t * wp;
  int uw;
  int32_t wsize;
  uint64_t * wp1;
  uint64_t cy;
  uint64_t result, result1;
  uint64_t * up;
  uint64_t * up1;
  usize = SIZ(u);
  if (usize == 0) {
    wp = PTR(w);
    *wp = v;
    SIZ(w) = -(!(v == UINT64_C(0)));
    (void)(w);
    return;
  }
  if (usize >= 0) {
    abs_usize = usize;
  } else {
    abs_usize = -usize;
  }
  uw = u == w;
  wsize = abs_usize + 1;
  wp1 = wmpz_realloc(w, wsize);
  cy = UINT64_C(0);
  if (usize < 0) {
    if (uw) {
      result = wmpn_add_1_in_place(wp1, abs_usize, v);
      cy = result;
    } else {
      up = PTR(u);
      result1 = wmpn_add_1(wp1, up, abs_usize, v);
      cy = result1;
      (void)(u);
    }
    wp1[abs_usize] = cy;
    wsize = -(abs_usize + (int32_t)cy);
  } else {
    if (uw) {
      if (abs_usize == 1 && *wp1 < v) {
        *wp1 = v - *wp1;
        wsize = -1;
      } else {
        wmpn_sub_1_in_place(wp1, abs_usize, v);
        wsize = abs_usize - (wp1[abs_usize - 1] == UINT64_C(0));
      }
    } else {
      up1 = PTR(u);
      if (abs_usize == 1 && *up1 < v) {
        *wp1 = v - *up1;
        wsize = -1;
      } else {
        wmpn_sub_1(wp1, up1, abs_usize, v);
        wsize = abs_usize - (wp1[abs_usize - 1] == UINT64_C(0));
      }
      (void)(u);
    }
  }
  SIZ(w) = wsize;
  (void)(w);
  return;
}

void wmpz_ui_sub(wmpz_ptr w, uint64_t uval, wmpz_ptr v) {
  int32_t vsize, wsize;
  int vw;
  uint64_t * wp;
  uint64_t * vp;
  uint64_t * wp1;
  uint64_t * vp1;
  uint64_t * wp2;
  uint64_t * wp3;
  uint64_t cy, cy1;
  uint64_t * vp2;
  vsize = SIZ(v);
  wsize = 0;
  vw = v == w;
  if (vsize > 1) {
    wp = wmpz_realloc(w, vsize);
    if (vw) {
      wmpn_sub_1_in_place(wp, vsize, uval);
    } else {
      vp = PTR(v);
      wmpn_sub_1(wp, vp, vsize, uval);
      (void)(v);
    }
    wsize = -(vsize - (wp[vsize - 1] == UINT64_C(0)));
    SIZ(w) = wsize;
    (void)(w);
    return;
  } else {
    if (vsize == 1) {
      wp1 = PTR(w);
      if (vw) {
        if (uval >= *wp1) {
          *wp1 = uval - *wp1;
          wsize = !(*wp1 == UINT64_C(0));
        } else {
          *wp1 = *wp1 - uval;
          wsize = -1;
        }
      } else {
        vp1 = PTR(v);
        if (uval >= *vp1) {
          *wp1 = uval - *vp1;
          wsize = !(*wp1 == UINT64_C(0));
        } else {
          *wp1 = *vp1 - uval;
          wsize = -1;
        }
        (void)(v);
      }
      SIZ(w) = wsize;
      (void)(w);
      return;
    } else {
      if (vsize == 0) {
        wp2 = PTR(w);
        *wp2 = uval;
        wsize = !(uval == UINT64_C(0));
        SIZ(w) = wsize;
        (void)(w);
        return;
      } else {
        vsize = -vsize;
        wp3 = wmpz_realloc(w, vsize + 1);
        if (vw) {
          cy = wmpn_add_1_in_place(wp3, vsize, uval);
          wp3[vsize] = cy;
          wsize = vsize + !(cy == UINT64_C(0));
        } else {
          vp2 = PTR(v);
          cy1 = wmpn_add_1(wp3, vp2, vsize, uval);
          wp3[vsize] = cy1;
          wsize = vsize + !(cy1 == UINT64_C(0));
          (void)(v);
        }
        SIZ(w) = wsize;
        (void)(w);
        return;
      }
    }
  }
}
