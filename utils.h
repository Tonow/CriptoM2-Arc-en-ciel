#include <iostream>
#include <string>
#include <vector>


/**
*Hache un texte en entrer et retourn un chiffre pas la fonction MD5
*/
void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);

/**
*Hache un texte en entrer et retourn un chiffre pas la fonction SHA
*/
void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);


int char2int(unsigned char input);
/**
*This function assumes src to be a zero terminated sanitized string with
*an even number of [0-9a-f] characters, and target to be sufficiently large
*/
void hex2bin(unsigned char* src,unsigned char* target);
