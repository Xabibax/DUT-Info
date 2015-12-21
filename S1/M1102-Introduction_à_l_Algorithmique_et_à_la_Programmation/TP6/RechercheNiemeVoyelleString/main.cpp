/*
 Programme : RechercheNiemeVoyelleString
 But : Déterminer et afficher la dernière voyelle d'un tableau de caractères saisis par l'utilisateur
 Date de création : 21/10/15
 Date de dernière modification : 10/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    unsigned int tailleTab; // La taille du tableau saisie par l'utilisateur
    unsigned int position; // La variable contenant la position éventuelle de la voyelle
    bool trouve = false; // Variable permettant de savoir si on a trouvé une voyelle ou pas


    // TRAITEMENT

    // (clavier) >> SaisirTailleTab >> tailleTab
    cout << "Saisir la taille du tableau : ";
    cin >> tailleTab;

    char tableau[tailleTab]; // Création du tableau de taille tailleTab

    // tableau, tailleTab >> SaisirValeur >> tableau
    for (int caseASaisir=0; caseASaisir<=tailleTab-1; caseASaisir++)
    {
        cout << "Saisissez la valeur de t[" << caseASaisir << "] : ";
        cin >> tableau[caseASaisir];
    }

    int i = tailleTab; // Initialisation de la recherche

    // Rechercher la dernière voyelle
    while (true)
    {
        if (i == -1)
        {
            break; // On sort de la boucle si on est au début du tableau
        }
        else
        {
            if ((tableau[i] == 'a') || (tableau[i] == 'e') || (tableau[i] == 'i') || (tableau[i] == 'o') || (tableau[i] == 'u') || (tableau[i] == 'y'))
            {
                trouve = true; // On a trouvé une voyelle
                position = i; // On sauvegarde la position de la voyelle
                break; // On sort de la boucle
            }
            else
            {
                i--; // Si on ne trouve pas de voyelle sur une certaine cellule, on passe à la suivante
            }
        }
    }

    // trouve, position >> AfficherPosition >> (écran)
    if (trouve)
    {
        cout << endl << "Position de la premiere voyelle : i=" << position << " (" << i+1 << " ieme case)" << endl;
    }
    else
    {
        cout << endl << "Aucune voyelle trouvee." << endl;
    }

    return 0;
}
