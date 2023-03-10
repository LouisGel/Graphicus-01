/********
 * Fichier: forme.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration des classes de formes geometriques. La
 *    classe Forme ne doit pas etre modifiee. Ce fichier fait partie de
 *    la distribution de Graphicus.
********/

#ifndef FORME_H
#define FORME_H

#include <iostream>
#include "coordonnee.h"

using namespace std;

class Forme
{
public:
  Forme(int x = 0, int y = 0);
  virtual ~Forme();
  void translater(int deltaX, int deltaY);
  Coordonnee getAncrage();
  void setAncrage(Coordonnee c);
  virtual double aire() const = 0;  //=0 veut dire virtuel pure! Les enfants sont obligé de la créer
  virtual void afficher(ostream & s) const = 0;
protected:
	Coordonnee ancrage;
};

ostream& operator<<(ostream& stream, const Forme& forme);

#endif