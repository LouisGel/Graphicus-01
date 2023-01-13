
#include "Canevas.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Cercle.h"


int main()
{

    //! =====================================================TEST 1
    cout << "===================================" << endl; 
    cout << "              TEST 1               " << endl; 
    cout << "===================================" << endl; 

    Canevas monDessin;
    if(!monDessin.activerCouche(0)) cout << "Erreur lors de l'activation de la couche 0";

    if(!monDessin.ajouterForme(new Cercle(4, {5, 1}))) cout << "Erreur lors de l'ajout du Cercle sur la couche 0";
    if(!monDessin.ajouterForme(new Carre(1, {0, 0}))) cout << "Erreur lors de l'ajout du Carré sur la couche 0";
    
    if(!monDessin.activerCouche(1)) cout << "Erreur lors de l'activation de la couche 1";
    if(!monDessin.ajouterForme(new Rectangle(2, 3, {2, 3}))) cout << "Erreur lors de l'ajout du Rectangle sur la couche 1";

    cout << "Affichage du canevas : " << endl << monDessin << endl;
    cout << "Affichage de l'aire de la couche 1' : " <<  monDessin.aire() << endl << endl;



    //! =====================================================TEST 2
    cout << "===================================" << endl;
    cout << "              TEST 2               " << endl;
    cout << "===================================" << endl;

    if(!monDessin.activerCouche(0)) cout << "Erreur lors de l'activation de la couche 0";
    if(!monDessin.translater(2, 3)) cout << "Erreur lors de la translation de la couche 0";

    cout << "Affichage du canevas : " << endl << monDessin << endl;
    cout << "Affichage de l'aire de la couche 0' : " <<  monDessin.aire() << endl << endl;



    //! =====================================================TEST 3
    cout << "===================================" << endl;
    cout << "              TEST 3               " << endl;
    cout << "===================================" << endl;
    if(!monDessin.activerCouche(0)) cout << "Erreur lors de l'activation de la couche 0";
    
    Forme* p_cercle = monDessin.getCoucheActive()->enleverForme(0);
    if(p_cercle == nullptr) cout << "Erreur lors du retrait de la première forme";
    
    cout << "Affichage du canevas : " << endl << monDessin << endl;
    cout << "Affichage de l'aire de la couche 0 : " <<  monDessin.aire() << endl << endl;



    //! =====================================================TEST 4
    cout << "===================================" << endl;
    cout << "              TEST 4               " << endl;
    cout << "===================================" << endl;
    if(!monDessin.activerCouche(3)) cout << "Erreur lors de l'activation de la couche 3";   //! Aurait pu la mettre sur la couche 2 
    
    if(!monDessin.ajouterForme(new Carre(2, {1, 1}))) cout << "Erreur lors de l'ajout du Carré sur la couche 3";

    cout << "Affichage du canevas : " << endl << monDessin << endl;
    cout << "Affichage de l'aire de la couche 2 : " <<  monDessin.aire() << endl << endl;



    //! =====================================================TEST 5
    cout << "===================================" << endl;
    cout << "              TEST 5               " << endl;
    cout << "===================================" << endl;
    if(!monDessin.activerCouche(3)) cout << "Erreur lors de l'activation de la couche 3";

    if(!monDessin.reinitialiser()) cout << "Erreur lors de la réinitialisation du Canevas";

    cout << "Affichage du canevas : " << endl << monDessin << endl;


    return 0;
}
