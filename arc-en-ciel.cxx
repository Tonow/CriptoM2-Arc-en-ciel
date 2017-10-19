/**
*Décrypte un mot de passe MD5 ou SHA
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "utils.h"
#include "ArcEnCiel.h"



using namespace std;



int main( int argc, char** argv )
{
    if ( argc < 2){
         cout << "Entrez un paramètre" << endl;
    }
    int indice = atoi(argv[1]);
    string chaineTeste = argv[2];
    int t = atoi(argv[3]);

    cout << '\n'
         << "#########################" << '\n'
         << "### Table arc-en-ciel ###" << '\n'
         << "#########################" << '\n'<< endl;

    cout <<  "\n" <<"Fonction ok :" << endl;
    cout << "   --> i2c" << endl;
    cout << "   --> h" << endl;
    cout << "   --> h2i" << endl;

    cout <<  "\n" <<"Fonction a tester :" << endl;
    cout << "   --> i2i" << endl;
    cout << "   --> randIndex" << endl;

    cout << "\n" << endl;

    byte d[16];

    Contexte c;
    c.i2c(indice);
    std::cout << "texte origin :" << chaineTeste << '\n';
    c.h(chaineTeste, d);
    c.h2i(t, d);

  	return 0;
}
