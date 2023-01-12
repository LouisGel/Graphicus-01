
/*#include "forme.cpp"
#include "rectangle.cpp"
#include "vecteur.cpp"

int main()
{
    
    Vecteur<Forme> vec_old;

    cout << "============== TEST : Ajout élément et size" << endl;
    cout << vec_old.size() << endl;
    vec_old.pushBack(new Rectangle);
    cout << vec_old.size() << endl;

    cout << "============== TEST : Copieur" << endl;
    Vecteur<Forme> vec(vec_old);

    cout << "============== TEST : Clear" << endl;
    vec.clear();
    cout << vec.size() << endl;
    vec.pushBack(new Rectangle);

    cout << "============== TEST : Affichage élément" << endl;
    if(vec[0] != nullptr){
        (*vec[0]).afficher(cout);
        vec.at(0)->afficher(cout);
        Forme* p = (vec[0]);
        cout << *p;
    }

    cout << "============== TEST : Pop" << endl;
    Forme* rem = vec.pop(0);
    if(rem != nullptr) cout << "Success : " << *rem << endl;

    cout << "============== TEST : Autres" << endl;
    cout << "Capacity : " << vec.capacity();
    cout << "Size : " << vec.size();
    cout << "Size : " << vec.isEmpty();
    vec.pushBack(new Rectangle);
    cout << "Size : " << vec.isEmpty();


    cout << endl << "END" << endl;
    return 0;
}
*/