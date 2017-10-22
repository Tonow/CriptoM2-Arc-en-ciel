/**
*
*/
#pragma once
#include <string>
#include <iostream>
#include <cstdint>
#include <vector>

#include "Contexte.h"

typedef unsigned int       uint;
typedef unsigned long long uint64;
typedef unsigned char      byte;
using namespace std;
using std::string;

struct Chaine {
  uint64 idx1;    // premier indice de la chaine
  uint64 idxT;    // dernier indice de la chaine
};
class ArcEnCiel {
public:

  uint    _numero = 0;   // numero de la table (ici 0, mais voir "Moult tables")
  uint    _M = 6000;        // nombre de chaines dans la table
  uint    _T = 5000; // taille de chaque chaine
  vector<Chaine> _X;        // la table elle-meme
  vector<Chaine> _X2;        // la table temporaire de tri




  // Creer les M chaînes de taille T, dans le contexte ctxt
  void creer( Contexte& ctxt, int num, int M, int T );

  // Tri _X suivant idxT.
  void trier();

  // Sauvegarde la table sur disque.
  void save( string name );

  // Nombre de ligne du fichier a traiter en memoir
  uint loadNbLigne( string name );

  // Nombre de colonne de la table arc-en-ciel
  uint loadNbColonne( string name );

  // Charge en mémoire la table à partir du disque.
  void load( string name );

  // Recherche dichotomique dans la table
  // ( p et q sont le premier/dernier trouvé )
  bool recherche( uint64 idx, uint & p, uint & q );
};
