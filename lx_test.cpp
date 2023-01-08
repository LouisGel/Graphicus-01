
/*
#include <iostream>
#include <assert.h>
*/

#include "rectangle.cpp"

int main(int argc, char const *argv[])
{
    Rectangle r(1, 2, {1,1});
    cout << "Size : " << endl;
    r.afficher(cout);
    r.setSize(3,4);
    cout << r;

    cout << "Ancrage : " << r.getAncrage().x << r.getAncrage().y << endl;
    r.setAncrage({2,3});
    cout << "Ancrage : " << r.getAncrage().x << r.getAncrage().y << endl;

    cout << "Aire : " << r.aire() << endl;
    
    return 0;
}
