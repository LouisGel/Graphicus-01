/********
 * Fichier: carre.cpp
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Implementation des methodes des classes decrites dans carre.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "carre.h"

Carre::Carre(double longueur, Coordonnee ancrage) : Rectangle(longueur, longueur, ancrage)
{
    //Vide
}

Carre::~Carre()
{
    _largeur = _hauteur = 0;
}

void Carre::setSize(double longueur)
{
    assert(longueur >= 0);
    _hauteur = _largeur = longueur;
}

Carre& Carre::operator=(Carre& carre)
{
    if(this == &carre) return *this;
    _hauteur = carre.getHauteur();
    _largeur = carre.getLargeur();
    ancrage = carre.getAncrage();
    return *this;
}

bool Carre::operator==(Carre& carre) const 
{
    return (carre.getHauteur() == _hauteur &&
            carre.getLargeur() == _largeur && 
            carre.getAncrage().x == ancrage.x &&
            carre.getAncrage().y == ancrage.y);
}

void Carre::afficher(ostream& stream) const
{
    stream  << "Carre(x=" << ancrage.x
            << ", y=" << ancrage.y
            << ", c=" << _hauteur
            << ", aire=" << aire() << ")";
}

ostream& operator<<(ostream& stream, const Carre& carre) {
    carre.afficher(stream);
    return stream;
}