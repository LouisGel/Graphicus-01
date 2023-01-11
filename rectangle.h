/********
 * Fichier: rectangle.h
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Declaration de la classe rectangle.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <assert.h>
#include "forme.h"

class Rectangle : public Forme
{
public:

    //Constructeurs/Destructeur
    Rectangle(double = 0, double = 0, Coordonnee = {0,0});
    virtual ~Rectangle();   //! Le destructeur de Forme est appelé par défaut puisqu'il est virtuel* https://www.geeksforgeeks.org/virtual-destructor/

    //Getters
    double getLargeur() const;
    double getHauteur() const;

    //Setters
    virtual void setSize(double = 0, double = 0);
    
    //Surcharge d'opérateurs
    Rectangle& operator=(Rectangle&);
    bool operator==(Rectangle&) const;

    //Autres
    double aire() const;
    void afficher(ostream&) const;

protected:
    double _largeur, _hauteur;
};

ostream& operator<<(ostream&, const Rectangle);

#endif