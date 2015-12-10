/*
 Programme : SaisieEtVerificationDUneNoteAvecMessageDErreur
 But :  Demander � l'utilisateur de saisir une note et afficher un message d'erreur tant que cele-ci n'est pas comprise entre 0 et 20.
 Date de cr�ation : 07/10/15
 Date de derni�re modification : 28/10/15
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
    while(true)
    {
        // (clavier) > SaisirNote > note
        cout << "Saisissez une note : ";
        cin >> note;

        if (note >= 0 && note <= 20)
        {
            break;
        }

        // AfficherErreur > (�cran)
        cout << "Erreur: la note saisie n'est pas comprise entre 0 et 20." << endl;
    }

    return 0;
}
