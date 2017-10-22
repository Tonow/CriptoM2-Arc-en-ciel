#include <stdio.h>
#include <string.h>
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

int char2int(unsigned char input)
{
  if(input >= '0' && input <= '9')
    return input - '0';
  if(input >= 'A' && input <= 'F')
    return input - 'A' + 10;
  if(input >= 'a' && input <= 'f')
    return input - 'a' + 10;
  throw std::invalid_argument("Invalid input string");
}

void hex2bin(unsigned char* src,unsigned char* target)
{
  while(*src && src[1])
  {
    *(target++) = char2int(*src)*16 + char2int(src[1]);
    src += 2;
  }
}
