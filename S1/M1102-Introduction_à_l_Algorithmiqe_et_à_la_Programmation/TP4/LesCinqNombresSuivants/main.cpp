/*
 Programme : LesCinqNombresSuivants
 But : D�terminer et afficher les cinq nombres suivants en fonction de la saisie de l'utilisateur.
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
    int nombre; // Le nombre saisi par l'utilisateur


    // TRAITEMENT

    // (clavier) > SaisirNombre > nombre
    cout << "Saisissez un nombre : ";
    cin >> nombre;

    // i > AfficherI > (�cran)
    for(int i=nombre+1; i<nombre+6; i++)
    {
        cout << i << endl;
    }

    return 0;
}
