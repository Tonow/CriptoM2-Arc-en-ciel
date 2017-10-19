/**
*Décrypte un mot de passe MD5 ou SHA
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
         cout << "Entrez un paramètre" << endl;
    }
    uint64 indice = atoi(argv[1]);
    uint p;
    uint q;
    string chaineTeste = argv[2];
    //int t = atoi(argv[3]);

    cout << '\n'
         << "#########################" << '\n'
         << "### Table arc-en-ciel ###" << '\n'
         << "#########################" << '\n'<< endl;

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
   std::cout << "arc._numero : " << arc._numero << endl;
   std::cout << "arc._M : " << arc._M << endl;
   std::cout << "arc._T : " << arc._T << "\n" << endl;
   arc.creer(c , arc._numero , arc._M, arc._T);
    std::cout << "#########################" << '\n'
              << "#########################" << '\n' <<endl;
   arc.trier();
   //arc.save("test.txt");
   //arc.load("test.txt");
   arc.recherche(indice, p , q);

  	return 0;
}
