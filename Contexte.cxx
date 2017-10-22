#include "Contexte.h"
#include "ArcEnCiel.h"
#include "utils.h"

#include <iostream>
#include <cstdint>
#include <math.h>

using namespace std;

// fonction de hachage
// In: Clair c ----> Out: Empreinte (tableau de 16 octets (MD5) ou 20 octets (SHA1)
void Contexte::h( string c, byte d[] )
    {
        unsigned char* pPlain = (unsigned char*) c.c_str();
        int nPlainLen = c.length();
        unsigned char* pHash = d;
        HashMD5(pPlain, nPlainLen, pHash);

        // // pour l'affichage
        // char mdString[33];
        // for (int i = 0; i < 16; i++)
        // {
        //     sprintf(&mdString[i*2], "%02x", (unsigned int)pHash[i]);
        // }
        //
        // printf("md5 digest: %s\n", mdString);
    }

// In: position t, empreinte d ---> Retourne index
uint64 Contexte::h2i( uint64 t, const byte d[] )
    {
        uint64* ptr = (uint64*) d; // le tableau de caractères est vu comme un tableau de grand nombre.
        uint64 i = *ptr; // par définition le nombre stocké dans t[0-7].

        uint64 index;
        index = (i + t) % _N;

        //std::cout << " --> h2i " << index << '\n';
        return index;
    }

// In: index idx ----> Out: Clair c
string Contexte::i2c( uint64 idx )
    {
        //cout << "index = " << idx << endl;
        char lettre_i;
        string sClair;
        //cout << "mot taille max = " << _mot_taille_max << "\n" << endl;
        //cout << "les lettres sont : " << _lettres << "\n" << endl;
        for (int i = _mot_taille_max - 1; i >= 0; i--)
        {

            uint64 position_lettre = pow(_nb_lettres,i);

            //cas Puissance n
            if ((idx >= position_lettre) && (i > 0))
            {
                uint64 position_alphabet_lettre_i =((uint64) (idx / position_lettre) % _nb_lettres);
                lettre_i = (char) (position_alphabet_lettre_i + 'a');
                idx = idx - (position_alphabet_lettre_i * position_lettre) ;
            }

            //cas Puissance 0
            else if (i==0)
            {
                lettre_i = (char) (idx + 'a');
            }

            //cas indice inferieure Puissance n
            else
            {
                lettre_i = (char) ('a');
            }
            sClair += lettre_i;
        }

        //string sClair(cClair);
        //std::cout << "\n" << '\n';

        int a = 0;
        for(std::string::iterator it = sClair.begin(); it != sClair.end(); ++it) {
            //cout << "indice de la chaine : " << a << " sClair vaut " << sClair[a] << endl;
            a++;
        }

        //std::cout << '\n' << "  --> le clair est : " <<sClair << "\n" << std::endl;
        return sClair;
    }

// In: index idx ----> retourne index (la composée des précédentes)
uint64 Contexte::i2i( uint64 idx , uint64 t) //TODO verifier
    {
        string clair_i2c =  i2c(idx);
        h( clair_i2c, empreinte );
        idx = h2i(t, empreinte);

        //std::cout << " clair_i2c --> "<< clair_i2c << "   ...       i2i --> " << idx << '\n';
        return idx;
    }

// Retourne un indice aléatoire valide.
uint64 Contexte::randIndex()
    {
        unsigned long n1 = random();
        unsigned long n2 = random();
        uint64 n = ( (uint64) n2 ) + ( ( (uint64) n1 ) << 32 );
        return n;
    }
