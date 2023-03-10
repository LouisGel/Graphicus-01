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
	TYPE** _tab;
	int _dim, _capacity;

public:
	Vecteur(int = 0);
    Vecteur(const Vecteur&);
	~Vecteur();

	void clear();
    int size() const;
    int capacity() const;
    bool isEmpty() const;

    void print(ostream&) const;

    TYPE* at(int pos) const;
	TYPE* operator[](int pos) const;

    bool pushBack(TYPE*);
    TYPE* pop(int);

};

template<class TYPE>
ostream& operator<<(ostream& stream, const Vecteur<TYPE>& vec);

template <class TYPE>
Vecteur<TYPE>::Vecteur(int dim)
{
    assert(dim >= 0);
    _dim = 0;
    _capacity = dim*2;
    _tab = (dim) ? new TYPE*[_capacity] : nullptr; 
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
    return (_dim == 0);
}

template <class TYPE>
void Vecteur<TYPE>::print(ostream& sortie) const
{
	for (int i = 0; i < _dim; i++)
		sortie << *(*(_tab + i)) << endl;
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
bool Vecteur<TYPE>::pushBack(TYPE* elem)
{
    if(elem == nullptr) return false;
    if(_dim == _capacity)
    {
        _capacity = (_capacity == 0) ? 2 : _capacity * 2;
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
    if(_dim == 0) return nullptr;
    if(pos > _dim) return nullptr;
    TYPE* temp = *(_tab + pos);
    _dim--;
    if(_dim != 0)   //S'il n'y avait qu'un seule élément
        for (int i = pos; i < _dim; i++)
            *(_tab + i) = *(_tab + i + 1);
    *(_tab + _dim + 1) = nullptr;   //On clean la mémoire en mettant le dernier elem à nullptr
    return temp;
}

template <class TYPE>
ostream& operator<<(ostream& out, const Vecteur<TYPE>& vec)
{
	vec.print(out);
	return out;
}

#endif