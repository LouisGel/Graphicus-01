/********
 * Fichier: graphicus-01.cpp
 * Auteurs: Louis-Xavier Gélinas et Émy Grégoire
 * CIP: GELL3101 - GREE1404
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"

using namespace std;

int main()
{
   Tests tests;
   
    tests.tests_unitaires();    // Plan de tests
    tests.tests_application_cas_01();   // Validation

   return 0;
}

