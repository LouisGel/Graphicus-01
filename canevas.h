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
#include "couche.h"

const int MAX_COUCHES = 5;

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();
   
   bool activerCouche(int);   
   bool ajouterForme(Forme*);
   bool retirerForme(int);
   bool reinitialiser();        //Réinitialise la couche activé
   bool reinitialiser(int);     //Réinitialise la couche à l'index...
   double aire() const;
   bool translater(int, int);
   void afficher(ostream&) const;
   Couche* getCoucheActive();

private:
    Couche couches[MAX_COUCHES];
};

ostream& operator<<(ostream&, const Canevas&);

#endif