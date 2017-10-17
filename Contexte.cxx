#include "Contexte.h"
#include <cstdint>

using namespace std;

// fonction de hachage
// In: Clair c ----> Out: Empreinte (tableau de 16 octets (MD5) ou 20 octets (SHA1)
void Contexte::h( string c, byte d[] )
    {
        //TODO
    }

// In: position t, empreinte d ---> Retourne index
uint64_t Contexte::h2i( uint64_t t, const byte d[] )
    {
        //TODO
    }

// In: index idx ----> Out: Clair c
string Contexte::i2c( uint64_t idx )
    {
        //TODO
    }

// In: index idx ----> retourne index (la composée des précédentes)
uint64_t Contexte::i2i( uint64_t idx )
    {
        //TODO
    }

// Retourne un indice aléatoire valide.
uint64_t Contexte::randIndex()
    {
        unsigned long n1 = random();
        unsigned long n2 = random();
        uint64_t n = ( (uint64_t) n2 ) + ( ( (uint64_t) n1 ) << 32 );
        return n;
    }
