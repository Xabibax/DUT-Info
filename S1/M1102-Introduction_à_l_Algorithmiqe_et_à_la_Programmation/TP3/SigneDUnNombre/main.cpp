/*
 Programme : SigneDUnNombre
 But :  Détermine le signe d'un nombre saisi par l'utilisateur.
 Date de création : 24/09/15
 Date de dernière modification : 28/10/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLE
    double nombre; // Le nombre dont on va déterminer le signe.
    string signe; // Le signe du nombre saisi par l'utilisateur


    // TRAITEMENT

    // (clavier) > SaisirNombre > nombre
    cout << "Saisissez un nombre : ";
    cin >> nombre;

    // nombre > DeterminerSigne > signe
    if (nombre < 0)
    {
        signe = "-";
    }
    else
    {
        if (nombre > 0)
        {
            signe = "+";
        }
        else
        {
            signe = "nul";
        }
    }

    // signe > AfficherSigne > (ecran)
    cout << "Signe : " << signe << endl;

    return 0;
}
