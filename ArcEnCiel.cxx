
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

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
        printf("Pourcentage de la creation de la table : 0 %%");
        fflush(stdout);
        for (int i = 0; i < M; i++) // on vas ecrire M fois dans notre table
        {
            rateAffiche = (int) floor(i*rate);
            if (oldRate != rateAffiche) {
                //cout << "Pourcentage de la creation de la table : " << rateAffiche << "%" << '\r';
                printf("\rPourcentage de la creation de la table : %d%%", rateAffiche);

                fflush(stdout);
                usleep(1);
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
        fflush(stdout);
        printf("\rPourcentage de la creation de la table : 100%%");


        cout << "\n Creation de la table : \n"
        <<"   --> numero :"<< num << "\n"
        <<"   --> nb ligne :"<< M << "\n"
        <<"   --> nb colonne (virtuel) :"<< T << "\n"
        << " ok\n" << endl;
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
        cout << "\n Tri de la table ok\n"  << endl;

    }

// Sauvegarde la table sur disque.
void ArcEnCiel::save( string name )
    {
        name = name + ".txt";
        ofstream fichier;
        fichier.open(name);
        fichier << _X.size() << endl;
        fichier << _T << endl;
        for (uint i=0; i<_X.size(); i++){
            fichier <<  _X[i].idx1 << " " << _X[i].idxT << endl;
        }
        fichier.close();
        cout << "\n Sauvegarde sur fichier : " << name << " ok\n" << endl;
    }

// Nombre de ligne du fichier a traiter en memoir
uint ArcEnCiel::loadNbLigne( string name )
    {
        uint nbLigne;
        string ligne;
        ifstream fichier (name);

        getline(fichier, ligne);
        nbLigne = stoul(ligne.c_str());
        std::cout << '\n'  << "Load file : " << name << "\n"
        <<"Nombre de ligne dans le fichier : " << nbLigne << endl;
        fichier.close();

        return nbLigne;
    }

// Nombre de colonne de la table arc-en-ciel
uint ArcEnCiel::loadNbColonne( string name )
    {
        uint nbColonne;
        string ligne;
        ifstream fichier (name);

        getline(fichier, ligne);
        getline(fichier, ligne);
        nbColonne = stoul(ligne.c_str());
        std::cout << '\n'  << "Nombre de colonnes dans le fichier : " << nbColonne << endl;

        fichier.close();
        return nbColonne;
    }

// Charge en mémoire la table à partir du disque.
void ArcEnCiel::load( string name )
    {
        uint64 nbInFile;
        uint nbLigne;
        uint nbColonne;
        string ligne;
        ifstream fichier (name);

        getline(fichier, ligne);
        nbLigne = stoul(ligne.c_str());
        std::cout << '\n'  << "Load file : " << name << "\n"
        <<"Nombre de ligne dans le fichier : " << nbLigne << endl;

        getline(fichier, ligne);
        nbColonne = stoul(ligne.c_str());
        std::cout << '\n'  << "Nombre de colonnes dans le fichier : " << nbColonne << endl;

        for (uint i=0; i < nbLigne; i++){ //(nbInFile - 11)
            //printf("\rLecture de la ligne %d",i);
            getline(fichier, ligne , ' ');// premier chiffre de la ligne
            nbInFile = stoull(ligne.c_str());
            _X[i].idx1 = nbInFile; // indice initial

            //std::cout << "idx1 : " << nbInFile << " i : " << i << endl;

            getline(fichier, ligne);// deuxieme chiffre de la ligne
            nbInFile = stoull(ligne.c_str());
            _X[i].idxT = nbInFile; // indice finale

            //cout << "idxT : " << nbInFile << " i : " << i << endl;

            //cout << "   Indice initial --> " << _X[i].idx1 << "  ...  Finale --> " << _X[i].idxT << endl;
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

        // if (trouve) {
        //     cout << "\n"<< "Recherch ok pour : " << _X[milieu].idxT << endl;
        // }
        // else {
        //     ////visuel
        //     //cout << "\n" << "non trouver" << endl;
        // }
        return trouve;
    }
