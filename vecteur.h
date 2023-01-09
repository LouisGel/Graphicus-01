/********
 * Fichier: vecteur.h
 * Auteurs: Louis-Xavier Gélinas
 * Date: 09 janvier 2023 (creation)
 * Description: Declaration de la classe vecteur.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef VECTEUR_H
#define VECTEUR_H


#include <iostream>
#include <assert.h>

using namespace std;

template <class TYPE>
class Vecteur
{
private:
	TYPE *_tab;
	int _dim;
	int _capacity;

public:
	Vecteur(int dim = 0);
    Vecteur(const Vecteur&);
	~Vecteur();

	void clear();
    int size() const;
    int capacity() const;
    bool isEmpty() const;
    TYPE& getTab() const;
    void print(ostream&) const;

	TYPE at(int pos) const;             //! TODO : Aurait préféré TYPE&
	TYPE operator[](int pos) const;

    void push_back(const TYPE&);
    TYPE pop(int);
};

template<class TYPE>
ostream& operator<<(ostream& stream, const Vecteur<TYPE>& vec);

#endif