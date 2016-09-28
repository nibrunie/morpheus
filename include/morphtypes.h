#pragma once

#include <gmp.h>
#include <stdint.h>

struct morph_poly_s;

typedef struct 
{
  /** degree of the polynomial mod ring */
  int n;

  /** prime used to build Z_q, field for coefficients */
  int q;
  
  struct morph_poly_s* poly_mod;
} 
morph_state_t;

typedef struct morph_poly_s 
{
  int32_t* coeff_array;
  int degree;

  morph_state_t* state;
} 
morph_poly_t;

typedef struct {
  morph_poly_t** poly_array;
  int size;
} 
morph_cipher_t;

typedef enum {
  DISTRIB_NONE = 0,
  DISTRIB_UNIFORM,
  DISTRIB_GAUSSIAN
} 
morph_distrib_type_t;

typedef struct {
  struct {
    int32_t mean;
    int32_t deviation;
  } gaussian;

  struct { 
    int32_t lower;
    int32_t upper;
  } uniform;

  morph_distrib_type_t type;
} 
morph_random_distrib_t;

typedef struct {
  morph_poly_t* secret_s;

  morph_random_distrib_t distrib_e;

  morph_random_distrib_t distrib_a;

  morph_state_t* state;
} 
morph_secret_t;

