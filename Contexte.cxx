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
        cout << "index = " << idx << endl;
        char lettre_i;
        string sClair;
        cout << "mot taille max = " << _mot_taille_max << endl;
        for (int i = _mot_taille_max - 1; i >= 1; i--) {
            uint64 position_lettre = pow(_nb_lettres,i);

            //cas Puissance n
            if ((idx >= position_lettre) && (i > 0)) {
                cout << "if" << endl;
                cout << "idx entre : " << idx << endl;
                uint64 position_alphabet_lettre_i =((uint64) (idx / position_lettre) % _nb_lettres);
                lettre_i = (char) (position_alphabet_lettre_i + 'a');
                idx = idx - (idx - position_lettre);
                cout << "idx sortie: " << idx << endl;
            }

            //cas Puissance 1
            else if (i==1) {
                cout << "if" << endl;
                cout << "idx entre : " << idx << endl;
                uint64 position_alphabet_lettre_i =((uint64) (idx / position_lettre) % _nb_lettres);
                lettre_i = (char) (position_alphabet_lettre_i + 'a');
                idx = idx - (idx - _nb_lettres);
                cout << "idx sortie: " << idx << endl;
            }

            //cas Puissance 0
            else if (i==0){
                cout << "else if" << endl;
                cout << "idx : " << idx << endl;
                lettre_i = (char) (idx + 'a');
            }

            //cas indice inferieure Puissance n
            else{
                cout << "else" << endl;
                lettre_i = (char) ('a');
            }
            sClair += lettre_i;
        }

        //string sClair(cClair);

        int a = 0;
        for(std::string::iterator it = sClair.begin(); it != sClair.end(); ++it) {
            cout << "indice de la chaine : " << a << " sClair vaut " << sClair[a] << endl;
            a++;
        }

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
