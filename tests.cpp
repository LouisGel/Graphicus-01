/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

void Tests::tests_unitaires_formes()
{
    //Constructeur sans paramètre
    cout << "Constructeur sans paramètre" << endl;
    Rectangle* p_rectangle = new Rectangle;
    Carre* p_carre = new Carre;
    Cercle* p_cercle = new Cercle;

    //delete p_rectangle, p_carre, p_cercle;


    Vecteur<Forme> vec(1);
    if(vec.pushBack(new Rectangle(2,5))) cout << "OK!" << endl;
    if(vec.pushBack(new Carre(2))) cout << "OK!" << endl;
    if(vec.pushBack(new Cercle(2))) cout << "OK!" << endl;


    if(vec[0] != nullptr) cout << *(vec[0]);
    if(vec[1] != nullptr) cout << *(vec[1]);
    if(vec[2] != nullptr) cout << *(vec[2]);
    
   
}

void Tests::tests_unitaires_vecteur()
{
   // Tests sur la classe Vecteur
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
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
   cout << "TESTS APPLICATION (CAS 01)" << endl; 
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
