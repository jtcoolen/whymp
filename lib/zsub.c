#include "zsub.h"
#include <stdint.h>

void wmpz_sub(wmpz_ptr w, wmpz_ptr u, wmpz_ptr v) {
  wmpz_ptr u1, v1;
  int32_t usize, vsize, abs_usize, abs_vsize, tmp_size, wsize;
  wmpz_ptr z;
  int uw, vw;
  uint64_t * wp;
  uint64_t * vp;
  uint64_t usb, usb1;
  uint64_t * up;
  uint64_t * up1;
  uint64_t * vp1;
  uint64_t usb2, usb3, usb4;
  uint64_t * vp2;
  uint64_t * up2;
  uint64_t usb5, usb6;
  uint64_t * up3;
  uint64_t * vp3;
  uint64_t usb7, usb8;
  uint64_t cy;
  uint64_t * vp4;
  uint64_t o, o1;
  uint64_t * up4;
  uint64_t * up5;
  uint64_t * vp5;
  uint64_t o2;
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
        usb = sub_rx(wp, abs_usize, vp, abs_vsize);
        (void)(v1);
      } else {
        if (vw) {
          up = PTR(u1);
          usb1 = sub_ry(up, abs_usize, wp, abs_vsize);
          (void)(u1);
        } else {
          up1 = PTR(u1);
          vp1 = PTR(v1);
          usb2 = sub(wp, up1, abs_usize, vp1, abs_vsize);
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
          usb3 = sub_n_ry(vp2, wp, abs_usize);
          normalize(wp, &wsize);
          if (usize >= 0) {
            wsize = -wsize;
          }
        } else {
          usb4 = sub_n_rx(wp, vp2, abs_usize);
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
            usb5 = sub_n_rx(wp, up2, abs_usize);
            normalize(wp, &wsize);
            if (usize >= 0) {
              wsize = -wsize;
            }
          } else {
            usb6 = sub_n_ry(up2, wp, abs_usize);
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
            usb7 = sub_n(wp, vp3, up3, abs_usize);
            normalize(wp, &wsize);
            if (usize >= 0) {
              wsize = -wsize;
            }
          } else {
            usb8 = sub_n(wp, up3, vp3, abs_usize);
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
      o = add_rx(wp, abs_usize, vp4, abs_vsize);
      cy = o;
      (void)(v1);
    } else {
      if (vw) {
        up4 = PTR(u1);
        o1 = add_ry(up4, abs_usize, wp, abs_vsize);
        cy = o1;
        (void)(u1);
      } else {
        up5 = PTR(u1);
        vp5 = PTR(v1);
        o2 = add(wp, up5, abs_usize, vp5, abs_vsize);
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
  uint64_t o, o1;
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
      o = wmpn_add_1_in_place(wp1, abs_usize, v);
      cy = o;
    } else {
      up = PTR(u);
      o1 = wmpn_add_1(wp1, up, abs_usize, v);
      cy = o1;
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
