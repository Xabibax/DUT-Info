/*
  Programme : MoyenneDesValeursDUnTableauDeNombre
  But : Calculer et afficher la moyenne des valeurs d'un tableau de nombre saisis par l'utilisateur
  Date de création : 04/11/15
  Date de dernière modification : 10/11/15
  Auteur : Valentin GRAGLIA
  Dernière compilation : Linux
*/
#include <iostream>

using namespace std;

// Déclaration des sous-programmes
double moyenneTableau(const double tab[], unsigned short int tailleTab);
// But : calculer la moyenne de tab

int main()
{
    // VARIABLE
    unsigned short int nbCases; // La taille du tableau


    // TRAITEMENT

    // (clavier) >> SaisirTaille >> nbCases
    cout << "Saisissez la taille du tableau : ";
    cin >> nbCases;
    cout << endl;

    double notes[nbCases]; // Création du tableau

    // notes, nbCases >> SaisirNotes >> notes
    for (int i=0; i<nbCases; i++)
    {
        cout << "Saisissez notes[" << i << "] : ";
        cin >> notes[i];
    }

    // notes, nbCases >> AfficherMoyenne >> (écran)
    cout << endl << "La moyenne du tableau notes est egale a " << moyenneTableau(notes, nbCases) << endl;

    return 0;
}

// Définition des sous-programmes
double moyenneTableau(const double tab[], unsigned short int tailleTab)
{
    double moyenne; // La moyenne des valeurs de tab
    double somme=0; // Initialisation de la somme des valeurs

    // tab, somme >> CalculerSomme >> somme
    for (int i=0; i<tailleTab; i++)
    {
        somme+=tab[i];
    }

    // somme, tailleTab >> CalculerMoyenne >> moyenne
    moyenne = somme / tailleTab;

    return moyenne; // returner la moyenne
}
