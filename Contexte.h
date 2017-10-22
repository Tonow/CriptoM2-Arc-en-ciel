/**
*
*/
#include <string>
#include <cstdint>
#include <vector>
#pragma once


typedef unsigned int       uint;
typedef unsigned long long uint64;
typedef unsigned char      byte;
using std::string;


class Contexte {
 public:
  // uint64 _N;              // nombre de mots
  // int    _mot_taille_min; // nombre de lettres min d'un mot
  // int    _mot_taille_max; // nombre de lettres max d'un mot
  // uint64 _N_taille[];     // tableau, nombre de mots d'une taille donnée
  // int    _nb_lettres;     // nombre de lettres possibles pour un caractère
  // char   _lettres[];      // tableau des lettres de taille _nb_lettres


  // Valeur test pour Mdp de 4 lettres et uniquement alphabetique minucule
  uint64 _N           = 11881376; // 26^4
  int _mot_taille_min = 5;     // 4 lettres min
  int _mot_taille_max = 5;     // 4 lettres max
  uint64 _N_taille[1] = {11881376};// il n'y a que les mots de 4 lettres
  int _nb_lettres     = 26;    // 26 lettres de l'alphabet
  string _lettres     = "abcdefghijklmnopqrstuvwxyz"; // l'alphabet

  // fonction de hachage
  // In: Clair c ----> Out: Empreinte (tableau de 16 octets (MD5) ou 20 octets (SHA1)
  void h( string c, byte d[] );

  // In: position t, empreinte d ---> Retourne index
  uint64 h2i( uint64 t, const byte d[] );

  // In: index idx ----> Out: Clair c
  string i2c( uint64 idx );

  // In: index idx ----> retourne index (la composée des précédentes)
  uint64 i2i( uint64 idx , uint64 t);

  // Retourne un indice aléatoire valide.
  uint64 randIndex();

 private:
  // on peut mettre l'empreinte dans cette donnée membre
  // (évite de crééer un tableau à chaque fois)
  byte empreinte[ 16 ];

};
