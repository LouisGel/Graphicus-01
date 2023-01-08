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

public:
	//constructeur
	Vecteur();
	Vecteur(int dim);
	
	//destructeur
	~Vecteur();

	//copieur
	Vecteur(const Vecteur &v);

	TYPE size()const;
	TYPE& getTab()const;

	void print(ostream& sortie)const;
	
	void push_back(int num);
	void resize(int dim);
	void clear();
	void swap(Vecteur<TYPE>& v1);
	void swap(Vecteur<TYPE>& v1, Vecteur<TYPE>& v2);
	void inverse();
	void inverseRecursive();

	Vecteur<TYPE>& operator=(const Vecteur<TYPE>& v);
	Vecteur<TYPE> operator+(const Vecteur<TYPE>& v1);
	Vecteur<TYPE>& operator+=(const Vecteur<TYPE>& v1);

	TYPE at(int pos);
	TYPE operator[](int pos)const;
};


template <class TYPE>
ostream& operator<<(ostream& sortie, const Vecteur<TYPE>& v);
template <class TYPE>
const bool operator==(const Vecteur<TYPE> v1, const Vecteur<TYPE> v2);

template <class TYPE>
Vecteur<TYPE>::Vecteur()
{
	_dim = 0;
	_tab = new TYPE[_dim];
}

template <class TYPE>
Vecteur<TYPE>::Vecteur(int dim)
{
	assert(dim > 0);
	_dim = dim;
	_tab = new TYPE[_dim];
	for (int i = 0; i < _dim; i++) {
		*(_tab + i) = 0;
	}
}

template <class TYPE>
Vecteur<TYPE>::~Vecteur()
{
	_dim = 0;
	clear();
}

template <class TYPE>
Vecteur<TYPE>::Vecteur(const Vecteur<TYPE>& v)
{
	_dim = v.size();
	_tab = new TYPE[_dim];
	for (int i = 0; i < _dim; i++) {
		*(_tab + i) = *(v._tab + i);
	}

}

template <class TYPE>
TYPE Vecteur<TYPE>::size() const
{
	return _dim;
}

template <class TYPE>
TYPE& Vecteur<TYPE>::getTab() const
{
	return *_tab;
}

template <class TYPE>
void Vecteur<TYPE>::print(ostream& sortie)const
{
	for (int i = 0; i < _dim; i++) {
		sortie << *(_tab + i) << " ";
	}
}

template <class TYPE>
void Vecteur<TYPE>::push_back(int num)
{
	assert(num > 0);
	int dim = _dim;
	int* tab = new int[size() + 1];
	for (int i = 0; i < size(); i++) {
		*(tab + i) = *(&this->getTab() + i);
	}
	*(tab + size()) = num;

	clear();

	_dim = dim +1;
	_tab = new TYPE[_dim];

	for (int i = 0; i < size(); i++) {
		*(_tab + i) = *(tab + i);
	}

	tab = nullptr;
	delete tab;
}

template <class TYPE>
void Vecteur<TYPE>::resize(int dim)
{

	assert(dim > 0);

	if (dim > _dim) {
		int* tab = new int[dim];
		for (int i = 0; i < dim; i++) {
			if (i < _dim) {
				*(tab + i) = *(&this->getTab() + i);
			}
			else {
				*(tab + i) = 0;
			}
		}
		clear();

		_dim = dim;
		_tab = new int[dim];

		for (int i = 0; i < dim; i++) {
			*(_tab + i) = *(tab + i);
		}
		tab = nullptr;
		delete tab;
	}
	else {

		int* tab = new int[dim];
		for (int i = 0; i < dim; i++) {
			*(tab + i) = *(&this->getTab() + i);
		}

		clear();

		_dim = dim;
		_tab = new TYPE[_dim];

		for (int i = 0; i < dim; i++) {
			*(_tab + i) = *(tab + i);
		}

		tab = nullptr;
		delete tab;

		//Aurait du juste mettre les index � 0 et r�duire la dim???
	}


}

template <class TYPE>
void Vecteur<TYPE>::clear()
{
	_dim = 0;
	_tab = nullptr;
	delete _tab;
}

template <class TYPE>
void Vecteur<TYPE>::swap(Vecteur<TYPE>& v1)
{
	assert(size() == v1.size());

	int dim = size();

	Vecteur<TYPE> vec(dim);
	vec = v1;
	v1 = *this;
	clear();
	*this = vec;
}

template <class TYPE>
void Vecteur<TYPE>::swap(Vecteur<TYPE>& v1, Vecteur<TYPE>& v2)
{
	assert(v1.size() == v2.size());

	int dim = v1.size();

	Vecteur<TYPE> vec(dim);
	vec = v1;
	v1 = v2;
	clear();
	v2 = vec;
}

template <class TYPE>
void Vecteur<TYPE>::inverse()
{
	if (_dim == 0) return;

	int* tab = new TYPE[_dim];
	for (int i = 0; i < _dim; i++) {
		*(tab + i) = *(_tab + i);
	}

	int dim = _dim;
	clear();
	_dim = dim;
	_tab = new int[dim];

	for (int i = 0; i < _dim; i++) {
		*(_tab + i) = *(tab + _dim - i - 1);
	}
}


template <class TYPE>
Vecteur<TYPE>& Vecteur<TYPE>::operator=(const Vecteur<TYPE>& v)
{
	clear();
	_dim = v._dim;
	_tab = nullptr;
	_tab = new TYPE[_dim];
	for (int i = 0; i < v._dim; i++) {
		*(_tab + i) = *(v._tab + i);
	}
	return *this;
}

template <class TYPE>
Vecteur<TYPE> Vecteur<TYPE>::operator+(const Vecteur<TYPE>& v1)
{
	int dim = _dim + v1.size();
	int* tab = new int[dim];

	for (int i = 0; i < _dim; i++) {
		*(tab + i) = *(&this->getTab() + i);
	}

	for (int i = 0; i < v1.size(); i++) {
		*(tab + i + _dim) = *(v1._tab + i);
	}

	clear();
	_dim = dim;
	_tab = new TYPE[_dim];

	for (int i = 0; i < _dim; i++) {
		*(_tab + i) = *(tab + i);
	}

	return *this;
}

template <class TYPE>
Vecteur<TYPE>& Vecteur<TYPE>::operator+=(const Vecteur<TYPE>& v1)
{
	int dim = _dim + v1.size();
	int* tab = new int[dim];

	for (int i = 0; i < _dim; i++) {
		*(tab + i) = *(&this->getTab() + i);
	}

	for (int i = 0; i < v1.size(); i++) {
		*(tab + i + _dim) = *(v1._tab + i);
	}

	clear();
	_dim = dim;
	_tab = new TYPE[_dim];

	for (int i = 0; i < _dim; i++) {
		*(_tab + i) = *(tab + i);
	}

	return *this;
}

template <class TYPE>
TYPE Vecteur<TYPE>::at(int pos)
{
	assert(pos < _dim);
	if (_dim == 0){
		return 0;
	}
	return *(_tab + pos);
}

template <class TYPE>
TYPE Vecteur<TYPE>::operator[](int pos)const
{
	assert(pos < _dim);
	if (_dim == 0) {
		return 0;
	}
	return *(_tab + pos);
}

template <class TYPE>
ostream& operator<<(ostream& sortie, const Vecteur<TYPE>& v)
{
	v.print(cout);
	return sortie;
}

template <class TYPE>
const bool operator==(const Vecteur<TYPE> v1, const Vecteur<TYPE> v2)
{
	if (v1.size() == v2.size()) {
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] == v2[i]) {

			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
	return true;
}