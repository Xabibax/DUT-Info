/*
 Programme : SaisieEtVerificationDUneNote
 But :  Demander � l'utilisateur de saisir une note tant que celle-ci n'est pas comprise entre 0 et 20.
 Date de cr�ation : 07/10/15
 Date de derni�re modification : 27/10/15
 Auteur : Valentin GRAGLIA
 Derni�re compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLE
    float note; // La note saisie par l'utilisateur


    // TRAITEMENT

    do
    {
        // (clavier) > SaisirNote > note
        cout << "Saisissez une note : ";
        cin >> note;
    }
    while (!(note >= 0 && note <= 20));

    /*
    OU:
        while (!(note >= 0 && note <= 20))s
        {
            cout << "Saisissez une note : ";
            cin >> note;
        }
    */

    return 0;
}
