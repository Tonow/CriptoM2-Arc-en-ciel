/**
*
*/
#include "Contexte.h"
#include <string>
#include <iostream>
#pragma once
#include <cstdint>

// typedef unsigned int       uint;
// typedef unsigned long long uint64;
// typedef unsigned char      byte;
using namespace std;
using std::string;

struct Chaine {
  uint64 idx1;    // premier indice de la chaine
  uint64 idxT;    // dernier indice de la chaine
};
class ArcEnCiel {
public:
  ArcEnCiel(){

  }

  uint    _numero;   // numero de la table (ici 0, mais voir "Moult tables")
  uint    _M;        // nombre de chaines dans la table
  uint    _T;        // taille de chaque chaine
  Chaine* _X;        // la table elle-meme




  // Creer les M chaînes de taille T, dans le contexte ctxt
  void creer( const Contexte & ctxt, int num, int M, int T );
  // Tri _X suivant idxT.
  void trier();
  // Sauvegarde la table sur disque.
  void save( string name );
  // Charge en mémoire la table à partir du disque.
  void load( string name );
  // Recherche dichotomique dans la table
  // ( p et q sont le premier/dernier trouvé )
  bool recherche( uint64 idx, uint & p, uint & q );
};
