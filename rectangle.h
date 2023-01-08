/********
 * Fichier: rectangle.h
 * Auteurs: Louis-Xavier Gélinas
 * Date: 07 janvier 2023 (creation)
 * Description: Declaration de la classe rectangle. La
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.cpp"
#include <assert.h>

//TODO : Dans le contructeur, mettre default value de largeur à 0???
//TODO : Lors de la création, vérifier si le point d'encrage est dans la forme???
//TODO : Private???
class Rectangle : public Forme
{
private:
    double _largeur, _hauteur;

public:
    //constructeur
    Rectangle(double, Coordonnee);
    Rectangle(double, double, Coordonnee);

    //destructeur
    ~Rectangle();   //! Le destructeur de Forme est appelé par défaut puisqu'il est virtuel* https://www.geeksforgeeks.org/virtual-destructor/
    
    void setSize(double = 0, double = 0);
    double aire() const;
    void afficher(ostream & s) const;

};

ostream& operator<<(ostream& stream, const Rectangle rectangle);

#endif