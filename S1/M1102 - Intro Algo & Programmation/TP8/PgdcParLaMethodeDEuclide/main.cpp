/*
  Programme : MoyenneDesValeursDUnTableauDeNombre
  But : Calculer et afficher la moyenne des valeurs d'un tableau de nombres saisis par l'utilisateur
  Date de création : 04/11/15
  Date de dernière modification : 11/11/15
  Auteur : Valentin GRAGLIA
  Dernière compilation : Linux
*/
#include <iostream>

using namespace std;

// Déclaration des sous-programmes
int pgcd(int nombre1, int nombre2);
// But : calculer le PGCD de nombre1 et nombre2

int main()
{
    // VARIABLES
    int nb1, nb2; // Les deux nombres dont on veut connaître le PGCD


    // TRAITEMENT

    // (clavier) >> SaisirNB1 >> nb1
    cout << "Saisissez le premier nombre : ";
    cin >> nb1;

    // (clavier) >> SaisirNB2 >> nb2
    cout << "Saisissez le second nombre : ";
    cin >> nb2;

    // nb1, nb2 >> AfficherPGCD >> (écran)
    cout << endl << "Le PGCD de nb1 et nb2 est egal a " << pgcd(nb1, nb2) << endl;

    return 0;
}

// Définition des sous-pogrammes
int pgcd(int nombre1, int nombre2)
{
    int nombre3 = 0; // Initialisation de la variable intermédiaire

    if(nombre1 == 0 || nombre2 == 0)
    {
        return 0; // PGCD nul
    }
    else
    {
        // Utiliser la valeur absolue
        if(nombre1<0)
        {
            nombre1 = -nombre1;
        }

        if (nombre2<0)
        {
            nombre2 = -nombre2;
        }

        // nombre3, nombre2, nombre1 >> EchangerValeurs >> nombre3, nombre2, nombre1
        do
        {
            nombre3 = nombre2;
            nombre2 = nombre1 % nombre3;
            nombre1 = nombre3;
        }
        while (!(nombre2 == 0));

        return nombre1; // retourner nombre1
    }
}
