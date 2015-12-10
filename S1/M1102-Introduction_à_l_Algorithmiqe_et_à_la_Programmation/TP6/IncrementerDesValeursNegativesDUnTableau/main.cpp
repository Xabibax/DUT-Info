/*
 Programme : IncrementerDesValeursNegativesDUnTableau
 But :  Ajouter 1 à toute les valeurs négatives d'un tableau saisi par l'utilisateur
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

    // tableau, tailleTab >> IncrementerTableau >> tableau
    for (i=0; i<=tailleTab-1; i++)
    {
        if (tableau[i] < 0)
        {
            tableau[i] = tableau[i] + 1;
        }

        // tableau, i >> AfficherTableau >> (écran)
        cout << endl << "t[" << i << "] = " << tableau[i] << endl;
    }

    return 0;
}
