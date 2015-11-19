/*
  Programme : ValeurAbsolue
  But : Afficher la valeur absolue d'un nombre saisi par l'utilisateur.
  Date de création : 04/11/15
  Date de dernière modification : 05/11/15
  Auteur : Valentin GRAGLIA
  Dernière compilation : Linux
*/
#include <iostream>

using namespace std;

// Déclaration des sous-programmes
double valeurAbsolue(double nombre);
// But : Calculer la valeur absolue de nombre

int main()
{
    // VARIABLE
    double nombreASaisir; // Le nombre saisi par l'utilisateur


    // TRAITEMENT

    // (clavier) >> SaisirNombre >> nombreASaisir
    cout << "Saisissez un nombre : ";
    cin >> nombreASaisir;

    // nombreASaisir >> AfficherValeurAbsolue >> (écran)
    cout << "La valeur absolue de " << nombreASaisir << " est : " << valeurAbsolue(nombreASaisir) << endl;

    return 0;
}

// Définition des sous-programmes
double valeurAbsolue(double nombre)
{
    return nombre >= 0 ? nombre : -nombre;
}
