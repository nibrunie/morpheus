
#include "morphtypes.h"

/** \defgroup code Morpheus Code
 *  \brief API to implementing homomorphic encryption code: encode/decode
 *       and basic operations
 *  @{
 */

/** Allocate a new cipher
 *  @param size size of the cipher to generate
 *  @return a new cipher object
 */
morph_cipher_t* morph_cipher_new(int size);

/** Encode a message from a 32-bit unsigned integer to a polynomial
 * @param message data to be encoded
 * @param coded_message result polynomial
 * @param state morpheus state used to processe the coding
 * @return 0 on success, non zero error code otherwise
 */
int morph_encode_u32(morph_state_t* state, morph_poly_t* coded_message, uint32_t message);

/** Decode an unsigned 32-bit value from a coded polynomial
 *  @param coded_message message to be decoded
 *  @param state Morpheus state used to process the decoding
 *  @return 32-bit unsigned decoded value
 */
uint32_t morph_decode_u32(morph_state_t* state, morph_poly_t* coded_message);

/** Encrypt @p plaintext into @p ciphertext
 *  @param plaintext plain data to be encrypted
 *  @param ciphertext resulting encrypted data
 *  @param secret Morpheus secret used to process the encryption 
 *  @return 0 if success, non-zero error code otherwise
 */
int morph_encrypt(morph_secret_t* secret, morph_cipher_t* ciphertext, morph_poly_t* plaintext);

/** Decrypt @p plaintext from @p ciphertext
 *  @param ciphertext encrypted data to be decrypted
 *  @param plaintext resulting decrypted plain data 
 *  @param secret Morpheus secret used to process the encryption 
 *  @return 0 if success, non-zero error code otherwise
 */
int morph_decrypt(morph_secret_t* secret, morph_poly_t* plaintext, morph_cipher_t* ciphertext);

/** Perform homomorphic addition (Ring addition) on ciphertexts
  * @param state Morpheus state used to process the homomorphic operation
  * @param op0 first operand
  * @param op1 second operand
  * @return error code, 0 on success, non-zero otherwise
  */
int morph_homomorphic_add(morph_state_t* state, morph_cipher_t* result, morph_cipher_t* op0, morph_cipher_t* op1);

/** Perform homomorphic multiplication (Ring multiplication) on ciphertexts
  * @param state Morpheus state used to process the homomorphic operation
  * @param op0 first operand
  * @param op1 second operand
  * @return error code, 0 on success, non-zero otherwise
  */
int morph_homomorphic_mult(morph_state_t* state, morph_cipher_t* result, morph_cipher_t* op0, morph_cipher_t* op1);


/** Squash the input cipher text into a reduced cipher text
 *  to provide full homomorphic capabilities from somewhat homomorphic capabilities
 */
int morph_homomorphic_recrypt(morph_state_t* state, morph_cipher_t* result, morph_cipher_t* op);

int morph_generate_recrypt(morph_recrypt_pk_t* pk, morph_recrypt_sk_t* sk, morph_secret_t* secret, int m, int l, int D);


void  morph_cipher_realloc(morph_cipher_t* cipher, int size);

/** Display a cipher
 *  @param title text to display before object
 *  @param cipher cipher object to be displayed
 *  @param footer text to display after object 
 */
void morph_cipher_display(char* title, morph_cipher_t* cipher, char* footer);

/** normalize the given cipher under a new modulo
 *  @param result operation result
 *  @param op input cipher
 *  @param new_modulo momdulo to switch to
 */
void morph_cipher_switch_modulo(morph_cipher_t* result, morph_cipher_t* op, int new_modulo);

/** @} */ // End of Doxygen's code group
