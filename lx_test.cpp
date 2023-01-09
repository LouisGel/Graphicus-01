

//TODO : Lors de la création, vérifier si le point d'encrage est dans la forme???


#include "carre.cpp"
#include <vector>
/*
#include <iostream>
using namespace std;
*/

#include "vecteur.cpp"

int main()
{


    /*
    Rectangle r(1,3, {0,0});
    cout << "Size : " << endl;
    r.afficher(cout);
    r.setSize(3,4);
    cout << r;

    cout << "Ancrage : " << r.getAncrage().x << r.getAncrage().y << endl;
    r.setAncrage({2,3});
    cout << "Ancrage : " << r.getAncrage().x << r.getAncrage().y << endl;

    cout << "Aire : " << r.aire() << endl;
    */

/*
   Carre c(7);

    cout << "Size : " << endl;
    c.afficher(cout);
    c.setSize(3);
    cout << c;

    cout << "Ancrage : " << c.getAncrage().x << c.getAncrage().y << endl;
    c.setAncrage({2,3});
    cout << "Ancrage : " << c.getAncrage().x << c.getAncrage().y << endl;

    cout << "Aire : " << c.aire() << endl;
   
*/
    
    /*vector<int> y(5);
    cout << y[0] << endl;*/
    
    //Vecteur<int> x(1);
    //Vecteur<float> y(1);
    //Vecteur<Forme> z(1);

    Vecteur<Forme*> forme;
    cout << forme.isEmpty() << endl;
    forme.push_back(new Carre(2));
    forme.push_back(new Rectangle(2,4));
    cout << forme.isEmpty() << endl;
    
    cout << "TEST INDEX" << endl;
    cout << forme[0] << endl;


    Forme *removedForme;
    removedForme = forme.pop(7);
    if(removedForme == nullptr) cout << "Oui!";


    Vecteur<int> ints;
    ints.push_back(2);
    cout << "TEST INT" << endl;
    cout << ints[0] << endl;
    int removedInt;
    removedInt = ints.pop(7);
    if(removedInt == 0) cout << "Oui!";

    cout << forme[0]->aire();

    cout << endl;
    forme.clear();
    cout << "Fin";

/*
    Forme* x{};
    cout << x;
    if(x == nullptr)
        cout << "oui";
    else
        cout << "non";
*/

    /*int x;
    cout << x;
    if(x == 0)
        cout << "oui";
    else
        cout << "non";
*/
    /*
    cout << forme.size() << endl;
    cout << (*forme[0]).aire() << endl;
    cout << forme[1]->aire() << endl;

    cout << forme.size() << endl;
    cout << (*forme[0]).aire() << endl;
    //cout << forme[1]->aire() << endl;       //Erreur prévue
    */
    /*
    *Affiche l'addresse
    cout << (&forme[0]) << endl;
    cout << &(forme[0]) << endl;
    */

/*
    cout << "Size : " << x.size() << " " << x.capacity() << endl;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.print(cout);
    cout << endl;
    cout << "Size : " << x.size() << " " << x.capacity() << endl;
*/

    return 0;
}
