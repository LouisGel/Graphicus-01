
#include "Canevas.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Cercle.h"


void printHeaderTest(int id){
    cout << "===================================" << endl;
    cout << "              TEST " << id << "               " << endl;
    cout << "===================================" << endl;

}

int main()
{

    Canevas monDessin;

    //! ===================================================== Étape 1
    printHeaderTest(1);
    if(!monDessin.activerCouche(1)) cout << "Erreur lors de l'activation de la couche 1";
    
    //! ===================================================== Étape 2
    printHeaderTest(2);
    if(!monDessin.ajouterForme(new Rectangle(2, 3, {0, 0}))) cout << "Erreur lors de l'ajout du Rectangle sur la couche 1";
    if(!monDessin.ajouterForme(new Carre(4, {2, 3}))) cout << "Erreur lors de l'ajout du Carré sur la couche 1";
    if(!monDessin.ajouterForme(new Cercle(6, {7, 8}))) cout << "Erreur lors de l'ajout du Cercle sur la couche 1";

    //! ===================================================== Étape 3
    printHeaderTest(3);
    if(!monDessin.activerCouche(2)) cout << "Erreur lors de l'activation de la couche 2";

    //! ===================================================== Étape 4
    printHeaderTest(4);
    if(!monDessin.ajouterForme(new Rectangle(4, 5, {0, 0}))) cout << "Erreur lors de l'ajout du Rectangle sur la couche 1";

    //! ===================================================== Étape 5
    printHeaderTest(5);
    cout << "Affichage du canevas : " << endl << monDessin << endl;

    //! ===================================================== Étape 6
    printHeaderTest(6);
    cout << "Aire total du Canevas : " << monDessin.aire() << endl;

    //! ===================================================== Étape 7
    printHeaderTest(7);
    if(!monDessin.activerCouche(0)) cout << "Erreur lors de l'activation de la couche 0";
    if(!monDessin.ajouterForme(new Rectangle(1, 1, {0, 0}))) cout << "Erreur lors de l'ajout du Rectangle sur la couche 0";
    if(!monDessin.ajouterForme(new Carre(1, {2, 3}))) cout << "Erreur lors de l'ajout du Carré sur la couche 0";
    if(!monDessin.ajouterForme(new Cercle(1, {7, 8}))) cout << "Erreur lors de l'ajout du Cercle sur la couche 0";

    //! ===================================================== Étape 8
    printHeaderTest(8);
    if(!monDessin.activerCouche(1)) cout << "Erreur lors de l'activation de la couche 1";
    if(!monDessin.translater(5, 5)) cout << "Erreur lors de la translation de la couche 1";

    //! ===================================================== Étape 9
    printHeaderTest(9);
    if(!monDessin.activerCouche(2)) cout << "Erreur lors de l'activation de la couche 2";

    //! ===================================================== Étape 10
    printHeaderTest(10);
    if(!monDessin.activerCouche(3)) cout << "Erreur lors de l'activation de la couche 3";

    //! ===================================================== Étape 11
    printHeaderTest(11);
    if(!monDessin.activerCouche(4)) cout << "Erreur lors de l'activation de la couche 4";

    //! ===================================================== Étape 12
    printHeaderTest(12);
    cout << "Affichage du canevas : " << endl << monDessin << endl;

    //! ===================================================== Étape 13
    printHeaderTest(13);
    cout << "Affichage du canevas : " << endl << monDessin.aire() << endl;

    //! ===================================================== Étape 14
    printHeaderTest(14);
    if(!monDessin.activerCouche(1)) cout << "Erreur lors de l'activation de la couche 1";
    if(!monDessin.retirerForme(0)) cout << "Erreur lors du retrait de la Forme";

    //! ===================================================== Étape 15
    printHeaderTest(15);
    cout << "Affichage du canevas : " << endl << monDessin << endl;

    //! ===================================================== Étape 16
    printHeaderTest(16);
    cout << "Affichage du canevas : " << endl << monDessin.aire() << endl;

    //! ===================================================== Étape 17
    printHeaderTest(17);
    if(!monDessin.reinitialiser()) cout << "Erreur lors de la réinitialisation du Canevas";

    //! ===================================================== Étape 18
    printHeaderTest(18);
    cout << "Affichage du canevas : " << endl << monDessin << endl;

    //! ===================================================== Étape 19
    printHeaderTest(19);
    cout << "Affichage du canevas : " << endl << monDessin.aire() << endl;


    return 0;
}
