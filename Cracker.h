#pragma once

#include <stdio.h>

#include "Cracker.h"
#include "ArcEnCiel.h"

typedef unsigned int       uint;
typedef unsigned char      byte;

class Cracker {
public:
  // Retourne vrai si l'alerte était bonne, c est alors le texte clair
  // correspondant à l'empreinte y.
  bool VerifieAlerte( byte Empreinte[], vector<Chaine> _X, uint t, uint m, string & clair, Contexte& ctxt);


  bool cracker( byte Empreinte[], ArcEnCiel& aec, Contexte& ctxt, string & clair , uint T);

private:
 // on peut mettre l'empreinte dans cette donnée membre
 // (évite de crééer un tableau à chaque fois)
 //byte empreinte0[ 16 ];
};
