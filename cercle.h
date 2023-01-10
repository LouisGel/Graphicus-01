/********
 * Fichier: cercle.h
 * Auteurs: Louis-Xavier Gélinas
 * Date: 09 janvier 2023 (creation)
 * Description: Declaration de la classe cercle.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CERCLE_H
#define CERCLE_H

#include <cmath>
#include <assert.h>
#include "forme.cpp"

class Cercle : public Forme
{
public:

    //Constructeurs/Destructeur
    Cercle(double = 0, Coordonnee = {0,0});
    ~Cercle();

    //Getters
    double getRayon() const;

    //Setters
    void setRayon(double);

    //Surcharge d'opérateurs
    Cercle& operator=(Cercle&);
    bool operator==(Cercle&) const;

    //Autres
    double aire() const;
    void afficher(ostream&) const;

protected:
    double _rayon;
};

ostream& operator<<(ostream&, const Cercle);

#endif