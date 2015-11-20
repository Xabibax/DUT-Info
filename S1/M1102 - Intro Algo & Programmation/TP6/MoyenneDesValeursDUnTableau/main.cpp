/*
 Programme : MoyenneDesValeursDUnTableau
 But : Calculer et afficher la moyenne des valeurs d'un tableau d'entiers saisis par l'utilisateur
 Date de création : 21/10/15
 Date de dernière modification : 10/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLE
    unsigned int tailleTab; // La taille du tableau saisie par l'utilisateur


    // TRAITEMENT

    // (clavier) >> SaisirTailleTab >> tailleTab
    cout << "Saisir la taille du tableau : ";
    cin >> tailleTab;

    int tableau[tailleTab]; // Création du tableau de taille tailleTab

    // tableau, tailleTab >> SaisirValeur >> tableau
    for (int i=0; i<=tailleTab-1; i++)
    {
        cout << "Saisissez la valeur de t[" << i << "] : ";
        cin >> tableau[i];
    }

    double somme = 0; // Initalisation de somme
    double moyenne; // La variable contenant la moyenne calculée des valeurs du tableau

    // tableau, tailleTab, somme >> CalculerSomme >> somme
    for (i=0; i<=tailleTab-1; i++)
    {
        somme = somme + tableau[i];
    }

    // somme, tailleTab >> CalculerMoyenne >> moyenne
    moyenne = somme / tailleTab;

    // moyenne >> Afficher Moyenne >> (écran)
    cout << endl << "Moyenne = " << moyenne << endl;

    return 0;
}
