/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
    reinitialiser();
    couches[0].setActive();
}

Canevas::~Canevas()
{
    this->reinitialiser();
}

bool Canevas::reinitialiser()
{
    for (int i = 0; i < MAX_COUCHES; i++)
        if(!couches[i].reinitialiser() && !couches[i].setInactive()) return false;
    return true;
}

bool Canevas::activerCouche(int index)
{
    if(index > MAX_COUCHES) return false;
    Couche* coucheActive = this->getCoucheActive();
    if(coucheActive == nullptr) return false;
    coucheActive->setInactive();
    couches[index].setActive();
    return true;
}

bool Canevas::cacherCouche(int index)
{
   return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
    if(p_forme == nullptr) return false;
    Couche* coucheActive = this->getCoucheActive();
    if(coucheActive == nullptr) return false;
    if(!coucheActive->ajouterForme(p_forme)) return false;
    return true;
}

bool Canevas::retirerForme(int index)
{
    if(index > MAX_COUCHES) return false;
    Couche* coucheActive = this->getCoucheActive();
    if(coucheActive == nullptr) return false;
    if(!coucheActive->enleverForme(index)) return false;
    return true;    
}

double Canevas::aire()
{
    double aire_total = 0;
    for (int i = 0; i < MAX_COUCHES; i++)
        aire_total += couches[i].aireTotale();
   return aire_total;
}

bool Canevas::translater(int deltaX, int deltaY)
{
    Couche* coucheActive = this->getCoucheActive();
    if(coucheActive == nullptr) return false;
    if(!coucheActive->translation(deltaX, deltaY)) return false;
    return true;
}

void Canevas::afficher(ostream& stream)
{
    for (int i = 0; i < MAX_COUCHES; i++)
        stream << "----- Couche " << i << endl << couches[i];
}

Couche* Canevas::getCoucheActive()
{
    for (int i = 0; i < MAX_COUCHES; i++)
        if(couches[i].isActive()) return &couches[i];
    return nullptr;
}