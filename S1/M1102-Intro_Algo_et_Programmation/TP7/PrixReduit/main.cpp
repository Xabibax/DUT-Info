/*
 Programme : PrixReduit
 But : Calculer et afficher un prix reduit en fonction du prix initial et d'une réduction
       saisis par l'utilisateur à l'aide des procédures.
 Date de création : 29/10/15
 Date de dernière modification : 08/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

// Déclaration des sous-programmes
void calculerPrixReduit(double prixInit, unsigned short int reduc, double prixFinal);
// But : calculer un prix final en fonction d'un prix initial et d'une réduction

int main()
{
    // VARIABLES
    double prixInitial; // Le prix de départ saisi par l'utilisateur
    unsigned short int reduction; // La réduction saisi par l'utilisateur et qui sera appliquée à prixInitial
    double prixFinal; // Le prix final calculé


    // TRAITEMENT

    // (clavier) >> SaisirPrixInitial >> prixInitial
    cout << "Saisissez le prix initial : ";
    cin >> prixInitial;

    // (clavier) >> SaisirReduction >> reduction
    cout << "Saisissez la reduction : ";
    cin >> reduction;

    // Appel de la procédure calculerPrixReduit
    calculerPrixReduit(prixInitial, reduction, prixFinal);

    // prixFinal >> AfficherPrixFinal >> (écran)
    cout << "Prix final : " << prixFinal << endl;

    return 0;
}

// Définition des sous-programmes
void calculerPrixReduit(double prixInit, unsigned short int reduc, double prixFinal)
{
    // prixInit, reduc >> calculerPrixReduit >> prixFinal
    prixFinal = prixInit - (prixInit*reduc)/100;
}
