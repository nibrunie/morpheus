# morpheus  [![Build Status](https://travis-ci.org/nibrunie/morpheus.svg?branch=master)](https://travis-ci.org/nibrunie/morpheus)


## Introduction 
Morpheus aims at becoming an implementation of a Fully Homomorphic Encryption scheme based on the Ring-LWE problem. For now it implements Leveled Homomorphic Encryption with encrypt/decrypt of ciphertext plus homomorphic addition and multiplication between ciphertext.

An Homomorphic encryption scheme allows the evaluation of functions on encrypted ciphertext such that the results of those evaluations appears once the final ciphertext is decrypted. Known since 1978, it has become more of a reality since the breakthrough work of Craig Gentry Thesis in 2009.


## Todo 
There are (lots of) things to be done, here is a non-exhaustive list:
- Implement squashing: transform the somewhat homomorphic encryption into a fully homomorphic encryption scheme by implementation a encrypted version of the decryption circuits
- Implement support for larger integer fields using GMP
- Implement proper sampling for random encryption polynomial, gaussian sampled error and secret
- Bound wrt parameters the depth of circuit computable
- Implement simpler homomorphic operation helper so any binary circuit can be implemented
- Measure and optimize operations latency

## References 
This library is based on many theoretical and pratical works:
- Fully Homomorphic Encryption from Ring-LWE and Security for Key Dependent Messages, by Z. Brakerski and V. Vaikuntanathan
- [A Fully Homomorphic Encryption Scheme](https://crypto.stanford.edu/craig/), C. Gentry 
