/*
 Programme : AffichageDUnJeuDeMorpion
 But : Afficher une grille de morpion à l'aide d'un tableau prédéfini
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
    const unsigned short int TAILLETAB = 3; // La taille prédéfini du tableau
    char tableau[TAILLETAB][TAILLETAB]; // Création du tableau de caractères


    // TRAITEMENT

    // Initialisation du tableau
    tableau[0][0] = 'x';
    tableau[0][1] = 'o';
    tableau[0][2] = 'o';
    tableau[1][0] = 'o';
    tableau[1][1] = 'x';
    tableau[1][2] = 'o';
    tableau[2][0] = 'o';
    tableau[2][1] = 'o';
    tableau[2][2] = 'x';

    // TAILLETAB, tableau >> AfficherTableau >> (écran)
    for (int x=0; x<=TAILLETAB-1; x++)
    {
        for (int y=0; y<=TAILLETAB-1; y++)
        {
            cout << tableau[x][y];
        }

        cout << endl;
    }

    return 0;
}
