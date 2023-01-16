/********
 * Fichier: rectangle.cpp
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Implementation des methodes des classes decrites dans rectangle.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "rectangle.h"

Rectangle::Rectangle(double hauteur, double largeur, Coordonnee ancrage) : Forme(ancrage.x, ancrage.y)
{
    setSize(hauteur, largeur); 
}

Rectangle::Rectangle(Rectangle& rectangle) : Forme(rectangle.getAncrage().x, rectangle.getAncrage().y)
{
    _hauteur = rectangle.getHauteur();
    _largeur = rectangle.getLargeur();
}

Rectangle::~Rectangle()
{
    _largeur = _hauteur = 0;
}

double Rectangle::getLargeur() const
{
    return _largeur;
}

double Rectangle::getHauteur() const
{
    return _hauteur;
}

void Rectangle::setSize(double hauteur, double largeur)
{
    assert(hauteur >= 0 && largeur >= 0);
    _hauteur = hauteur;
    _largeur = largeur;
}

Rectangle& Rectangle::operator=(Rectangle& rectangle)
{
    if(this == &rectangle) return *this;
    _hauteur = rectangle.getHauteur();
    _largeur = rectangle.getLargeur();
    ancrage = rectangle.getAncrage();
    return *this;
}

bool Rectangle::operator==(Rectangle& rectangle) const 
{
    return (rectangle.getHauteur() == _hauteur &&
            rectangle.getLargeur() == _largeur && 
            rectangle.getAncrage().x == ancrage.x &&
            rectangle.getAncrage().y == ancrage.y);
}

double Rectangle::aire() const
{ 
    return _hauteur * _largeur; 
}

void Rectangle::afficher(ostream& stream) const
{
    stream  << "Rectangle(x=" << ancrage.x
            << ", y=" << ancrage.y
            << ", l=" << _largeur
            << ", h=" << _hauteur
            << ", aire=" << aire() << ")";
}

ostream& operator<<(ostream& stream, const Rectangle& rectangle)
{
    rectangle.afficher(stream);
    return stream;
}