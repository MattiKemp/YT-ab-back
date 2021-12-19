#ifndef SALTING_H
#define SALTING_H
#include <string>
/* compile with :
 * g++ -o out SHA-256_salting.cpp -lssl -lcrypto
 */

using namespace std;

/**
 * Provides static security related methods.
 */

//calls the SHA256 hash directly, docs recommend using a higher level interface
//called EVP so other hash functions could be used in the future wihout needing to do 
//significant rewrites
string sha256(const string str);

/**
 * Generates random bytes and returns them in hex. The number of bytes
 * generated is based on the input size. SHA-256 requires a size of 32.
 * @param size number of random bytes to generate.
 * @return random bytes in hex.
 */
string get_salt(int size);

/**
 * Generates a 32 byte random salt and hashes the input string with the salt.
 * @param str string to hash with random salt. (max 256 length)
 * @return salted and hashed string in hex.
 */
string sha256_with_salt(string str);

/**
 * Salts and hashes a string with a given salt.
 * @param str string to hash.
 * @param salt salt to hash with.
 * @return salted and hashed string in hex.
 */
string sha256_with_salt(string str, string salt);

#endif
