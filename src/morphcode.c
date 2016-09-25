#include "morphcode.h"
#include "morphpoly.h"


morph_cipher_t* morph_cipher_new(int size)
{
  morph_cipher_t* new_cipher = malloc(sizeof(morph_cipher_t));
  new_cipher->poly_array = malloc(sizeof(morph_poly_t*) * size);
  new_cipher->size = size;

  for (int i = 0; i < size; ++i) new_cipher->poly_array[i] = NULL;

  return new_cipher;
}

void  morph_cipher_realloc(morph_cipher_t* cipher, int size)
{
  if (size <= cipher->size) return;
  new_cipher->poly_array = realloc(new_cipher->poly_array, sizeof(morph_poly_t*) * size);

  for (int i = cipher->size; i < size; ++i) new_cipher->poly_array[i] = NULL;
  new_cipher->size = size;

  return new_cipher;
}

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

int morph_encrypt(morph_secret_t* secret, morph_cipher_t* ciphertext, morph_poly_t* plaintext) 
{
  int n = secret->state->n;

  morph_poly_t* public_a = morph_poly_new(secret->state, n);
  morph_poly_sample(public_a, secret->distrib_a);

  morph_poly_t* secret_e = morph_poly_new(secret->state, n);
  morph_poly_sample(secret_e, secret->distrib_e);
  morph_poly_scale_ui(secret_e, secret_e, 2);

  morph_poly_mult(ciphertext, secret->secret_s, public_a);

  morph_poly_add(ciphertext, ciphertext, secret_e);

  morph_poly_add(ciphertext, ciphertext, plaintext);

  return 0;
}

int morph_decrypt(morph_secret_t* secret, morph_poly_t* plaintext, morph_poly_t* ciphertext) 
{
}

int morph_homomorphic_add(morph_state_t* state, morph_cipher_t* op0, morph_cipher_t* op1);

int morph_homomorphic_mult(morph_state_t* state, morph_cipher_t* op0, morph_cipher_t* op1);
