/*
 Programme : SaisirUnTableau
 But :  Saisir la taille d'un tableau et remplir chaque cellule.
 Date de création : 21/10/15
 Date de dernière modification : 10/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLE
    unsigned int tailleTab; // La taille du tableau saisie par l'utilisateur


    // TRAITEMENT

    // (clavier) >> SaisirTailleTab >> tailleTab
    cout << "Saisir la taille du tableau : ";
    cin >> tailleTab;

    int tableau[tailleTab]; // Création du tableau de taille tailleTab

    // tableau, tailleTab >> SaisirValeur >> tableau
    for (int i=0; i<=tailleTab-1; i++)
    {
        cout << "Saisissez la valeur de t[" << i << "] : ";
        cin >> tableau[i];
    }

    return 0;
}
