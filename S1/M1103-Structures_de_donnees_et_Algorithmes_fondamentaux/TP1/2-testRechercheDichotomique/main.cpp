/*
 Programme : Recherche dichotomique d�une valeur dans un tableau d�entiers strictement/totalement ordonn�
 But : Le programme permet de recherche une valeur dans un tableau.
 Date de derni�re modification : 18/01/2016
 Auteur : Valentin GRAGLIA
 Remarques : Recherche dichotomique de premi�re occurence
*/

#include <iostream>
#include "RechercheDichotomiqueValeur.h"

using namespace std;

int main (void)
{
    // VARIABLES.
    const unsigned short int NBCASES=10;// Le nombre de cases du tableau
    const short int t[NBCASES]={-4, -1, 6, 9, 12, 14, 15, 20, 21, 25};// Un tableau ordonn� d'entiers
    short int valRechercher;// La valeur que l'on recherche
    unsigned short int position;// La position de la valeur trouv�e
    bool trouve;// Prend vrai si la valeur val a �t� trouv�, faux sinon

    // TRAITEMENTS
    // Saisie de la valeur � rechercher
    cout << "Entrez la valeur a rechercher : ";
    cin >> valRechercher;

    // Appel de la proc�dure recherchePremiereOcc
    recherchePremiereOcc(t, NBCASES, valRechercher, position, trouve);

    // V�rifier si on a trouv� la valeur valRechercher que l'on recherche
    if (trouve)
    {
        cout << "la valeur a ete trouvee a la position " << position+1 << ".";
    }
    else
    {
        cout << "La valeur n'a pas ete trouvee.";
    }
    return 0;
}
