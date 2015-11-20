/*
 Programme : CompterLesValeursNegativesDUnTableau
 But : Compter et afficher le nombre de valeurs négatives d'un tableau saisi par l'utilisateur
 Date de création : 21/10/15
 Date de dernière modification : 11/11/15
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

    unsigned int compteur = 0; // Initialisation du compteur

    // tableau, tailleTab, compteur >> CalculerCompteur >> compteur
    for (int i=0; i <= tailleTab-1; i++)
    {
        if (tableau[i] < 0)
        {
            compteur++;
        }
    }

    // compteur >> AfficherCompteur >> (écran)
    cout << endl << "Il y a " << compteur << " valeur(s) negative(s)." << endl;

    return 0;
}
