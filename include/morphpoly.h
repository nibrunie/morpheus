#include "morphtypes.h"

/** \defgroup poly Morpheus Polynomial
 *  \brief API of primitives for polynomial operations
 *  @{
 */

/** Allocate a new polynomial of degree @p degree with all coefficients
 *  equal to zero
 *  @param degree degree of the polynomial to be allocated
 *  @return a pointer toward the new polynomial
 */
morph_poly_t*  morph_poly_new(morph_state_t* state, int degree);


/** Copy a polynomial
 *  @param[in] op copy source
 *  @param[out] result destination
 */
void morph_poly_copy(morph_poly_t* result, morph_poly_t* op);

/** Free coefficient storage array 
 *  @param poly 
 */
void morph_poly_free_coeff_array(morph_poly_t* poly); 

/** Free polynomial object
 *  @param poly polynoimal to be freed
 */
void morph_poly_free(morph_poly_t* poly);

/** reset all coefficients of @p poly to zero
 *  @param poly polynomial to be reset
 */
void morph_poly_reset(morph_poly_t* poly);

/** change size of coefficient storage array to match @p degree
 *  @param poly polynomial object whose coefficient array is to be modified
 *  @param degree minimal degree which should fit in the newly re-allocated storage
 */
void morph_poly_realloc_coeff_array(morph_poly_t* poly, int degree); 

/** Polynomial addition @p result = @p op0 + @p op1
 *  @param[in] op0 left hand side addition operand
 *  @param[in] op1 right hand side addition operand
 *  @param[out] result operation result destination 
 */
void morph_poly_add(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1);

/** Polynomial subtraction @p result = @p op0 - @p op1
 *  @param[in] op0 left hand side subtraction operand
 *  @param[in] op1 right hand side subtraction operand
 *  @param[out] result operation result destination 
 */
void morph_poly_sub(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1);

/** Polynomial multiplication @p result = @p op0 * @p op1
 *  @param[in] op0 left hand side multiplication operand
 *  @param[in] op1 right hand side multiplication operand
 *  @param[out] result operation result destination 
 */
void morph_poly_mult(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1);

/** Polynomial modulo @p result = @p op0 % @p op1
 *  @param[in] op0 modulo input
 *  @param[in] op1 modulus operand
 *  @param[out] result operation result destination 
 */
void morph_poly_mod(morph_poly_t* result, morph_poly_t* op0, morph_poly_t* op1);

/** Polynomial negate @p result = - @p op
 *  @param[in] op  input
 *  @param[out] result operation result destination 
 */
void morph_poly_neg(morph_poly_t* result, morph_poly_t* op);

/** Randomly generate a polynomial
 *  @param[in] distrib random distribution to be used for coefficient generation
 *  @param[in] degree size of the polynomial to be generated
 *  @param[out] result destination of the generated polynomial
 */
void morph_poly_sample(morph_random_distrib_t distrib, morph_poly_t* result, int degree);

/** Set single coefficient unsigned int value
 *  @param poly input polynomial to be modified
 *  @param index index of the coefficient to be modified
 *  @param value new coefficient numerical value
 */
void morph_poly_set_coeff_ui(morph_poly_t* poly, int index, uint32_t value);

/** Set single coefficient unsigned int value
 *  @param poly input polynomial to be modified
 *  @param index index of the coefficient to be modified
 *  @param value new coefficient numerical value
 */
uint32_t morph_poly_get_coeff_ui(morph_poly_t* poly, int index);

/** Rescale a polynomial's coefficients
 *  @param[out] result destination storage
 *  @param[in]  op     source polynomial
 *  @param[in]  scale  numerical value to multiply each coefficient with
 */
void morph_poly_scale_ui(morph_poly_t* result, morph_poly_t* op, uint32_t scale);

/** Coefficient-wise Modulo reduction
 *  @param poly polynomial to be reduced 
 *  @param mod  numerical modulus value 
 */
void morph_poly_coeffs_mod_ui(morph_poly_t* poly, uint32_t mod);

/** Implement modulo switching technic
 *  @param[out] result destination of the polynomial result
 *  @param[in]  op input polynomial operand
 *  @param[in] new_modulo new modulus value
 */
void morph_poly_switch_modulo(morph_poly_t* result, morph_poly_t* op, int new_modulo); 
  
/** @} */ // End of Doxygen's poly group
