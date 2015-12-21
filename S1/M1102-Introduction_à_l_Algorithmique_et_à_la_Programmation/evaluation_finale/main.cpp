/*
 Programme : Exercice A
 But : Déterminer et affiche le nombre de valeurs d'un tableau inférieurs à 10
       et afficher la position du premier zéro de ce même tableau, s'il existe
 Date de dernière modification : 18/11/15
 Auteur : GRAGLIA Valentin
 Groupe de TD : 3
 Groupe de TP : 5
 Remarques : Modèles utilisés : Parcours complet avec traitement conditionné
                                Recherche de première occurrence
*/

#include <iostream>
using namespace std;

// Déclarations des sou-programmes// position >> AffichePosition >> (écran)
int nbValeursSousSeuil(unsigned short int tableau[], const unsigned short int tailleTab, unsigned short int seuil);
// But : déterminer le nombre de valeurs contenues dans tableau et qui sont inférieurs à 10;

void rechercheVal(unsigned short int tableau[], unsigned short int tailleTab, short int valeurARechercher, bool& trouve, unsigned short int& position);
// But : détemriner la position du premier zéro contenu dans tableau s'il existe

int main (void)
{
    // VARIABLES
    const unsigned short int NBCASES = 10; // La taille du tableau de note
    unsigned short int tabNotes[NBCASES] = {3, 0, 9, 15.5, 13, 4, 12.5, 11, 10.5, 14}; // Initialisation du tableau de note

    unsigned short int seuil = 10; // Le seuil utilisé pour la fonction nbValeursSousSeuil

    short int valeurARechercher = 0; // La valeur à rechercher dans la procédure rechercheVal
    bool trouve = false; // Initialisation de la recherche
    unsigned short int position = 0; // Initialisation de la position de la valeur à rechercher


    // TRAITEMENTS
    // tabNotes, NBCASES, seuil >> DeteminerNbValeursSousSeuil >> (écran)
    cout << "Il y a " << nbValeursSousSeuil(tabNotes, NBCASES, seuil) << " notes inferieures a 10." << endl;

    // tabNotes, NBCASES, valeurARechercher, trouve, position >> RechercherPositionValeurARechercher >> position, trouve
    rechercheVal(tabNotes, NBCASES, valeurARechercher, trouve, position);

    // position >> AffichePosition >> (écran)
    if(trouve)
    {
        cout << "Il y a un zero en position " << position+1 << endl;
        // On afiche position+1 afin de savoir que l'on se situe dans la i+1 ième cellule du tableau (pour éviter i=0)
    }
    else
    {
        cout << "Il n'y a aucune note egale a zero." << endl;
    }

    return 0;
}

int nbValeursSousSeuil(unsigned short int tableau[], const unsigned short int tailleTab, unsigned short int seuil)
{
    unsigned short int compteur = 0; // Initialisation du compteur de valeurs sous le seuil

    // Parcours complet avec traitement conditionné
    for (int i=0; i<tailleTab; i++)
    {
        if (tableau[i] < seuil)
        {
            compteur++;
        }
    }

    return compteur;
}

void rechercheVal(unsigned short int tableau[], unsigned short int tailleTab, short int valeurARechercher, bool& trouve, unsigned short int& position)
{
    // Recherche de première occurrence
    while(true)
    {
        if (position == tailleTab)
        {
            break; // Si on est à la fin du tableau, on sort
        }
        else
        {
            if (tableau[position] == valeurARechercher)
            {
                trouve = true; // On a trouve une valeur qui respecte valeurARechercher
                break; // On sort de la boucle
            }
            else
            {
                position++; // Dans tous les autres cas, on incrémente la position
            }
        }
    }
}
