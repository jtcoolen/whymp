Version 0.4
-----------

- fixed poor performance of division due to non-inlined shifts
- fixed name of `wmpz_mul_2exp`
- added `wmpz_neg`, `wmpz_realloc2`

Version 0.3
-----------

- fixed memory leak in `wmpz_mul`
- added `wmpz_get_str`, `wmpz_set_str`, `wmpz_tdiv_qr`
- added `wmpz_cmpabs`, `wmpz_abs`, `wmpz_sgn`

Version 0.2
-----------

- early support for mpz layer
- added `wmpn_powm`
- added header `wmp-gmp.h` to substitute GMP functions with WhyMP ones

Version 0.1
-----------

- initial release
