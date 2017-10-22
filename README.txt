Reponse au TP sur les table arc-en-ciel du lien suivant:
http://www.lama.univ-savoie.fr/~lachaud/Cours/INFO910/Tests/doc/html/tp1.html


Deux programme

1) - arc-en-ciel
    construit la table arc-en-ciel
        @argument nomFichierTable - nom du fichier qui contiendra la table
        @argument Mstr - nombre de ligne de la table

        si on ne les rentre pas on a un menu utilisateur sommaire

        si on veux changer T (nombre de colonne de la table) il faut aller dans ArcEnCiel.h

        - la table a en premier argument l'indice initial aléatoire
        - la table a deuxième argument l'indice final qui correspondant au dernier indice du dernier hash

        la table est trier


2) - craquer
    craque un hash type md5 (pour SHA1 il faut changer des paramétres notamment la fonction h et donc re-génere une table)
        @argument hash - le hash a craquer
        @argument fichierArcEnCiel - la table dans le quelle on cherche
        @argument (de test) claire - car il y a un probleme de correspondance en le tableau de byte du claire hasher et celui du hash qui est construit (notamment le dernier octet)

        -on construit un indice pour le hash
        -on compare l'indice avec celui de la derniere colonne de la table
            -si egale alors on test le hash avec l'avant derniere colonne
                -si egale alors on a trouver et on va rechercher le claire qui est juste avant sur le meme ligne
                -sinon fausse alerte
            -sinon on fait un i2i (boucle complete de l'indice du claire a l'indice du hash) de plus sur le hash
            Et cela tant qu'on a pas soit trouver soit qu'on ne l'a pas fait le nombre de colonne T (virtuel) de la table


Etat actuel:
    -création table arc-en-ciel ok (aphabet de 26 lettres minuscules et taille mot fixe)
    -craque presque ok (on pense) juste pb de comparaison entre transformation en hexadecimal en byte de soit le hash de test soit l'original 
