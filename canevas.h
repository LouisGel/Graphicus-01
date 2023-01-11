/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef DESSIN_H
#define DESSIN_H

#include <iostream>
#include "forme.h"
#include "couche.h"

const int MAX_COUCHES = 5;

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();
   
   bool reinitialiser();
   
   bool activerCouche(int);
   bool cacherCouche(int);
   
   bool ajouterForme(Forme*);
   bool retirerForme(int);
   
   double aire();
   bool translater(int, int);
   void afficher(ostream&);

   Couche* getCoucheActive();

private:
    Couche couches[MAX_COUCHES];
};

#endif