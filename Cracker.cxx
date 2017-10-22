#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include "Cracker.h"
#include "ArcEnCiel.h"

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

typedef unsigned int       uint;
typedef unsigned long long uint64;
typedef unsigned char      byte;
using std::string;
using namespace std;

uint T; // TODO pour l'instant apres il faudra prendre le deuxieme indice de la table
uint q = 0;
uint p = 1;

// Retourne vrai si l'alerte était bonne, c est alors le texte clair
// correspondant à l'empreinte Empreinte.
bool Cracker::VerifieAlerte( byte Empreinte[], vector<Chaine> _X, uint t, uint m, string & clair, Contexte& ctxt) // TODO a tester
{
    //unsigned char* empreinte0;
    // X[ m ] est le couple ( i_m1, i_mT )
    // clair : texte clair si trouvé
    byte empreinte0[ 16 ];
    bool trouver;

    // On parcourt à partir du début de la chaîne
    uint64 idx = _X[ m ].idx1  ; // i_m1

    for (uint k = 0; k < t-1; k++) // on s'arrete avant pour pouvoir tomber sur le claire
    {
      idx = ctxt.i2i(idx, k);
    }
    clair = ctxt.i2c(idx);
    ctxt.h(clair , empreinte0); // crée l'empreinte du clair a tester

     std::cout << "Alerte pour Claire : " << clair << " ; qui a l empreinte -->  "<< empreinte0 << endl;

    trouver = (Empreinte == empreinte0);

    if (trouver)
    {
      cout << '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;

      cout << "\n" << COLOR_RED << "   -->    Les Claire est : " << COLOR_RESET <<  clair << "\n" << endl;

      cout << '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' << COLOR_RED << "######"<< COLOR_GREEN <<"######"<< COLOR_YELLOW <<"######"<< COLOR_BLUE <<"######"<< COLOR_MAGENTA <<"######"<< COLOR_CYAN <<"######"<< '\n' <<endl;
    }

    return trouver; // on teste si les deux hash sont equivalant
}


bool Cracker::cracker( byte Empreinte[], ArcEnCiel& aec, Contexte& ctxt, string & clair , uint T) {

  int nb_fausses_alertes = 0;

  float rate = (float)((100.0/T));
  int rateAffiche;
  int oldRate = 0;
  printf("Pourcentage de Test du mdp : 0 %%");
  fflush(stdout);

  for ( uint t = T - 1; t > 0; --t )
  {
    // affichage progrestion
    rateAffiche = (int) floor( 100 - t*rate);
          if (oldRate != rateAffiche) {
              // cout << "Pourcentage de la creation de la table : " << rateAffiche << "%" << '\r';
              printf(COLOR_MAGENTA "\rPourcentage de Test du mdp : %d %%", rateAffiche);

              fflush(stdout);
              usleep(1);
          }

     // fabrication du bon indice
     uint64 idx = ctxt.h2i( t, Empreinte );
     for ( uint k = t + 1; k <= T - 1; ++k ) {
       idx = ctxt.i2i( k, idx );
     }
     //printf(COLOR_MAGENTA "\rRecherche de idx : %llu", idx);

     // Recherche dans la table.
     if ( aec.recherche( idx, p, q ) ) {
       // On vérifie chacune des alertes
       for ( uint m = p; m <= q; ++m ) {
         //std::cout << "p = "<<p << " q = " << q << '\n';
         //std::cout << "Empreinte : " << Empreinte << "  -- indice : "<<  idx << "  t : " << t  <<'\n';
         if ( VerifieAlerte( Empreinte, aec._X, t, m, clair, ctxt) )
           return true;
         nb_fausses_alertes++;
       }
     }
  }
  fflush(stdout);
  printf("\rPourcentage de Test du mdp : 100%%" COLOR_RESET);

  cout << "\n" << "Non trouve, fausses alertes = " << nb_fausses_alertes << endl;
  return false;

}
