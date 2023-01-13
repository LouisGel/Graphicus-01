#include "coordonnee.h"


void test(Coordonnee co){

}


int main(){

    //! ============== Soit tu fais ça :
    Coordonnee c;
    c.x = 1;
    c.y = 2;
    test(c);

    //! ============== Ou tu peux aussi définir une struct comme ça :
    test({1,2});    //* Avec la première valeur qui sera égale à x et la deuxième à y

    return 0;
}