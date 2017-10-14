#include <string>
#include <iostream>
#include <sstream>
#include <openssl/md5.h>
#include <openssl/sha.h>

#include "utils.h"

using namespace std;

/**
*Hache un texte en entrer et retourn un chiffre pas la fonction MD5
*/
void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
  MD5(pPlain, nPlainLen, pHash);
}

/**
*Hache un texte en entrer et retourn un chiffre pas la fonction SHA
*/
void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
  SHA1(pPlain, nPlainLen, pHash);
}
