/*
 Programme : RechercheDesDiviseurs
 But :  D�terminer et afficher le nombre de diviseurs d'un nombre saisi par l'utilisateur.
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
    unsigned int nombre; // Le nombre saisi par l'utilisateur et dont on veut d�terminer le nombre de diviseurs
    unsigned int reste = 0; // Le reste de nombre%i
    unsigned int diviseur = 0; // La variable qui compte le nombre de diviseurs


    // TRAITEMENT

    // (clavier) > SaisirNote > nombre
    cout << "Saisissez un nombre : ";
    cin >> nombre;

    for (int i=1; i<=nombre; i++)
    {
        // nombre, i > CalculerReste > reste
        reste = nombre % i;

        if (reste = 0)
        {
            // diviseur > IncrementerDiviseur > diviseur
            diviseur++;
        }
    }

    // nombre, diviseur > AfficherDiviseur > (�cran)
    cout << nombre << " a " << diviseur << " diviseurs." << endl;

    return 0;
}
