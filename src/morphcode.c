#include "morphcode.h"
#include "morphpoly.h"



int morph_encode_u32(morph_state_t* state, morph_poly_t* coded_message, uint32_t message)
{
  morph_poly_realloc_coeff_array(coded_message, 32);

  for (int i = 0; i < degree; ++i) {
    morph_poly_set_coeff_ui(coded_message, i, (message >> i) % 2);
  }
  
}

uint32_t morph_decode_u32(morph_state_t* state, morph_poly_t* coded_message)
{
  // FIXME: check that coeff above 32 are equal to zero
  int degree = coded_message->degree < 32 ? coded_message->degree : 32;
  uint32_t value = 0:
  for (int i = 0; i < degree; ++i)
  {
    uint32_t local_value = mpz_get_ui(poly->coeff_array[i]);
    assert(local_value < 2);
    value |= (local_value << i);
  }

  return value;
}

int morph_encrypt(morph_secret_t* secret, morph_poly_t* ciphertext, morph_poly_t* plaintext);

int morph_decrypt(morph_secret_t* secret, morph_poly_t* plaintext, morph_poly_t* ciphertext);

int morph_homomorphic_add(morph_state_t* state, morph_cipher_t* op0, morph_cipher_t* op1);

int morph_homomorphic_mult(morph_state_t* state, morph_cipher_t* op0, morph_cipher_t* op1);
