
/*
#include <iostream>
#include <assert.h>
*/


//TODO : Lors de la création, vérifier si le point d'encrage est dans la forme???


#include "carre.cpp"

int main(int argc, char const *argv[])
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


   Carre c(7);

    cout << "Size : " << endl;
    c.afficher(cout);
    c.setSize(3);
    cout << c;

    cout << "Ancrage : " << c.getAncrage().x << c.getAncrage().y << endl;
    c.setAncrage({2,3});
    cout << "Ancrage : " << c.getAncrage().x << c.getAncrage().y << endl;

    cout << "Aire : " << c.aire() << endl;
   

    return 0;
}
