/*
 Programme : ProfitonsDesSoldes
 But :  Calcule et affiche un prix final en fonction du prix initial et de la r�duction associ�e.
 Date de cr�ation : 16/09/15
 Date de derni�re modification : 28/10/15
 Auteur : Valentin GRAGLIA
 Derni�re compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    double prixInitial; // Le prix initial saisi par l'utilisateur
    unsigned short int reduction; // La r�duction saisie par l'utilisateur et appliqu�e au prix initial
    double prixAPayer; // Le prix final correspondant au prix initial d�duit de la r�duction

    // TRAITEMENT

    // (clavier) >> saisirPrixInitial >> prixInitial
    cout << "Saisir le prix initial : ";
    cin >> prixInitial;

    // (clavier) >> saisirReduction >> reduction
    cout << "Saisir reduction : ";
    cin >> reduction;

    // prixInitial, reduction >> CalculerPrixAPayer >> prixAPayer
    prixAPayer = prixInitial * (100 - reduction) / 100;

    // prixAPayer >> AfficherPrixAPayer >> (ecran)
    cout << "Prix a payer : " << prixAPayer << endl;

    return 0;
}
