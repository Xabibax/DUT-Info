/*
 Programme : ConversionEurosVersDollars
 But :  Calcule l'aire d'un cercle suivant le rayon saisi par l'utilisateur
 Date de création : 10/09/15
 Date de dernière modification : 28/10/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    const float pi = 3.14; // La valeur arrondie de pi
    double rayon; // Le rayon saisi par l'utilisateur
    double aire; // L'aire calculée avec pi et rayon

    // (clavier) > SaisirRayon > rayon
    cout << "Entrez la valeur du rayon [cm] : ";
    cin >> rayon;

    // pi, rayon > CalculerAire > aire
    aire = pi * rayon * rayon;

    // aire > AfficherAire > (ecran)
    cout << "Pour un cercle de " << rayon << " cm, l'aire est egale a " << aire << " cm." << endl;

    return 0;
}
