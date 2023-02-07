/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

void printHeaderTest(int id);

void Tests::tests_unitaires_formes()
{

    cout << "Test Unitaire Formes" << endl;

    //! ============================================================================= Test 1
    printHeaderTest(1);
    Rectangle* p_rectangle = new Rectangle;
    Carre* p_carre = new Carre;
    Cercle* p_cercle = new Cercle;

    cout << *(p_rectangle) << endl;
    cout << *(p_carre) << endl;
    cout << *(p_cercle) << endl;

    delete p_rectangle;
    delete p_carre;
    delete p_cercle;


    //! ============================================================================= Test 2
    printHeaderTest(2);
    p_rectangle = new Rectangle(1,2, {1,1});
    p_carre = new Carre(3, {1,1});
    p_cercle = new Cercle(4, {1,1});

    cout << *(p_rectangle) << endl;
    cout << *(p_carre) << endl;
    cout << *(p_cercle) << endl;


    //! ============================================================================= Test 3
    printHeaderTest(3);
    Rectangle rectangle(*p_rectangle);
    Carre carre(*p_carre);
    Cercle cercle(*p_cercle);

    cout << rectangle << endl;
    cout << carre << endl;
    cout << cercle << endl;


    //! ============================================================================= Test 4
    printHeaderTest(4);
    p_rectangle->afficher(cout);
    cout << endl;
    p_carre->afficher(cout);
    cout << endl;
    p_cercle->afficher(cout);
    cout << endl;


    //! ============================================================================= Test 5
    printHeaderTest(5);
    cout << rectangle << endl;
    cout << carre << endl;
    cout << cercle << endl;

}

void Tests::tests_unitaires_vecteur()
{

    cout << "Test Unitaire Vecteur" << endl;
    Vecteur<Forme> vec(1);

    //! ============================================================================= Test 6
    printHeaderTest(6);
    cout << "Dimension  : " << vec.size() << endl;
    cout << "Capacité  : " << vec.capacity() << endl;


    //! ============================================================================= Test 7
    printHeaderTest(7);
    if(!vec.pushBack(new Rectangle(2, 5, {0, 0}))) cout << "Erreur lors de l'ajout du Rectangle dans le vecteur" << endl;
    cout << "Dimension  : " << vec.size() << endl;
    cout << "Capacité  : " << vec.capacity() << endl;


    //! ============================================================================= Test 8
    printHeaderTest(8);
    if(!vec.pushBack(new Carre(3, {0, 0}))) cout << "Erreur lors de l'ajout du Carre dans le vecteur" << endl;
    if(!vec.pushBack(new Cercle(4, {0, 0}))) cout << "Erreur lors de l'ajout du Cercle dans le vecteur" << endl;
    cout << "Dimension  : " << vec.size() << endl;
    cout << "Capacité  : " << vec.capacity() << endl;


    //! ============================================================================= Test 9
    printHeaderTest(9);
    cout << "Avant : " << endl;
    cout << vec;
    Forme* p_forme = vec.pop(1);
    if(p_forme == nullptr) cout << "Erreur lors du retrait de la Forme";
    cout << "Après : " << endl;
    cout << vec;


    //! ============================================================================= Test 10
    printHeaderTest(10);
    Vecteur<Forme> vec2(10);
    cout << vec2 << endl;

}

void Tests::tests_unitaires_couche()
{
    cout << "Test Unitaire Couche" << endl;
    Couche couche;

    //! ============================================================================= Test 11
    printHeaderTest(11);
    if(!couche.setActive()) cout << "Erreur lors de l'activation de la couche" << endl;
    if(!couche.ajouterForme(new Rectangle(2, 4))) cout << "Erreur lors de l'ajout du Rectangle dans la couche" << endl;
    if(!couche.ajouterForme(new Carre(2))) cout << "Erreur lors de l'ajout du Carre dans la couche" << endl;
    if(!couche.ajouterForme(new Cercle(5))) cout << "Erreur lors de l'ajout du Cercle dans la couche" << endl;
    cout << couche.aireTotale() << endl;


    //! ============================================================================= Test 12
    printHeaderTest(12);
    cout << "Après : " << endl;
    cout << couche;
    Forme* p_forme2 = couche.enleverForme(1);
    if(p_forme2 == nullptr) cout << "Erreur lors du retrait de la Forme";
    cout << "Après : " << endl;
    cout << couche;

}

void Tests::tests_unitaires_canevas()
{
    cout << "Test Unitaire Canevas" << endl;
    Canevas canevas;

    //! ============================================================================= Test 13
    printHeaderTest(13);
    if(!canevas.activerCouche(7)) cout << "Impossible d'activer la couche!" << endl;


    //! ============================================================================= Test 14
    printHeaderTest(14);
    if(!canevas.activerCouche(1)) cout << "Impossible d'activer la couche!" << endl;
    if(!canevas.retirerForme(0)) cout << "Impossible de retirer la Forme!" << endl;

    //! ============================================================================= Test 15
    printHeaderTest(15);
    if(!canevas.reinitialiser()) cout << "Impossible de reéinitialiser le canevas!" << endl;
    if(!canevas.translater(5, 10)) cout << "Impossible de translater la couche!" << endl;

    cout << endl << endl << endl;

}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
    cout << "Test Validation" << endl;
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
    if(!monDessin.reinitialiser(2)) cout << "Erreur lors de la réinitialisation de la couche 4 ";

    //! ===================================================== Étape 10
    printHeaderTest(10);
    if(!monDessin.reinitialiser(3)) cout << "Erreur lors de la réinitialisation de la couche 4 ";

    //! ===================================================== Étape 11
    printHeaderTest(11);
    if(!monDessin.reinitialiser(4)) cout << "Erreur lors de la réinitialisation de la couche 4 ";

    //! ===================================================== Étape 12
    printHeaderTest(12);
    cout << "Affichage du canevas : " << endl << monDessin << endl;

    //! ===================================================== Étape 13
    printHeaderTest(13);
    cout << "Aire total du Canevas : " << monDessin.aire() << endl;

    //! ===================================================== Étape 14
    printHeaderTest(14);
    if(!monDessin.activerCouche(1)) cout << "Erreur lors de l'activation de la couche 1";
    if(!monDessin.retirerForme(0)) cout << "Erreur lors du retrait de la Forme";

    //! ===================================================== Étape 15
    printHeaderTest(15);
    cout << "Affichage du canevas : " << endl << monDessin << endl;

    //! ===================================================== Étape 16
    printHeaderTest(16);
    cout << "Aire total du Canevas : " << monDessin.aire() << endl;

    //! ===================================================== Étape 17
    printHeaderTest(17);
    if(!monDessin.reinitialiser()) cout << "Erreur lors de la réinitialisation du Canevas";

    //! ===================================================== Étape 18
    printHeaderTest(18);
    cout << "Affichage du canevas : " << endl << monDessin << endl;

    //! ===================================================== Étape 19
    printHeaderTest(19);
    cout << "Aire total du Canevas : " << monDessin.aire() << endl;

}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}


void printHeaderTest(int id)
{
    cout << "===================================" << endl;
    cout << "              TEST " << id << "               " << endl;
    cout << "===================================" << endl;
}
