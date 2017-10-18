#include "Contexte.h"
#include <iostream>
#include <cstdint>
#include <math.h>

using namespace std;

// fonction de hachage
// In: Clair c ----> Out: Empreinte (tableau de 16 octets (MD5) ou 20 octets (SHA1)
void Contexte::h( string c, byte d[] )
    {
        //TODO
    }

// In: position t, empreinte d ---> Retourne index
uint64 Contexte::h2i( uint64 t, const byte d[] )
    {
        //TODO
        return 0;
    }

// In: index idx ----> Out: Clair c
string Contexte::i2c( uint64 idx )
    {
        char lettre_i;
        char cClair[_mot_taille_max];
        for (int i = _mot_taille_max; i > 0 ; i--) {
            uint64 position_lettre = pow(_nb_lettres,i);
            if (idx > position_lettre) {
                uint64 position_alphabet_lettre_i = (idx / _nb_lettres) % _nb_lettres;
                lettre_i = (char) (position_alphabet_lettre_i + 'a');
                idx = idx - position_alphabet_lettre_i;
            }
            else{
                lettre_i = (char) ('a');
            }
            cClair[i] = lettre_i;
        }

        string sClair(cClair);
        std::cout << "nb lettre : " << _nb_lettres <<'\n';
        std::cout << sClair << std::endl;
        return sClair;
    }

// In: index idx ----> retourne index (la composée des précédentes)
uint64 Contexte::i2i( uint64 idx )
    {
        //TODO
        return 0;
    }

// Retourne un indice aléatoire valide.
uint64 Contexte::randIndex()
    {
        unsigned long n1 = random();
        unsigned long n2 = random();
        uint64 n = ( (uint64) n2 ) + ( ( (uint64) n1 ) << 32 );
        return n;
    }
