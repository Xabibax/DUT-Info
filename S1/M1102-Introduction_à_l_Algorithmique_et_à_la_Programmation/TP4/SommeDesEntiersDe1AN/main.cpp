/*
 Programme : SommeDesEntiersDe1AN
 But : Calculer et afficher la somme des entiers de 1 � N avec N saisi par l'utilisateur.
 Date de cr�ation : 07/10/15
 Date de derni�re modification : 28/10/15
 Auteur : Valentin GRAGLIA
 Derni�re compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    unsigned int nombre; // La nombre saisi par l'utilisateur
    unsigned int somme = 0; // La variable contenant la somme progressive des entiers de 1 � N

    // TRAITEMENT

    // (clavier) > SaisirNombre > nombre
    cout << "Saisissez un nombre : ";
    cin >> nombre;

    // somme, nombre, i > CalculerSomme > somme
    for(int i=1; i<=nombre; i++)
    {
        somme = somme + i;
    }

    // somme > AfficherSomme > (�cran)
    cout << "La somme des entiers de 1 a " << nombre << " est egale a " << somme  << "." << endl;

    return 0;
}
