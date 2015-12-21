/*
 Programme : MaxDeTroisNombres
 But :  Détermine et affiche le maximum entre trois nombres saisis par l'utilisateur.
 Date de création : 24/09/15
 Date de dernière modification : 27/10/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    double nombre1; // Le premier nombre
    double nombre2; // Le second nombre
    double nombre3; // Le troisième nombre
    double maximum; // Le maximum entre nombre1, nombre2 et nombre3
    bool egal= false; // La variable utilisée si nombre1 = nombre2 = nombre3


    // TRAITEMENT

    // (clavier) > SaisirNombre1 > nombre1e
    cout << "Saisissez un premier nombre : ";
    cin >> nombre1;

    // (clavier) > SaisirNombre2 > nombre2
    cout << "Saisissez un second nombre : ";
    cin >> nombre2;

    // (clavier) > SaisirNombre3 > nombre3
    cout << "Saisissez un troisieme nombre : ";
    cin >> nombre3;

    // nombre1, nombre2, nombre3 > DeterminerMaximum > maximum, egal
    if (nombre1 < nombre2)
    {
        if (nombre3 < nombre2)
        {
            maximum = nombre2;
        }
        else
        {
            if (nombre2 < nombre3)
            {
                maximum = nombre3;
            }
            else
            {
                maximum = nombre3;
            }
        }
    }
    else
    {
        if (nombre2 < nombre1)
        {
            if (nombre3 < nombre1)
            {
                maximum = nombre1;
            }
            else
            {
                if (nombre1 < nombre3)
                {
                    maximum = nombre3;
                }
                else
                {
                    maximum = nombre3;
                }
            }
        }
        else
        {
            if (nombre3 < nombre1)
            {
                maximum = nombre1;
            }
            else
            {
                if (nombre1 < nombre3)
                {
                    maximum = nombre3;
                }
                else
                {
                    egal = true;
                }
            }
        }
    }

    // egal, maximum > AfficherResultat > (écran)
    if (egal)
    {
        cout << "Les trois nombres sont egaux." << endl;
    }
    else
    {
        cout << "Le maximum est " << maximum << endl;
    }

    return 0;
}
