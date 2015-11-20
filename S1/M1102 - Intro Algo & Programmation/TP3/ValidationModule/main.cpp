/*
 Programme : ValidationModule
 But :  Calcule la moyenne d'un module en fonction des notes orales et �crites saisies par l'utilisateur et affiche la validation obtenue.
 Date de cr�ation : 24/09/15
 Date de derni�re modification : 27/10/15
 Auteur : Valentin GRAGLIA
 Derni�re compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    float noteOral; // La note obtenu � l'oral.
    float noteEcrit; // La note obtenu � l'�crit.
    float moyenne; // La moyenne du module.
    bool validation = false; // Module valid� ou non


    // TRAITEMENT

    // (clavier) > SaisirNoteOral > noteOral
    cout << "Saisir la note obtenu a l'oral : ";
    cin >> noteOral;

    // (clavier) > SaisirNoteEcrit > noteEcrit
    cout << "Saisir la note obtenu a l'ecrit : ";
    cin >> noteEcrit;

    // noteEcrit, noteOral > CalculerMoyenne > moyenne
    moyenne = (noteOral + noteEcrit * 2) / 3;

    // D�terminer la validation
    if (moyenne >= 10)
    {
        validation = true;
    }

    // validation > AfficherValidation > (�cran)
    if (validation)
    {
        cout << "Recu" << endl;
    }
    else
    {
        cout << "Non recu" << endl;
    }

    return 0;
}
