/********
 * Fichier: carre.h
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Declaration de la classe carre.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CARRE_H
#define CARRE_H

#include "rectangle.h"

class Carre : public Rectangle
{
public:

    //Constructeurs/Destructeur
    Carre(double = 0, Coordonnee = {0,0});
    ~Carre();

    //Getters
    //! On en a besoin???

    //Setters
    void setSize(double = 0);

    //Surcharge d'opérateurs
    Carre& operator=(Carre&);
    bool operator==(Carre&) const;

    //Autres
    void afficher(ostream&) const;

};

ostream& operator<<(ostream&, const Carre&);

#endif