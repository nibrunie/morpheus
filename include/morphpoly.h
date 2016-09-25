#include "morphtypes.h"

/** Allocate a new polynomial of degree @p degree with all coefficients
 *  equal to zero
 *  @param degree degree of the polynomial to be allocated
 *  @return a pointer toward the new polynomial
 */
morph_poly_t*  morph_poly_new(morph_state_t* state, int degree);

void morph_poly_free_coeff_array(morph_poly_t* poly); 

void morph_poly_free(morph_poly_t* poly);

void morph_poly_realloc_coeff_array(morph_poly_t* poly, int degree); 

void morph_poly_add(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1);

void morph_poly_sub(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1);

void morph_poly_mult(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1);

void morph_poly_mod(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1);

void morph_poly_neg(morph_poly_t* result, morph_poly_t* op0);

void morph_poly_sample(morph_random_distrib_t distrib, morph_poly_t* result);

void morph_poly_set_coeff_ui(morph_poly_t* poly, int index, uint32_t value);

uint32_t morph_poly_get_coeff_ui(morph_poly_t* poly, int index);
