/*
 Programme : SommeDesEntiersDe1AN
 But : Calculer et afficher la somme des entiers de 1 à N avec N saisi par l'utilisateur.
 Date de création : 07/10/15
 Date de dernière modification : 28/10/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    unsigned int nombre; // La nombre saisi par l'utilisateur
    unsigned int somme = 0; // La variable contenant la somme progressive des entiers de 1 à N

    // TRAITEMENT

    // (clavier) > SaisirNombre > nombre
    cout << "Saisissez un nombre : ";
    cin >> nombre;

    // somme, nombre, i > CalculerSomme > somme
    for(int i=1; i<=nombre; i++)
    {
        somme = somme + i;
    }

    // somme > AfficherSomme > (écran)
    cout << "La somme des entiers de 1 a " << nombre << " est egale a " << somme  << "." << endl;

    return 0;
}
