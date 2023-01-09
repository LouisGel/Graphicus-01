/********
 * Fichier: vecteur.cpp
 * Auteurs: Louis-Xavier Gélinas
 * Date: 09 janvier 2023 (creation)
 * Description: Implementation des methodes des classes decrites dans vecteur.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "vecteur.h"


//TODO : Lors de la création, on met _capacity à dimx2???
template <class TYPE>
Vecteur<TYPE>::Vecteur(int dim)
{
    assert(dim >= 0);
    _dim = dim;
    _capacity = dim*2;
    if(dim)
        _tab = new TYPE[_capacity]();   //!Les parenthèses set tout les items à 0 (Parce qu'on appel le constructeur et qu'il a des valeurs par défaut???)
    else
        _tab = nullptr;
}

template <class TYPE>
Vecteur<TYPE>::Vecteur(const Vecteur& vecteur)
{
    _dim = vecteur._dim;
    _capacity = vecteur._capacity;
    if(_capacity == 0){
        this->clear();
    } else {
        _tab = new TYPE[_capacity];
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
    //! TODO : Vrai ce truc???
	delete[] _tab;   //Les [] appel le destructeur de tous les éléments
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
TYPE& Vecteur<TYPE>::getTab() const
{
	return *_tab;
}

template <class TYPE>
void Vecteur<TYPE>::print(ostream& sortie) const
{
	for (int i = 0; i < _dim; i++)
		sortie << *(_tab + i) << " ";
}


template <class TYPE>
void Vecteur<TYPE>::push_back(const TYPE& elem)
{
    if(_dim == _capacity)
    {
        _capacity = (_capacity == 0) ? _capacity = 2 : _capacity = _capacity * 2;
        TYPE* temp_tab = new TYPE[_capacity];
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
}

template <class TYPE>
TYPE Vecteur<TYPE>::at(int pos) const
{
    if(pos > _dim) return TYPE{};
    return *(_tab + pos);
}

template <class TYPE>
TYPE Vecteur<TYPE>::operator[](int pos) const
{
    return this->at(pos);
}

template <class TYPE>
TYPE Vecteur<TYPE>::pop(int pos)
{    
    if(pos > _dim) return TYPE{};  //https://stackoverflow.com/questions/39429510/what-do-empty-braces-mean-in-struct-declaration
    TYPE temp = *(_tab + pos);
    _dim--;
    for (int i = pos; i < _dim; i++)
        *(_tab + i) = *(_tab + i + 1);
    *(_tab + _dim + 1) = 0; //On met le dernier elem à 0
    return temp;
}

template <class TYPE>
ostream& operator<<(ostream& out, const Vecteur<TYPE>& vec)
{
	vec.print(out);
	return out;
}