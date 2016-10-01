# morpheus


== Introduction ==

Morpheus aims at becoming an implementation of a Fully Homomorphic Encryption scheme based on the Ring-LWE problems. For now it implements Leveled Homomorphic Encryption with encrypt/decrypt of ciphertext plus homomorphic addition and multiplication between ciphertext.

== Todo ==
- Implement squashing: transform the somewhat homomorphic encryption into a fully homomorphic encryption scheme by implementation a encrypted version of the decryption circuits
- Implement support for larger integer fields using GMP
- Implement proper sampling for random encryption polynomial, gaussian sampled error and secret
- Bound wrt parameters the depth of circuit computable
- Implement simpler homomorphic operation helper so any binary circuit can be implemented
- Measure and optimize operations latency

== References ==
- Fully Homomorphic Encryption from Ring-LWE and Security for Key Dependent Messages, by Z. Brakerski and V. Vaikuntanathan
