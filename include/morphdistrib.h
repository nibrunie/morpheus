#include <gmp.h>

typedef struct {
  mpz_t mean;
  mpz_t deviation;
} morph_gaussian_distrib_t;

typedef struct {
  mpz_t lower, upper;
} morph_uniform_distrib_t;
