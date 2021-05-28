#ifndef __WMP_H__

#include <gmp.h>
#include "wmp.h"

#undef mpn_add
#undef mpn_add_1
#undef mpn_add_n
#undef mpn_addmul_1
#undef mpn_cmp
#undef mpn_copyd
#undef mpn_copyi
#undef mpn_divrem_1
#undef mpn_get_str
#undef mpn_lshift
#undef mpn_mul
#undef mpn_mul_1
#undef mpn_mul_n
#undef mpn_powm
#undef mpn_rshift
#undef mpn_set_str
#undef mpn_sqrtrem
#undef mpn_sub
#undef mpn_sub_1
#undef mpn_sub_n
#undef mpn_submul_1
#undef mpn_tdiv_qr
#undef mpn_zero
#undef mpn_zero_p

#undef mpz_abs
#undef mpz_add
#undef mpz_add_ui
#undef mpz_clear
#undef mpz_cmp
#undef mpz_cmp_si
#undef mpz_cmp_ui
#undef mpz_cmpabs
#undef mpz_cmpabs_ui
#undef mpz_get_str
#undef mpz_get_ui
#undef mpz_init
#undef mpz_mul
#undef mpz_mul_2exp
#undef mpz_mul_si
#undef mpz_mul_ui
#undef mpz_neg
#undef mpz_realloc
#undef mpz_realloc2
#undef mpz_set_si
#undef mpz_set_str
#undef mpz_set_ui
#undef mpz_sgn
#undef mpz_sub
#undef mpz_sub_ui
#undef mpz_tdiv_q_2exp
#undef mpz_tdiv_qr
#undef mpz_tdiv_qr_ui
#undef mpz_ui_sub

#define mpn_add wmpn_add
#define mpn_add_1 wmpn_add_1
#define mpn_add_n wmpn_add_n
#define mpn_addmul_1 wmpn_addmul_1
#define mpn_cmp wmpn_cmp
#define mpn_copyd wmpn_copyd
#define mpn_copyi wmpn_copyi
#define mpn_divrem_1 wmpn_divrem_1
#define mpn_get_str wmpn_get_str
#define mpn_lshift wmpn_lshift
#define mpn_mul wmpn_mul
#define mpn_mul_1 wmpn_mul_1
#define mpn_mul_n wmpn_mul_n
#define mpn_powm wmpn_powm
#define mpn_rshift wmpn_rshift
#define mpn_set_str wmpn_set_str
#define mpn_sqrtrem wmpn_sqrtrem
#define mpn_sub wmpn_sub
#define mpn_sub_1 wmpn_sub_1
#define mpn_sub_n wmpn_sub_n
#define mpn_submul_1 wmpn_submul_1
#define mpn_tdiv_qr wmpn_tdiv_qr
#define mpn_zero wmpn_zero
#define mpn_zero_p wmpn_zero_p

#define mpz_abs wmpz_abs
#define mpz_add wmpz_add
#define mpz_add_ui wmpz_add_ui
#define mpz_clear wmpz_clear
#define mpz_cmp wmpz_cmp
#define mpz_cmp_si wmpz_cmp_si
#define mpz_cmp_ui wmpz_cmp_ui
#define mpz_cmpabs wmpz_cmpabs
#define mpz_cmpabs_ui wmpz_cmpabs_ui
#define mpz_get_str wmpz_get_str
#define mpz_get_ui wmpz_get_ui
#define mpz_init wmpz_init
#define mpz_mul wmpz_mul
#define mpz_mul_2exp wmpz_mul_2exp
#define mpz_mul_si wmpz_mul_si
#define mpz_mul_ui wmpz_mul_ui
#define mpz_neg wmpz_neg
#define mpz_realloc wmpz_realloc
#define mpz_realloc2 wmpz_realloc2
#define mpz_set_si wmpz_set_si
#define mpz_set_str wmpz_set_str
#define mpz_set_ui wmpz_set_ui
#define mpz_sgn wmpz_sgn
#define mpz_sub wmpz_sub
#define mpz_sub_ui wmpz_sub_ui
#define mpz_tdiv_q_2exp wmpz_tdiv_q_2exp
#define mpz_tdiv_qr wmpz_tdiv_qr
#define mpz_tdiv_qr_ui wmpz_tdiv_qr_ui
#define mpz_ui_sub wmpz_ui_sub

#endif
