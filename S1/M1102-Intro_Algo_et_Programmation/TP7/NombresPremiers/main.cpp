/*
 Programme : NombrePremiers
 But : D�terminer et afficher les nombres premiers d'un tableau de taille pr�d�fini � l'aide des proc�dures.
 Date de cr�ation : 29/10/15
 Date de derni�re modification : 10/11/15
 Auteur : Valentin GRAGLIA
 Derni�re compilation : Linux
*/

#include <iostream>
#include <cmath>

using namespace std;

// D�claration des sous-programmes
void determinerPremiers(unsigned int tableau[], unsigned short int tailleTab, bool premier[]);
// But : D�terminer les nombres premiers contenus dans tableau

int main()
{
    // VARIABLE
    unsigned int tailleTab; // La taille du tableau


    // TRAITEMENT

    // (clavier) >> SaisirTailleTab >> tailleTab
    cout << "Saisissez la taille du tableau : ";
    cin >> tailleTab;

    unsigned int tableau[tailleTab]; // Cr�ation du tableau d'entier
    bool premier[tailleTab]; // Cr�ation du tableau bol�en

    // tableau, tailleTab >> InitialiserTableau >> tableau
    // premier, tailleTab >> InitialiserPremier >> premier
    for (int i=0; i<tailleTab; i++)
    {
        tableau[i] = i+1;
        premier[i] = false;
    }

    // Appel de la proc�dure determinerPremiers
    determinerPremiers(tableau, tailleTab, premier);

    // tailleTab >> AfficherIntervalle >> (�cran)
    cout << "Liste des nombres premiers entre 2 et " << tailleTab << " :" << endl;

    // premier, tailleTab, tableau >> AfficherTableau >> (�cran)
    for (int i=0; i < tailleTab; i++)
    {
        if (premier[i])
        {
            cout << tableau[i] << endl;
        }
    }

    return 0;
}

// D�finition des sous-programmes
void determinerPremiers(unsigned int tableau[], unsigned short int tailleTab, bool premier[])
{
    // On parcourt tout le tableau pour chercher les nombres premiers
    for (int i=0; i<tailleTab; i++)
    {
        // stocker 'true' dans la 2nde cellule
        if (tableau[i] == 2)
        {
            premier[i] = true;
        }
        else
        {
            if (tableau[i] % 2 == 0)
            {
                premier[i] = false; // si le nombre est pair, il n'est pas premier
            }
            else
            {
                // tableau >> ChercherPremier >> premier
                for (int d=2; d<tableau[i]; d++)
                {
                    if (tableau[i] % d == 0)
                    {
                        premier[i] = false;
                        break;
                    }
                    else
                    {
                        premier[i] = true;
                    }
                }
            }
        }
    }
}
