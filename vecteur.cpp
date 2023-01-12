/********
 * Fichier: vecteur.cpp
 * Auteurs: Louis-Xavier Gélinas
 * Date: 09 janvier 2023 (creation)
 * Description: Implementation des methodes des classes decrites dans vecteur.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "vecteur.h"

template <class TYPE>
Vecteur<TYPE>::Vecteur(int dim)
{
    assert(dim >= 0);
    _dim = dim;
    _capacity = dim*2;
    if(dim)
        _tab = new TYPE*[_capacity]();
    else
        _tab = nullptr;
}

template <class TYPE>
Vecteur<TYPE>::Vecteur(const Vecteur& vecteur)
{
    _dim = vecteur._dim;
    _capacity = vecteur._capacity;
    if(_capacity == 0){
        clear();
    } else {
        _tab = new TYPE*[_capacity];
        for (int i = 0; i < _dim; i++)
            *(_tab + i) = vecteur._tab[i];
    }
}

template <class TYPE>
Vecteur<TYPE>::~Vecteur()
{
    clear();
}

template <class TYPE>
void Vecteur<TYPE>::clear()
{
    for (int i = 0; i < _dim; i++)  //Appel le destructeur pour tous les éléments
        delete *(_tab + i);
	delete[] _tab;  //Détruit le tableau de pointeur
    _dim = _capacity = 0;
	_tab = nullptr;
}

template <class TYPE>
int Vecteur<TYPE>::size() const
{
	return _dim;
}

template <class TYPE>
int Vecteur<TYPE>::capacity() const
{
	return _capacity;
}

template <class TYPE>
bool Vecteur<TYPE>::isEmpty() const
{
    return (_dim > 0);
}

template <class TYPE>
void Vecteur<TYPE>::print(ostream& sortie) const
{
	for (int i = 0; i < _dim; i++)
		sortie << *(_tab + i) << " ";
}

template <class TYPE>
TYPE* Vecteur<TYPE>::at(int pos) const
{
    if(pos > _dim || !_dim) return nullptr;
    return *(_tab + pos);
}

template <class TYPE>
TYPE* Vecteur<TYPE>::operator[](int pos) const
{
    return at(pos);
}

template <class TYPE>
bool Vecteur<TYPE>::push_back(TYPE* elem)
{
    if(elem == nullptr) return false;
    if(_dim == _capacity)
    {
        _capacity = (_capacity == 0) ? _capacity = 2 : _capacity = _capacity * 2;
        TYPE** temp_tab = new TYPE*[_capacity];
        for (int i = 0; i < _dim; i++)
            *(temp_tab + i) = *(_tab + i);
        *(temp_tab + _dim) = elem;
        delete[] _tab;
        _tab = temp_tab;
    }
    else
    {
        *(_tab + _dim) = elem;
    }
    _dim++;
    return true;
}

template <class TYPE>
TYPE* Vecteur<TYPE>::pop(int pos)
{
    if(pos > _dim) return nullptr;
    TYPE* temp = *(_tab + pos);
    _dim--;
    for (int i = pos; i < _dim; i++)
        *(_tab + i) = *(_tab + i + 1);
    *(_tab + _dim + 1) = nullptr; //On met le dernier elem à 0
    return temp;
}

template <class TYPE>
ostream& operator<<(ostream& out, const Vecteur<TYPE>& vec)
{
	vec.print(out);
	return out;
}