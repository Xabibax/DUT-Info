/*
 Programme : ProblemeToursRoue
 But :  Calcule et affiche le nombre de tours de roue à faire en fonction de la distance et du rayon saisient par l'utilisateur.
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
    double distance; // La distance à parcourir saisie par l'utilisateur
    double rayon; // Le rayon de la roue saisie par l'utilisateur
    double tours; // Le nombre de tours de roue calculée nécessaire pour parcourir la distance en fonction du rayon
    const float PI = 3.14; // La valeur approchée de la constante pi

    // TRAITEMENT

    // (clavier) >> SaisirDistance >> distance
    cout << "Saisir la distance (km) : ";
    cin >> distance;

    // (clavier) >> SaisirRayon >> rayon
    cout << "Saisir le rayon (mm) : ";
    cin >> rayon;

    // distance, PI, rayon >> CalculerTours >> tours
    tours = (distance * 1000) / (2 * PI * rayon * 0.01);

    // tours >> AfficherTours >> (ecran)
    cout << "Nombres de tours a parcourir : " << tours << endl;

    return 0;
}
