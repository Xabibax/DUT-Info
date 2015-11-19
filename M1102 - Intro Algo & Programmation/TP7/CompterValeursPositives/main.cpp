/*
 Programme : CompterValeursPositives
 But : Déterminer et afficher le nombre de valeurs positives d'un tableau prédéfini.
 Date de création : 29/10/15
 Date de dernière modification : 10/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

// Déclaration des sous-programmes
void compterValeursPositives(const int tab[], unsigned short int TAILLETAB, int& compteur);
// But : compter le nombre de valeurs positives de tab

int main()
{
    // VARIABLES
    const unsigned short int TAILLETAB = 5; // La taille du tableau
    int tableau[TAILLETAB] = {13, -9, 15, -13, 5}; // Initialisation du tableau

    int compteur = 0; // Initialisation du compteur


    // TRAITEMENT

    // Appel de la procédure compterValeursPositives
    compterValeursPositives(tableau, TAILLETAB, compteur);

    // compteur >> AfficherCompteur >> (écran)
    cout << endl << "Il y a " << compteur << " valeur(s) positive(s)." << endl;

    return 0;
}

// Définition des sous-programmes
void compterValeursPositives(const int tab[], unsigned short int TAILLETAB, int& compteur)
{
    // tableau, TAILLETAB, compteur >> CalculerCompteur >> compteur
    for (int i=0; i < TAILLETAB; i++)
    {
        if (tab[i] > 0)
        {
            compteur++;
        }
    }
}
