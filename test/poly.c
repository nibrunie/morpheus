#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>
#include <assert.h>

#include "morphpoly.h"
#include "morphcode.h"


int main() {
  morph_poly_t* a, *b, *c;

  morph_state_t state;
  state.n = 256;
  state.q = 2;
  state.poly_mod = morph_poly_new(NULL, 257);
  morph_poly_set_coeff_ui(state.poly_mod, 0, 1);
  morph_poly_set_coeff_ui(state.poly_mod, 256, 1);

  printf("allocating polynomials\n");
  a = morph_poly_new(&state, 256);
  b = morph_poly_new(&state, 256);
  c = morph_poly_new(&state, 256);

  uint32_t ua = 0xffff, ub = 0x1;

  morph_encode_u32(&state, a, ua);
  morph_encode_u32(&state, b, ub);

  morph_poly_add(c, a, b);
  uint32_t uc = morph_decode_u32(&state, c);
  printf("poly add %"PRIx32" + %"PRIx32" = %"PRIx32" \n", ua, ub, uc);
  assert(uc == 0xfffe && "addition test failed");

  ub = 0x2;
  morph_encode_u32(&state, b, ub);
  morph_poly_mult(c, a, b);
  uc = morph_decode_u32(&state, c);
  printf("poly mult %"PRIx32" * %"PRIx32" = %"PRIx32" \n", ua, ub, uc);
  assert(uc == 0x1fffe && "multiplication test failed");

  ub = 0x10001, ua = 0x10000;
  morph_encode_u32(&state, a, ua);
  morph_encode_u32(&state, b, ub);
  morph_poly_mod(c, a, b);
  uc = morph_decode_u32(&state, c);
  printf("poly mod %"PRIx32" * %"PRIx32" = %"PRIx32" \n", ua, ub, uc);
  assert(uc == 0x1 && "modulo test failed");

  printf("freeing polynomials\n");
  morph_poly_free(a);
  morph_poly_free(b);
  morph_poly_free(c);

  morph_poly_free(state.poly_mod);

  return 0;
}
