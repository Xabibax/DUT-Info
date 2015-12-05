/*
 Programme : NombrePremiers
 But : Déterminer et afficher les nombres premiers d'un tableau de taille prédéfini à l'aide des procédures.
 Date de création : 29/10/15
 Date de dernière modification : 10/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>
#include <cmath>

using namespace std;

// Déclaration des sous-programmes
void determinerPremiers(unsigned int tableau[], unsigned short int tailleTab, bool premier[]);
// But : Déterminer les nombres premiers contenus dans tableau

int main()
{
    // VARIABLE
    unsigned int tailleTab; // La taille du tableau


    // TRAITEMENT

    // (clavier) >> SaisirTailleTab >> tailleTab
    cout << "Saisissez la taille du tableau : ";
    cin >> tailleTab;

    unsigned int tableau[tailleTab]; // Création du tableau d'entier
    bool premier[tailleTab]; // Création du tableau boléen

    // tableau, tailleTab >> InitialiserTableau >> tableau
    // premier, tailleTab >> InitialiserPremier >> premier
    for (int i=0; i<tailleTab; i++)
    {
        tableau[i] = i+1;
        premier[i] = false;
    }

    // Appel de la procédure determinerPremiers
    determinerPremiers(tableau, tailleTab, premier);

    // tailleTab >> AfficherIntervalle >> (écran)
    cout << "Liste des nombres premiers entre 2 et " << tailleTab << " :" << endl;

    // premier, tailleTab, tableau >> AfficherTableau >> (écran)
    for (int i=0; i < tailleTab; i++)
    {
        if (premier[i])
        {
            cout << tableau[i] << endl;
        }
    }

    return 0;
}

// Définition des sous-programmes
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
