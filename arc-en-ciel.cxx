/**
*Crée une table arc-en-ciel
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <stdio.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#include "utils.h"
#include "ArcEnCiel.h"

typedef unsigned long long uint64;



using namespace std;



int main( int argc, char** argv )
{
   string nomFichierTable;
   string Mstr;
   int M;
   string reponse = " ";
   bool parametreEntrerOk = false;

   cout << '\n'
           << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n'      << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;
   cout << "Bonjour," << endl;
   cout << '\n'
           << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n'      << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;


   if ( argc < 3){
     while (parametreEntrerOk == false) {

        cout << "Il faut entrer des parametres Voulez vous continuer? Oui/Non"<< endl;
        cin >> reponse;

        if (reponse == "NON" || reponse ==  "non" ||reponse ==  "N" ||reponse ==  "n" ||
            reponse == "q" || reponse ==  "Q" || reponse ==  "no" || reponse ==  "No" ||
            reponse ==  "NO") {
           std::cout << "Au revoir" << '\n';
           exit(-1);
        }

        printf("\n1: Nom du fichier de la table :    ");
        cin >> nomFichierTable;

        printf("\n1: Nombre de ligne de la table :    ");
        cin >> Mstr;
        M = atoi(Mstr.c_str());
        parametreEntrerOk = true; // pour plus tard valider les reponses
     }
   }
   else
   {
     nomFichierTable = argv[1];
     Mstr = argv[2];
     M = atoi(Mstr.c_str());
   }
    //uint64 indice = atoi(argv[1]);
   //  uint p;
   //  uint q;
    //string chaineTeste = argv[2];
    //int t = atoi(argv[3]);

    cout << '\n'  << COLOR_RED << "####"<< COLOR_GREEN <<"####"<< COLOR_YELLOW <<"####"<< COLOR_BLUE <<"####"<< COLOR_MAGENTA <<"####"<< COLOR_CYAN <<"####"<< COLOR_RESET << '\n' << "###Table arc-en-ciel###" << '\n'    << COLOR_RED << "####"<< COLOR_GREEN <<"####"<< COLOR_YELLOW <<"####"<< COLOR_BLUE <<"####"<< COLOR_MAGENTA <<"####"<< COLOR_CYAN <<"####"<< COLOR_RESET << '\n'<< endl;

    cout <<  "\n" <<"Fonction ok :" << endl;
    cout << "   --> Contexte.i2c" << endl;
    cout << "   --> Contexte.h" << endl;
    cout << "   --> Contexte.h2i" << endl;
    cout << "   --> Contexte.i2i" << endl;
    cout << "   --> Contexte.randIndex" << endl;
    cout << "   --> ArcEnCiel.cree" << endl;
    cout << "   --> ArcEnCiel.trier" << endl;
    cout << "   --> ArcEnCiel.load" << endl;
    cout << "   --> ArcEnCiel.recherche" << endl;

    cout << '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n'  << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;

    cout <<  "\n" <<"Fonction a tester :" << endl;

    cout << '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;

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
   std::cout << "arc._numero : " << arc._numero << endl;
   std::cout << "arc._M : " << arc._M << endl;
   std::cout << "arc._T : " << arc._T << "\n" << endl;

   cout << '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######" << COLOR_RESET <<'\n' <<endl;

   arc.creer(c , arc._numero , M, arc._T);

   cout << '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;
   arc.trier();
   cout << '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;
   arc.save(nomFichierTable);


   //arc.load(nomFichierTable);
   //std::cout << "Load ok" << '\n';
   //arc.recherche(indice, p , q);

   cout << '\n'
   << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< COLOR_RESET << '\n'
   << "###  La table a bien ete creee   ###" << '\n'
   << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< COLOR_RESET << '\n'<< endl;

  	return 0;
}
