#include <iostream>
#include "moduleCommunsTri.h"

using namespace std;

int main()
{
    const unsigned int TAILLE = 10 ;
    int monTab [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié
    int monTab2 [TAILLE] = {8, -5, 7, 10, 1, -4, 5, 9, 0, 2}; // non trié
    /*
    int monTab [TAILLE] = {-6, -3, 0, 2, 2, 6, 7, 8, 9, 10}; déjà trié croissant
    int monTab [TAILLE] = {10, 9, 8, 7, 6, 2, 2, 0, -3, -6}; trié à l’envers
    */


    // Tri Par Bulle de 1 elements
    cout << "TRI par Bulle de 1 element" << endl << endl;
    cout << "AVANT, monTab = " ;
    afficheTableauEntiers(monTab, TAILLE);
    cout << endl;
    triUnElement(monTab, TAILLE);// appel de la procedure triUnElement
    cout<< endl;
    cout << "APRES, monTab = " ;
    afficheTableauEntiers(monTab, TAILLE);
    cout << endl;

    // Tri Par Bulle
    cout << "TRI par Bulle" << endl << endl;
    cout << "AVANT, monTab = " ;
    afficheTableauEntiers(monTab, TAILLE);
    cout << endl;
    triParBulle(monTab, TAILLE);// appel de la procedure triParBulle
    cout<< endl;
    cout << "APRES, monTab = " ;
    afficheTableauEntiers(monTab, TAILLE);
    cout << endl;

    // Tri par selection de place 1 element
    cout << "TRI par selection de place 1 element" << endl << endl;
    cout << "AVANT, monTab2 = " ;
    afficheTableauEntiers(monTab2, TAILLE);
    cout << endl;
    triSelectUnElement(monTab2, TAILLE);
    cout<< endl;
    cout << "APRES, monTab2 = " ;
    afficheTableauEntiers(monTab2, TAILLE);
    cout << endl;

    // Tri par selection de place Tout element
    cout << "TRI par selection de place Tout element" << endl << endl;
    cout << "AVANT, monTab2 = " ;
    afficheTableauEntiers(monTab2, TAILLE);
    cout << endl;
    triSelect(monTab2, TAILLE);
    cout<< endl;
    cout << "APRES, monTab2 = " ;
    afficheTableauEntiers(monTab2, TAILLE);
    cout << endl;

    return 0;
}
