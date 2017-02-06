#pragma once

#include <gmp.h>
#include <stdint.h>


/** \defgroup types Morpheus Types
 *  \brief Morpheus basic data structures
 *  @{
 */

struct morph_poly_s;

/** Morpheus global parameters */
typedef struct 
{
  /** degree of the polynomial mod ring */
  int n;

  /** prime used to build Z_q, field for coefficients */
  int q;
  
  struct morph_poly_s* poly_mod;
} 
morph_state_t;


/** Morpheus polynomial structure */
typedef struct morph_poly_s 
{
  /** array of polynomial coefficients */
  int32_t* coeff_array;

  /** degree of the polynomial */
  int degree;

  /** Morpheus state associated with the polynomial */
  morph_state_t* state;
} 
morph_poly_t;

/** Morpheus cipher structure */
typedef struct {
  /** Array of polynomials */
  morph_poly_t** poly_array;

  /** size of the array polynomial */
  int size;
} 
morph_cipher_t;

/** Types of random distribution */
typedef enum {
  /** undefined distribution */
  DISTRIB_NONE = 0,
  /** uniform distribution */
  DISTRIB_UNIFORM,
  /** gaussian distribution */
  DISTRIB_GAUSSIAN
} 
morph_distrib_type_t;

/** Morpheus random distrbution structure */
typedef struct {
  /** Gaussian distribution parameters */
  struct {
    /** distribution mean value */
    int32_t mean;
    /** distribution mean deviation value */
    int32_t deviation;
  } gaussian;

  /** Uniform distribution parameters */
  struct { 
    /** lower bound of the distribution range */
    int32_t lower;
    /** upper bound of the distribution range */
    int32_t upper;
  } uniform;

  /** Type of the random distribution */
  morph_distrib_type_t type;
} 
morph_random_distrib_t;

/** Morpheus recrypt public key */
typedef struct {
  /** m parameter */
  int m;

  /** number of polynomial in each z_i */
  int D;

  /** array of m (z_i,0 ... z_i,D) element */
  morph_cipher_t** z_array;
} morph_recrypt_pk_t;

/** Morpheus recrypt secret key */
typedef struct {
  /** size of the sparse index array */
  int l;
  /** index of secret sparse coefficient */
  int* sparse_index_array;
} morph_recrypt_sk_t;

/** Morpheus secret structure */
typedef struct {
  /** Secret polynomial */
  morph_poly_t* secret_s;

  /** Random distribution e (error distribution)*/
  morph_random_distrib_t distrib_e;

  /** random distribution a (random parameter distribution) */
  morph_random_distrib_t distrib_a;

  /** State */
  morph_state_t* state;
} 
morph_secret_t;

/** @} */ // End of Doxygen's types group
