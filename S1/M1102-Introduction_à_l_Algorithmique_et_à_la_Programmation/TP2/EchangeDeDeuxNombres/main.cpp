/*
 Programme : EchangeDeDeuxNombres
 But :  Échange deux nombres saisis par l'utilisateur.
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
    int nombre1; // Le premier nombre saisi par l'utilisateur
    int nombre2; // Le second nombre saisi par l'utilisateur
    int nombre3; // La variable intermédiaire pour échanger les deux autres


    // TRAITEMENT

    // (clavier) >> Saisirnb1 >> nombre1
    cout << "Saisir le premier nombre : ";
    cin >> nombre1;

    // (clavier) >> Saisirnb2 >> nombre2
    cout << "Saisir le second nombre : ";
    cin >> nombre2;

    // nombre2, calculernb3 >> nombre3
    nombre3 = nombre2;

    // nombre1, calculernb2 >> nombre2
    nombre2 = nombre1;

    // nombre3, calculernb1 >> nombre1
    nombre1 = nombre3;

    // nombre1 >> Affichernb1 >> (ecran)
    cout << endl << "Premier nombre : " << nombre1 << endl;

    // nombre2 >> Affichernb2 >> (ecran)
    cout << "Second nombre : " << nombre2 << endl;

    return 0;
}
