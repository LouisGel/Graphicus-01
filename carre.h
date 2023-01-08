/********
 * Fichier: carre.h
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Declaration de la classe carre.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CARRE_H
#define CARRE_H

#include "rectangle.cpp"

class Carre : public Rectangle
{
public:
    Carre(double = 0, Coordonnee = {0,0});
    ~Carre();
    void setSize(double = 0);
    double aire() const;
    void afficher(ostream&) const;
};

ostream& operator<<(ostream&, const Carre);

#endif