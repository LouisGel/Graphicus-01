

//TODO : Lors de la création, vérifier si le point d'encrage est dans la forme???
//TODO : forme.cpp destructeur, destruction de la struct coordonnee???

#include "forme.cpp"
#include "rectangle.cpp"
#include "carre.cpp"
#include "vecteur.cpp"

int main()
{

    Vecteur<Forme*> vec;
    vec.push_back(new Carre);
    if(vec.at(90) == nullptr) cout << "nullptr" << endl;

    if(vec.at(0)) vec.at(0)->aire();

    return 0;
}
