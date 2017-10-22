/**
*Cracke un hash grace a une table arc en ciel deja crée
*/

#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>

#include "utils.h"
#include "ArcEnCiel.h"
#include "Cracker.h"
#include "Contexte.h"

typedef unsigned int       uint;
typedef unsigned long long uint64;
typedef unsigned char      byte;
using std::string;
using namespace std;


#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"



int main( int argc, char** argv )
{
   string clair;
   string claire;
   string hash;
   string fichierArcEnCiel;
   string reponse = " ";
   bool parametreEntrerOk = false;

   cout << '\n'
           << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n'
           << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;
   cout << "Bonjour," << endl;
   cout << '\n'
           << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n'
           << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;


    if ( argc < 4){
      while (parametreEntrerOk == false) {

         cout << "Il faut entrer des parametre Voulez vous continuer? Oui/Non"<< endl;
         cin >> reponse;

         if (reponse == "NON" || reponse ==  "non" ||reponse ==  "N" ||reponse ==  "n" ||
             reponse == "q" || reponse ==  "Q" || reponse ==  "no" || reponse ==  "No" ||
             reponse ==  "NO") {
            std::cout << "Au revoir" << '\n';
            exit(-1);
         }

         printf("\n1: chaine deja Hasher :    ");
         cin >> hash;

         printf("\n2: fichier de la table arc-en-ciel :     ");
         cin >> fichierArcEnCiel;

         printf("\n2: claire du test :     ");
         cin >> claire;

         parametreEntrerOk = true; // pour plus tard valider les reponses
      }
    }
    else
    {
      hash = argv[1];
      fichierArcEnCiel = argv[2];
      claire = argv[3];
    }




    cout << '\n'
         << "#########################" << '\n'
         << "###  Craque Hash md5  ###" << '\n'
         << "#########################" << '\n'<< endl;

    cout <<  "\n" <<"Fonction ok :" << endl;


    cout <<  "\n" <<"Fonction a tester :" << endl;
    cout << "   --> Craker.VerifieAlerte" << endl;
    cout << "   --> Craker.cracker" << endl;

    cout << "\n" << endl;
    ArcEnCiel arc;
    Contexte ctxt;
    Cracker crac;

    byte empreinte1 [16];
    byte empreinteCrack [16];

    ctxt.h(claire , empreinte1);

    std::cout << "le claire est :" << claire << " son hash ci dessous " << '\n';

    cout << empreinte1 << endl;

    //byte empreinteCrack[ 16 ];
    unsigned char* empreinteCrackTempo = (unsigned char*) hash.c_str();

    std::cout << "empreinteCrackTempo avant " << empreinteCrack << '\n';

   //  unsigned char* empreinteCrackByte [1];
     hex2bin(empreinteCrackTempo, empreinteCrack);

      std::cout << "empreinteCrackTempo apres " << empreinteCrack << '\n';
   //   char mdString[33];
   //    for (int i = 0; i < 16; i++)
   //    {
   //         sprintf(&mdString[i*2], "%02x", (unsigned int)empreinteCrack[i]);
   //    }
     //
   //    printf("empreinteCrackTempo apres hexa: %s\n", mdString);


    uint nbL = arc.loadNbLigne(fichierArcEnCiel);
    uint nbC = arc.loadNbColonne(fichierArcEnCiel);
    arc._X.resize(nbL);

    arc.load(fichierArcEnCiel);
    crac.cracker( empreinteCrack, arc, ctxt, clair , nbC);


   std::cout << "chaine deja Hasher : " << hash << endl;
   std::cout << "Dernier clair traiter : " << clair << endl;
   std::cout << "fichierArcEnCiel : " << fichierArcEnCiel << "\n" << endl;
    std::cout << "#########################" << '\n'
              << "#########################" << '\n' <<endl;

  	return 0;
}
