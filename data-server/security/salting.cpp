#include "salting.h"
#include <openssl/bio.h> //Input/output streams
#include <openssl/err.h> //errors
#include <openssl/ssl.h> //core lib
#include <openssl/rand.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
//#include "database/async/async_db.h"
/* compile with :
 * g++ -o out SHA-256_salting.cpp -lssl -lcrypto
 */

using namespace std;

// sqweeps from: https://stackoverflow.com/questions/14050452/how-to-convert-byte-array-to-hex-string-in-visual-c
string hexStr(unsigned char *data, int len)
{
     std::stringstream ss;
     ss << std::hex;

     for( int i(0) ; i < len; ++i )
         ss << std::setw(2) << std::setfill('0') << (int)data[i];

     return ss.str();
}

//calls the SHA256 hash directly, docs recommend using a higher level interface
//called EVP so other hash functions could be used in the future wihout needing to do 
//significant rewrites
string sha256(const string str){
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, str.c_str(), str.size());
	SHA256_Final(hash, &sha256);
	stringstream ss;
	for(int i=0; i < SHA256_DIGEST_LENGTH; i++){
		ss << hex << setw(2) << setfill('0') << (int)hash[i];
	}

	return ss.str();
}

string get_salt(int size){

	if(!(RAND_status())){
		cout << "uh oh, the PRNG did not seed correctly (OS Dependent)" << endl;
	}
	unsigned char buf[32];
	//generate 32 random bytes and store in the buffer
	RAND_bytes(buf, 32);
	//string str = "";
	//there is probably a bette way to do this
	//for(int i=0; i<sizeof(buf); i++){
	//	str += (int)buf[i];
	//}
    //string str(buf, buf + sizeof buf / sizeof buf[0]);
	return hexStr(buf, 32);
}

string sha256_with_salt(string str){

	//nvm just use a prng within openssl
	str += get_salt(32);
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, str.c_str(), str.size());
	SHA256_Final(hash, &sha256);
	stringstream ss;
	for(int i=0; i < SHA256_DIGEST_LENGTH; i++){
		ss << hex << setw(2) << setfill('0') << (int)hash[i];
	}

	return ss.str();
}

string sha256_with_salt(string str, string salt){
	//nvm just use a prng within openssl
    str += salt;
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, str.c_str(), str.size());
	SHA256_Final(hash, &sha256);
	stringstream ss;
	for(int i=0; i < SHA256_DIGEST_LENGTH; i++){
		ss << hex << setw(2) << setfill('0') << (int)hash[i];
	}

	return ss.str();
}

/*int main(){
    string salt = get_salt(32);
    cout << salt << endl;
    cout << sha256_with_salt("password", salt) << endl;
}*/

/*int main(){
    AsyncDB db = AsyncDB("test", "Password22!", "127.0.0.1");
    string salt = get_salt(32);
    cout << salt << '\n' << sha256_with_salt("password", salt) << endl;
    db.updateCreds("jack", sha256_with_salt("password", salt), salt);
    salt = get_salt(32);
    cout << salt << '\n' << sha256_with_salt("test", salt) << endl;
    db.updateCreds("jacob", sha256_with_salt("test", salt), salt);
    salt = get_salt(32);
    cout << salt << '\n' << sha256_with_salt("test2", salt) << endl;
    db.updateCreds("mark", sha256_with_salt("test2", salt), salt);
    salt = get_salt(32);
    cout << salt << '\n' << sha256_with_salt("12345", salt) << endl;
    db.updateCreds("matt", sha256_with_salt("12345", salt), salt);
    return 0;
}*/

