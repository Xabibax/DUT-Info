/*
 Programme : InversionTableau
 But : Inverser les valeurs d'un tableau saisi par l'utilisateur.
 Date de création : 21/10/15
 Date de dernière modification : 10/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
	// VARIABLES
    unsigned short int borneFin; // La borne calculée indiquant où l'on doit arrêter d'inverser le tableau
    int iIntermediaire; // La variable intermédiaire pour échanger les deux autres

    unsigned int tailleTab; // La taille du tableau saisie par l'uilisateur


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

	// tailleTab >> DeterminerBorneFin >> borneFin
    if (tailleTab % 2 == 0)
    {
        borneFin = tailleTab / 2;
    }
    else
    {
        borneFin = tailleTab / 2 + 0.5;
    }

	// tableau, borneFin, tailleTab, iIntermediaire >> InverserTableau >> tableau
    for (int i=0; i<=(borneFin-1); i++)
    {
        // On inverse les valeurs à l'aide de la variable intermédiaire
        iIntermediaire = tableau[i];
        tableau[i] = tableau[tailleTab-1-i];
        tableau[tailleTab-1-i] = iIntermediaire;
    }

	// tableau, tailleTab >> AfficherTableau >> (écran)
    for (int i=0; i<=tailleTab-1; i++)
    {
        cout << "t[" << i << "] = " << tableau[i] << endl;
    }

    return 0;
}
