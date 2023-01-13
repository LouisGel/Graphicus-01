#include "forme.h"
#include <iostream>
using namespace std;


void test(ostream& x){
    //! On reçois x = cout
    //! Donc on peut faire :
    x << "bonjour";
}


int main(){


    ostream* nouveau_cout;
    Forme* forme;
    int* x;
    double* y;

    cout << "salut";
    test(cout);

    return 0;
}


