/**
*Cracke un hash grace a une table arc en ciel deja crée
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "utils.h"
#include "ArcEnCiel.h"

typedef unsigned long long uint64;

using namespace std;



int main( int argc, char** argv )
{
    if ( argc < 2){
         cout << "Entrez deux paramètre \n 1: chaine deja Hasher \n 2: fichier de la table arc-en-ciel" << endl;
    }

    string chaineHasher = argv[1];
    string fichierArcEnCiel = argv[2];


    cout << '\n'
         << "#########################" << '\n'
         << "###  Craque Hash md5  ###" << '\n'
         << "#########################" << '\n'<< endl;

    cout <<  "\n" <<"Fonction ok :" << endl;


    cout <<  "\n" <<"Fonction a tester :" << endl;

    cout << "\n" << endl;

    //byte d[16];

     Contexte c;
   //  c.i2c(indice);
   //  std::cout << "texte origin :" << chaineTeste << '\n';
   //  c.h(chaineTeste, d);
   //  c.h2i(t, d);
    //
   //  std::cout << "#########################" << '\n'
   //            << "#########################" << '\n' <<endl;
   //  c.i2i(indice, t);
   ArcEnCiel arc;
   std::cout << "chaine deja Hasher : " << chaineHasher << endl;
   std::cout << "fichierArcEnCiel : " << fichierArcEnCiel << "\n" << endl;
    std::cout << "#########################" << '\n'
              << "#########################" << '\n' <<endl;

  	return 0;
}
