/********
 * Fichier: rectangle.h
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Declaration de la classe rectangle.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.cpp"
#include <assert.h>

class Rectangle : public Forme
{
public:
    Rectangle(double = 0, double = 0, Coordonnee = {0,0});
    virtual ~Rectangle();   //! Le destructeur de Forme est appelé par défaut puisqu'il est virtuel* https://www.geeksforgeeks.org/virtual-destructor/
    virtual void setSize(double = 0, double = 0);
    double aire() const;
    void afficher(ostream&) const;

protected:
    double _largeur, _hauteur;
};

ostream& operator<<(ostream&, const Rectangle);

#endif