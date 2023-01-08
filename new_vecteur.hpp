#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

template <class TYPE>
class Vecteur
{
private:
	TYPE *_tab;
	int _dim;
	int _tab_dim;

public:
	Vecteur(int dim = 0);
    Vecteur(const Vecteur &v);
	~Vecteur();

	void clear();

};

template <class TYPE>
Vecteur<TYPE>::Vecteur(int dim){
    assert(dim >= 0);
    _dim = dim;
    if(dim)
        _tab = new TYPE[dim];
    else
        _tab = nullptr;
}


template <class TYPE>
Vecteur<TYPE>::Vecteur(const Vecteur& vecteur){
    _dim = vecteur._dim;
    if(_dim == 0){
        this->clear();
    } else {
        _tab = new TYPE[_dim];
        for (int i = 0; i < _dim; i++)
            *(_tab + i) = vecteur._tab[i];
    }
}

template <class TYPE>
Vecteur<TYPE>::~Vecteur() {
	clear();
}



template <class TYPE>
void Vecteur<TYPE>::clear() {
	delete[]_tab;
    _dim = 0;
	_tab = nullptr;
}
