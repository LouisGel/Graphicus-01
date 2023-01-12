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
    cout << "TEST  -   Constructeur sans paramètre : " << endl;
    Rectangle* p_rectangle = new Rectangle;
    Carre* p_carre = new Carre;
    Cercle* p_cercle = new Cercle;

    delete p_rectangle;
    delete p_carre;
    delete p_cercle;


    cout << "TEST  -   Constructeur avec paramètres : " << endl;
    p_rectangle = new Rectangle(1,2, {1,1});
    p_carre = new Carre(3, {1,1});
    p_cercle = new Cercle(4, {1,1});

    cout << "TEST  -   Constructeur copieur : " << endl;
    Rectangle rectangle(*p_rectangle);
    Carre carre(*p_carre);
    Cercle cercle(*p_cercle);

    cout << "TEST  -   Affichage en utilisant la méthode afficher(ostream&) de la Formes sur un pointeur : ";
    p_rectangle->afficher(cout);
    cout << "TEST  -   Affichage en utilisant la surcharge de l'opérateur << de la Formes sur un pointeur : ";
    cout << *(p_carre);
    cout << "TEST  -   Affichage en utilisant la méthode afficher(ostream&) de la Formes : ";
    cout << cercle;

}

void Tests::tests_unitaires_vecteur()
{
    Vecteur<Forme> vec(1);

    cout << "TEST  -   Ajout d'une forme dans le Vecteur avec une capacity non égale à 0 : ";
    if(vec.pushBack(new Rectangle(2,5))) cout << "OK!" << endl;
    cout << "TEST  -   Ajout d'une forme dans le Vecteur contenant déjà une forme : ";
    if(vec.pushBack(new Carre(2))) cout << "OK!" << endl;
    cout << "TEST  -   Ajout d'une forme dans le Vecteur qui devra se redimensionner : ";
    if(vec.pushBack(new Cercle(2))) cout << "OK!" << endl;

    cout << "TEST  -   Affichage des éléments dans le Vecteur et..." << endl;
    cout << "Accès grâce aux [index] en utilisant la méthode afficher(ostream&) de la Forme : ";
    if(vec[0] != nullptr) vec[0]->afficher(cout);
    cout << "Accès grâce à la méthode at(index) en utilisant la méthode afficher(ostream&) de la Forme : ";
    if(vec[1] != nullptr) vec.at(1)->afficher(cout);
    cout << "Accès grâce aux pointeur de [index] sans utiliser la méthode afficher(ostream&) de la Forme : ";
    if(vec[2] != nullptr) cout << *(vec[2]);

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
