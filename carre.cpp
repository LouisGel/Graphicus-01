/********
 * Fichier: carre.cpp
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Declaration de la classe carre.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "carre.h"

Carre::Carre(double longueur, Coordonnee ancrage) : Rectangle(longueur, longueur, ancrage) { }

Carre::~Carre() { _largeur = _hauteur = 0; }

void Carre::setSize(double longueur)
{
    assert(longueur >= 0);
    _hauteur = _largeur = longueur;
}

double Carre::aire() const{ 
    return _hauteur * _largeur; 
}

void Carre::afficher(ostream& stream) const {
    stream << _hauteur << endl << _largeur << endl;
}

ostream& operator<<(ostream& stream, const Carre carre) {
    carre.afficher(stream);
    return stream;
}