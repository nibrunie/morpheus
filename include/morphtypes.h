#include <gmp.h>
#include <stdint.h>

typedef struct {
  /** degree of the polynomial mod ring */
  int n;

  /** prime used to build Z_q, field for coefficients */
  int q;
} morph_state_t;

typedef struct {
  int32_t coeff_array*;
  int degree;

  morph_state_t* state;
} morph_poly_t;

typedef struct {
  morph_poly_t* poly_array;
  int size;
} morph_cipher_t;

typedef struct {
  morph_poly_t secret_s;

  morph_random_distrib_t distrib_e;

  morph_random_distrib_t distrib_a;

  morph_state_t state;
} morph_secret_t;

