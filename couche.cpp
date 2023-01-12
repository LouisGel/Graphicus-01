/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche()
{
    _state = INITIALISEE;
}

Couche::~Couche()
{
    _state = '\0';
    _formes.clear();
}

bool Couche::ajouterForme(Forme* forme)
{
    if(forme == nullptr) return false;
    if(_state != ACTIVE) return false;
    return _formes.pushBack(forme);
}

Forme* Couche::enleverForme(int pos)
{
    if(_state != ACTIVE) return nullptr;
    return _formes.pop(pos);
}

Forme* Couche::getForme(int pos) const
{
    if(pos > 0 && !_formes.size()) return nullptr;
    return _formes.at(pos);
}

double Couche::aireTotale() const
{
    int qt_formes = _formes.size();
    double aire_total = 0;
    for (int i = 0; i < qt_formes; i++)
        aire_total += _formes[i]->aire();
    return aire_total;
}

bool Couche::translation(int horizontale, int verticale)
{
    if(_state != ACTIVE) return false;
    int qt_formes = _formes.size();
    if(!qt_formes) return false;
    for (int i = 0; i < qt_formes; i++)
        _formes.at(i)->translater(horizontale, verticale);
    return true;
}

void Couche::afficher(ostream& stream) const
{
    int qt_formes = _formes.size();
    for (int i = 0; i < qt_formes; i++)
        stream << _formes.at(i) << endl;
}

bool Couche::reinitialiser()
{
    _state = INITIALISEE;
    _formes.clear();
    return (!_formes.size());
}

bool Couche::setActive()
{
    _state = ACTIVE;
    return (_state == ACTIVE);
}

bool Couche::setInactive()
{
    _state = INACTIVE;
    return (_state == INACTIVE);
}

bool Couche::isActive() const
{
    return (_state == ACTIVE);
}

bool Couche::isInactive() const
{
    return (_state == INACTIVE);
}

ostream& operator<<(ostream& stream, const Couche couche)
{
    couche.afficher(stream);
    return stream;
}