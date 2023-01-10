/********
 * Fichier: cercle.cpp
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Implementation des methodes des classes decrites dans cercle.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "cercle.h"

Cercle::Cercle(double rayon, Coordonnee ancrage) : Forme(ancrage.x, ancrage.y)
{
    _rayon = rayon;
}

Cercle::~Cercle()
{
    _rayon = 0;
}

double Cercle::getRayon() const
{
    return _rayon;
}

void Cercle::setRayon(double rayon)
{
    assert(rayon > 0);
    _rayon = rayon;
}

Cercle& Cercle::operator=(Cercle& cercle)
{
    if(this == &cercle) return *this;
    _rayon = cercle.getRayon();
    ancrage = cercle.getAncrage();
    return *this;
}

bool Cercle::operator==(Cercle& cercle) const 
{
    return (cercle.getRayon() == _rayon &&
            cercle.getAncrage().x == ancrage.x &&
            cercle.getAncrage().y == ancrage.y);
}

double Cercle::aire() const
{
    return M_PI * pow(_rayon, 2);
}

void Cercle::afficher(ostream & stream) const
{
    stream << _rayon << endl;
}

ostream& operator<<(ostream& stream, const Cercle cercle)
{
    cercle.afficher(stream);
    return stream;
}