#include "Contexte"

using namespace std;


// fonction de hachage


// In: Clair c ----> Out: Empreinte
void h( String c, Condense & d )
    {
        //TODO
    }

// In: position t, empreinte d ---> Retourne index
uint64 h2i( uint64 t, Condense & d )
    {
        //TODO
    }

// In: index idx ----> Out: Clair c
void i2c( uint64 idx, String & c )
    {
        //TODO
    }

// In: index idx ----> retourne index (la composée des précédentes)
uint64 i2i( uint64 idx )
    {
        //TODO
    }

// Retourne un indice aléatoire valide.
uint64 randIndex()
    {
        unsigned long n1 = random();
        unsigned long n2 = random();
        uint64 n = ( (uint64) n2 ) + ( ( (uint64) n1 ) << 32 );
        return n;
    }
