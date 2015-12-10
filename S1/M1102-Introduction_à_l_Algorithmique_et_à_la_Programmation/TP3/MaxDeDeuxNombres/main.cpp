/*
 Programme : MaxDeDeuxNombres
 But :  D�termine et affiche le maximum entre deux nombres saisis par l'utilisateur.
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
    double nombre1; // Le premier nombre
    double nombre2; // Le second nombre
    double maximum; // Le maximum entre nombre1 et nombre2
    bool egal= false; // La variable utilis�e si nombre1=nombre2


    // TRAITEMENT

    // (clavier) > SaisirNombre1 > nombre1
    cout << "Saisissez un premier nombre : ";
    cin >> nombre1;

    // (clavier) > SaisirNombre2 > nombre2
    cout << "Saisissez un second nombre : ";
    cin >> nombre2;

    // nombre1, nombre2 > DeterminerMaximum > maximum, egal
    if (nombre1 < nombre2)
    {
        maximum = nombre2;
    }
    else
    {
        if (nombre2 < nombre1)
        {
            maximum = nombre1;
        }
        else
        {
            egal = true;
        }
    }

    // egal, maximum > AfficherResultat > (�cran)
    if (egal)
    {
        cout << "Les deux nombres sont egaux." << endl;
    }
    else
    {
        cout << "Le maximum est " << maximum << endl;
    }

    return 0;
}
