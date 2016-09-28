#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>
#include <assert.h>

#include "morphpoly.h"
#include "morphcode.h"
#include "morphdebug.h"


uint64_t emul_poly_mul(uint32_t a, uint32_t b)
{
  uint64_t tmp = 0;
  for (int i = 0; i < 32; ++i)
    if ((b >> i) & 1) tmp ^= (uint64_t) a << i;

  return tmp;
}

int main() {
  morph_poly_t* a, *b, *c;

  morph_state_t state;
  state.n = 256;
  state.q = 7681;
  state.poly_mod = morph_poly_new(NULL, state.n+1);
  morph_poly_set_coeff_ui(state.poly_mod, 0, 1);
  morph_poly_set_coeff_ui(state.poly_mod, state.n, 1);

  printf("allocating polynomials\n");
  a = morph_poly_new(&state, state.n);
  b = morph_poly_new(&state, state.n);
  c = morph_poly_new(&state, state.n);

  uint32_t ua = rand(), ub = rand();

  morph_encode_u32(&state, a, ua);
  morph_encode_u32(&state, b, ub);

  morph_random_distrib_t uni_distrib = {.type = DISTRIB_UNIFORM, .uniform = {.lower = 0, .upper = state.q}};
  morph_random_distrib_t distrib_e = {.type = DISTRIB_UNIFORM, .uniform = {.lower = 0, .upper = 0}};

  morph_secret_t _secret;
  morph_secret_t* secret =  &_secret;
  secret->secret_s = morph_poly_new(&state, state.n);
  morph_poly_sample(uni_distrib, secret->secret_s, state.n);

  secret->distrib_a = uni_distrib;
  secret->distrib_e = distrib_e;
  secret->state   = &state;

  morph_cipher_t* ca = morph_cipher_new(2);
  morph_cipher_t* cb = morph_cipher_new(2);
  morph_cipher_t* cc = morph_cipher_new(2);
  morph_cipher_t* cm = morph_cipher_new(2);

  morph_poly_t* deca = morph_poly_new(&state, state.n);
  morph_poly_t* decb = morph_poly_new(&state, state.n);
  morph_poly_t* decc = morph_poly_new(&state, state.n);
  morph_poly_t* decm = morph_poly_new(&state, state.n);

  morph_encrypt(secret, ca, a);
  morph_decrypt(secret, deca, ca);

  morph_encrypt(secret, cb, b);

  morph_homomorphic_add(&state, cc, ca, cb);

  morph_homomorphic_mult(&state, cm, ca, cb);

  morph_decrypt(secret, decb, cb);
  morph_decrypt(secret, decc, cc);
  morph_decrypt(secret, decm, cm);

  uint32_t da = morph_decode_u32(&state, deca);
  uint32_t db = morph_decode_u32(&state, decb);
  uint32_t dc = morph_decode_u32(&state, decc);
  uint32_t dm = morph_decode_u32(&state, decm);

  printf("ua = %"PRIx32" => da=%"PRIx32" \n", ua, da);
  assert(ua == da && "encode/decode failed");

  printf("ub = %"PRIx32" => db=%"PRIx32" \n", ub, db);
  assert(ub == db && "encode/decode failed");

  printf("homomorphic ua ^ ub = %"PRIx32" vs %"PRIx32" \n", dc, ua ^ ub);
  assert(dc == (ua ^ ub) && "homomorphic add failed");

  uint32_t emul_dm = emul_poly_mul(ua, ub);

  printf("homomorphic ua x ub = %"PRIx32" vs %"PRIx32" \n", dm, emul_dm);



  printf("freeing polynomials\n");
  morph_poly_free(a);
  morph_poly_free(b);
  morph_poly_free(c);

  morph_poly_free(deca);
  morph_poly_free(decb);
  morph_poly_free(decc);

  morph_poly_free(state.poly_mod);

  return 0;
}
