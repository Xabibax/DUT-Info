/*
 Programme : DetectionDePalindromes
 But : Déterminer si un mot saisi par l'utilisateur et stocké dans un tableau est un palindrome ou pas
 Date de création : 21/10/15
 Date de dernière modification : 11/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLE
    unsigned int tailleTab; // La taille du tableau saisie par l'utilisateur
    unsigned int borneFin; // La borne d'arrêt de la recherche
    bool palindrome = false; // Si vrai alors c'est un palindrome


    // TRAITEMENT

    // (clavier) >> SaisirTailleTab >> tailleTab
    cout << "Saisir la taille du tableau : ";
    cin >> tailleTab;

    char tableau[tailleTab]; // Création du tableau de taille tailleTab

    // tableau, tailleTab >> SaisirValeur >> tableau
    for (int i=0; i<=tailleTab-1; i++)
    {
        cout << "Saisissez la valeur de t[" << i << "] : ";
        cin >> tableau[i];
    }

    // tailleTab >> DeterminerBorneFin >> borneFin
    if (tailleTab % 2 == 0)
    {
        borneFin = tailleTab / 2;
    }
    else
    {
        borneFin = tailleTab / 2 + 0.5;
    }

    // tableau, borneFin, tailleTab >> DeterminerPalindrome >> palindrome
    for (int i=0; i<=(borneFin-1); i++)
    {
        if(tableau[i] == tableau[tailleTab -1 -i])
        {
            palindrome = true;
        }
        else
        {
            palindrome = false;
            break;
        }
    }

    // palindrome >> AfficherPalindrome >> (écran)
    if (palindrome)
    {
        cout << endl << "Le mot saisi est un palindrome." << endl;
    }
    else
    {
        cout << endl << "Le mot saisi n'est pas un palindrome." << endl;
    }

    return 0;
}
