AUTOMAKE_OPTIONS = foreign subdir-objects no-dependencies

EXTRA_DIST = COPYING.md COPYING.GPLv3.md NEWS.md README.md

lib_LIBRARIES = libwmp.a

libwmp_a_SOURCES = \
  lib/uint32gmp.h lib/uint64gmp.h lib/fxp.h lib/c.h \
  lib/util.c lib/util.h lib/utilold.c lib/utilold.h \
  lib/logical.c lib/logical.h \
  lib/logicalold.c lib/logicalold.h \
  lib/baseinfo.c lib/baseinfo.h \
  lib/compare.c lib/compare.h \
  lib/add.c lib/add.h lib/sub.c lib/sub.h \
  lib/add_1.c lib/add_1.h lib/sub_1.c lib/sub_1.h \
  lib/addold.c lib/addold.h lib/subold.c lib/subold.h \
  lib/mul.c lib/mul.h lib/mul_basecase.c lib/mul_basecase.h lib/toom.c lib/toom.h \
  lib/div.c lib/div.h \
  lib/powm.c lib/powm.h lib/binverttab.h \
  lib/sqrt.c lib/sqrt.h lib/sqrt1.c lib/sqrt1.h lib/sqrtinit.h \
  lib/get_str.c lib/get_str.h \
  lib/set_str.c lib/set_str.h \
  lib/alias.h \
  lib/z.h lib/zutil.c lib/zutil.h lib/set.c lib/set.h lib/zadd.c lib/zadd.h \
  lib/zabs.c lib/zabs.h \
  lib/zcmp.c lib/zcmp.h \
  lib/zcmpabs.c lib/zcmpabs.h \
  lib/zsub.c lib/zsub.h lib/zmul.c lib/zmul.h \
  lib/zmul2exp.c lib/zmul2exp.h lib/zdiv2exp.c lib/zdiv2exp.h \
  lib/zneg.c lib/zneg.h \
  lib/zrealloc2.c lib/zrealloc2.h \
  lib/zdiv.c lib/zdiv.h \
  lib/zget_str.c lib/zget_str.h \
  lib/zset_str.c lib/zset_str.h

include_HEADERS = wmp.h wmp-gmp.h
