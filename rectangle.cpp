/********
 * Fichier: rectangle.cpp
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Declaration de la classe rectangle. La
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "rectangle.h"

Rectangle::Rectangle(double hauteur = 0, Coordonnee ancrage = {0,0}) : Forme(ancrage.x, ancrage.y) { this->setSize(hauteur); }
Rectangle::Rectangle(double hauteur = 0, double largeur = 0, Coordonnee ancrage = {0,0}) : Forme(ancrage.x, ancrage.y) { this->setSize(hauteur, largeur); }

Rectangle::~Rectangle() { _largeur = _hauteur = 0; }

void Rectangle::setSize(double hauteur, double largeur)
{
    assert(hauteur >= 0);
    _hauteur = hauteur;
    _largeur = (largeur >= 0) ? largeur : hauteur;     //Si la largeur est égale à 0 ou plus petite : largeur = hauteur
}

double Rectangle::aire() const{ 
    return _hauteur * _largeur; 
}

void Rectangle::afficher(ostream& stream) const {
    stream << _hauteur << endl << _largeur << endl;
}

ostream& operator<<(ostream& stream, const Rectangle rectangle) {
    rectangle.afficher(stream);
    return stream;
}