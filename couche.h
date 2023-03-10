/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef COUCHE_H
#define COUCHE_H

#include "forme.h"
#include "vecteur.hpp"

#define INITIALISEE 73  //ASCII value for I
#define ACTIVE 65       //ASCII value for A
#define INACTIVE 78     //ASCII value for N

class Couche
{
public:
    Couche();
    ~Couche();

    bool ajouterForme(Forme*);
    Forme* enleverForme(int);
    Forme* getForme(int) const;
    double aireTotale() const;
    bool translation(int horizontale, int verticale);
    void afficher(ostream&) const;

    bool reinitialiser();

    bool setActive();
    bool setInactive();
    bool isActive() const;
    bool isInactive() const;
    bool isInitialise() const;
    bool isEmpty() const;

protected:
    Vecteur<Forme> _formes;
    char _state;
};

ostream& operator<<(ostream&, const Couche&);

#endif
