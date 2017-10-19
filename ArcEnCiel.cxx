
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

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
        float rate = (float)(100.0/M);
        int rateAffiche;
        int oldRate = 0;
        for (int i = 0; i < M; i++) // on vas ecrire M fois dans notre table
        {
            rateAffiche = (int) floor(i*rate);
            if (oldRate != rateAffiche) {
                cout << "Pourcentage de la creation de la table : " << rateAffiche << "%" << '\n';
            }
            oldRate = rateAffiche;
            indiceEntre = ctxt.randIndex();
            _X[i].idx1 = indiceEntre;
            for (int t = 0; t < T; t++) // on tourne T fois avec i2i
            {
                indiceSortie = ctxt.i2i(indiceEntre , t);
                indiceEntre = indiceSortie;
            }
            _X[i].idxT = indiceSortie;
            //affichage
            //std::cout << _X[i].idx1 << "-i2i(0) --> ... -i2c(" << T << ") -> " << _X[i].idxT << endl;
        }
    }

// Tri _X suivant idxT.
void ArcEnCiel::trier()
    {
        sort(_X.begin(),_X.end(),
                        [](const Chaine _X, const Chaine _X2)
                           {return _X.idxT < _X2.idxT;}
            );

        ////affichage
        // for (uint i = 0; i < _X.size(); i++)
        // {
        //     cout << _X[i].idx1 << "-i2i(0) --> ... -i2c(final) -> " << _X[i].idxT << endl;
        // }

    }

// Sauvegarde la table sur disque.
void ArcEnCiel::save( string name )
    {
        ofstream fichier;
        fichier.open(name);
        fichier << _X.size() << endl;
        for (uint i=0; i<_X.size(); i++){
            fichier <<  _X[i].idx1 << " " << _X[i].idxT << endl;
        }
        fichier.close();
    }

// Charge en mémoire la table à partir du disque.
void ArcEnCiel::load( string name )
    {
        uint64 nbInFile;
        uint nbLigne;
        string ligne;
        ifstream fichier (name);

        getline(fichier, ligne);
        nbLigne = stoul(ligne.c_str());
        std::cout << '\n'  << "Load file : " << name << "\n"
        <<"Nombre de ligne dans le fichier : " << ligne << endl;

        for (uint i=1; i < (nbLigne +1); i++){ //(nbInFile - 11)
            getline(fichier, ligne , ' ');// premier chiffre de la ligne
            nbInFile = stoull(ligne.c_str());
            _X[i-1].idx1 = nbInFile; // indice initial

            //std::cout << "idx1 : " << nbInFile << " i : " << i << endl;

            getline(fichier, ligne);// deuxieme chiffre de la ligne
            nbInFile = stoull(ligne.c_str());
            _X[i-1].idxT = nbInFile; // indice finale

            //cout << "idxT : " << nbInFile << " i : " << i << endl;

            cout << "   Indice initial --> " << _X[i-1].idx1 << "  ...  Finale --> " << _X[i-1].idxT << endl;
        }
        fichier.close();
    }

// Recherche dichotomique dans la table
// ( p et q sont le premier/dernier trouvé )
bool ArcEnCiel::recherche( uint64 idx, uint & p, uint & q )
    {
        //TODO a verifier
        bool trouve = false;  //faux tant que "idx" n'aura pas été trouvée
        uint milieu;  //indice de "milieu"
        p = 0;
        q = _X.size();

        /* boucle de recherche */
        while(!trouve && ((q - p) > 1))
        {
            milieu = (p + q)/2;  //on détermine l'indice de milieu

            trouve = (_X[milieu].idxT == idx);  //on regarde si la valeur recherchée est à cet indice

            if(_X[milieu].idxT > idx)
            {
                 q = milieu;
            }
            else p = milieu;
        }

        if (trouve) {
            cout << "\n"<< "trouver " << _X[milieu].idxT << endl;
        }
        else {
            cout << "\n" << "non trouver" << endl;
        }
        return trouve;
    }
