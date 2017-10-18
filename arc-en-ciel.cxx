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

  	cout << "Vide pour l'instant" << endl;
   //  ArcEnCiel nom;
   //  nom.trier();
    Contexte c;
    c.i2c(indice);

  	return 0;
}
