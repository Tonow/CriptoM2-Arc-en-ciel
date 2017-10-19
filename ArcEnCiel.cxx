
#include <cstdint>
#include <algorithm>

#include "ArcEnCiel.h"

typedef unsigned int       uint;
typedef unsigned long long uint64;
typedef unsigned char      byte;
using std::string;

using namespace std;

// Creer les M chaînes de taille T, dans le contexte ctxt
/**
*@param int M nombre d'entrees dans la table arc-en-ciel
*@param int num numero de la tableau
*@param int T nombre de colonne de la table
*/
void ArcEnCiel::creer(Contexte& ctxt, int num, int M, int T )
    {
        uint64 indiceEntre = 0;
        uint64 indiceSortie = 0;
        _X.resize(M);
        for (int i = 0; i < M; i++) // on vas ecrire M fois dans notre table
        {
            indiceEntre = ctxt.randIndex();
            _X[i].idx1 = indiceEntre;
            for (int t = 0; t < T; t++) // on tourne T fois avec i2i
            {
                indiceSortie = ctxt.i2i(indiceEntre , t);
                indiceEntre = indiceSortie;
            }
            _X[i].idxT = indiceSortie;
            std::cout << _X[i].idx1 << "-i2i(0) --> ... -i2c(" << T << ") -> " << _X[i].idxT << endl;
        }
    }

// Tri _X suivant idxT.
void ArcEnCiel::trier()
    {
        sort(_X.begin(),_X.end(),
                        [](const Chaine _X, const Chaine _X2)
                           {return _X.idxT < _X2.idxT;}
            );

        for (uint i = 0; i < _X.size(); i++)
        {
            cout << _X[i].idx1 << "-i2i(0) --> ... -i2c(final) -> " << _X[i].idxT << endl;
        }

    }

// Sauvegarde la table sur disque.
void ArcEnCiel::save( string name )
    {
        //TODO
    }

// Charge en mémoire la table à partir du disque.
void ArcEnCiel::load( string name )
    {
        //TODO
    }

// Recherche dichotomique dans la table
// ( p et q sont le premier/dernier trouvé )
bool ArcEnCiel::recherche( uint64 idx, uint & p, uint & q )
    {
        //TODO
        return true;
    }
