/*
 Programme : ConversionEnSecondes
 But :  Calcule et affiche le nombre de seconde compris dans l'heure saisie par l'utilisateur.
 Date de création : 16/09/15
 Date de dernière modification : 28/10/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    unsigned short int heures; // Le nombre d'heures saisies par l'utilisateur
    unsigned short int minutes; // Le nombre de minutes saisies par l'utilisateur
    unsigned int secondes; // Le nombre de secondes totales
    const unsigned short int CONVERSIONHEURESSECONDES = 3600; // Le nombre de secondes dans 1 heure
    const unsigned short int CONVERSIONMINUTESSECONDES = 60; // Le nombre de secondes dans 1 minute


    // TRAITEMENT

    // (clavier) >> SaisirHeures >> heures
    cout << "Saisir le nombre d'heures : ";
    cin >> heures;

    // (clavier) >> SaisirMinutes >> minutes
    cout << "Saisir le nombre de minutes : ";
    cin >> minutes;

    // heures, minutes, CONVERSIONHEURESENSECONDES, CONVERSIONMINUTESENSECONDES >> CalculerSecondes
    secondes = heures * CONVERSIONHEURESSECONDES + minutes * CONVERSIONMINUTESSECONDES;

    // secondes >> AfficherSecondes >> (ecran)
    cout << "Secondes : " << secondes << endl;

    return 0;
}
