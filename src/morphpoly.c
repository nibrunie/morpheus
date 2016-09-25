#include "morphpoly.h"

void morph_poly_init_coeff_array(int degree)
{

  /*poly->coeff_array = malloc(sizeof(mpz_t) * degree);
  for (int i = 0; i < degree; ++i) {
    mpz_init(poly->coeff_array[i]);
  }*/
  poly->coeff_array = malloc(sizeof(int32_t) * degree);
  for (int i = 0; i < degree; ++i) {
    poly->coeff_array[i] = 0;
  }
}

morph_poly_t*  morph_poly_new(morph_state_t* state, int degree)
{
  poly->state = state;

  morph_poly_t* poly = malloc(sizeof(morph_poly_t));
  poly->degree = degree;

  morph_poly_init_coeff_array(poly->degree);

  return poly;
}

void morph_poly_free_coeff_array(morph_poly_t* poly) 
{
  /*for (int i = 0; i < poly->degree; ++i) {
    mpz_clear(poly->coeff_array[i]);
  }*/

  free(poly->coeff_array);
}

void morph_poly_free(morph_poly_t* poly) 
{
  morph_poly_free_coeff_array(poly);

  free(poly);
}

void morph_poly_realloc_coeff_array(morph_poly_t* poly, int degree) 
{
  if (poly->degree >= degree) {
    for (int i = 0; i < poly->degree; ++i) {
      morph_poly_set_coeff_ui(poly, i, 0);
    }
  } else {
    poly->coeff_array = realloc(poly->coeff_array, sizeof(int32_t) * degree);

    for (int i = poly->degree; i < degree; ++i) {
      poly->coeff_array[i] = 0;
    }

    poly->degree = degree;
  }
}

void morph_poly_set_coeff_ui(morph_poly_t* poly, int index, uint32_t value)
{
  poly->coeff_array[index] = value;
  //  mpz_set_ui(poly->coeff_array[index], value); 
}

uint32_t morph_poly_get_coeff_ui(morph_poly_t* poly, int index)
{
  return poly->coeff_array[index];
  //  mpz_get_ui(poly->coeff_array[index]); 
}


void morph_poly_add(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1)
{
  int max_degree = op0->degree > op1->degree ? op0->degree : op1->degree;
  if (result->degree < max_degree) {
    morph_poly_realloc_coeff_array(poly, max_degree);
  }

  for (i = 0; i < max_degree; ++i) {
    int32_t c0 = 0, c1 = 0;
    if (i < op0->degree) c0 = op0->coeff_array[i];
    if (i < op1->degree) c1 = op1->coeff_array[i];
    coeff_array[i] = c0 + c1;
  }
  for (; i < result->degree; ++i) morph_poly_set_coeff_ui(i, 0);
}

void morph_poly_sub(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1)
{
  int max_degree = op0->degree > op1->degree ? op0->degree : op1->degree;
  if (result->degree < max_degree) {
    morph_poly_realloc_coeff_array(poly, max_degree);
  }

  for (i = 0; i < max_degree; ++i) {
    int32_t c0 = 0, c1 = 0;
    if (i < op0->degree) c0 = op0->coeff_array[i];
    if (i < op1->degree) c1 = op1->coeff_array[i];
    coeff_array[i] = c0 - c1;
  }
  for (; i < result->degree; ++i) morph_poly_set_coeff_ui(i, 0);
}

void morph_poly_neg(morph_poly_t* result, morph_poly_t* op0)
{
  if (result->degree < op0->degree) {
    morph_poly_realloc_coeff_array(poly, op0->degree);
  }


  for (i = 0; i < op0->degree; ++i) {
    coeff_array[i] = - op0->coeff_array[i];
  }
  for (; i < result->degree; ++i) morph_poly_set_coeff_ui(i, 0);
}

void morph_poly_mult(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1)
{
  assert(result != op0 && result != op1);
  int degree = op0->degree + op1->degree;
  if (result->degree < degree) {
    morph_poly_realloc_coeff_array(poly, degree);
  }
  for (int i = 0; i < result->degree; ++i) morph_poly_set_coeff_ui(result, i, 0);

  for (int i = 0; i < op0->degree; ++i) {
    int64_t multiplier = op0->coeff_array[i];
    for (int j = 0; j < op1->degree; ++j) {
      int64_t multiplicand = op1->coeff_array[j];
      int64_t coeff = result->coeff_array[i+j] + multiplicand * multiplier;
      coeff %= result->state->q;
      result->coeff_array[i+j] = coeff;
    }
  }
}

void morph_poly_mod(morph_poly_t* result, morph_poly_t* op, morph_poly_t* mod)
{

}

