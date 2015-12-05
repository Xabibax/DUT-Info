/*
 Programme : Exercice A
 But : D�terminer et affiche le nombre de valeurs d'un tableau inf�rieurs � 10
       et afficher la position du premier z�ro de ce m�me tableau, s'il existe
 Date de derni�re modification : 18/11/15
 Auteur : GRAGLIA Valentin
 Groupe de TD : 3
 Groupe de TP : 5
 Remarques : Mod�les utilis�s : Parcours complet avec traitement conditionn�
                                Recherche de premi�re occurrence
*/

#include <iostream>
using namespace std;

// D�clarations des sou-programmes// position >> AffichePosition >> (�cran)
int nbValeursSousSeuil(unsigned short int tableau[], const unsigned short int tailleTab, unsigned short int seuil);
// But : d�terminer le nombre de valeurs contenues dans tableau et qui sont inf�rieurs � 10;

void rechercheVal(unsigned short int tableau[], unsigned short int tailleTab, short int valeurARechercher, bool& trouve, unsigned short int& position);
// But : d�temriner la position du premier z�ro contenu dans tableau s'il existe

int main (void)
{
    // VARIABLES
    const unsigned short int NBCASES = 10; // La taille du tableau de note
    unsigned short int tabNotes[NBCASES] = {3, 0, 9, 15.5, 13, 4, 12.5, 11, 10.5, 14}; // Initialisation du tableau de note

    unsigned short int seuil = 10; // Le seuil utilis� pour la fonction nbValeursSousSeuil

    short int valeurARechercher = 0; // La valeur � rechercher dans la proc�dure rechercheVal
    bool trouve = false; // Initialisation de la recherche
    unsigned short int position = 0; // Initialisation de la position de la valeur � rechercher


    // TRAITEMENTS
    // tabNotes, NBCASES, seuil >> DeteminerNbValeursSousSeuil >> (�cran)
    cout << "Il y a " << nbValeursSousSeuil(tabNotes, NBCASES, seuil) << " notes inferieures a 10." << endl;

    // tabNotes, NBCASES, valeurARechercher, trouve, position >> RechercherPositionValeurARechercher >> position, trouve
    rechercheVal(tabNotes, NBCASES, valeurARechercher, trouve, position);

    // position >> AffichePosition >> (�cran)
    if(trouve)
    {
        cout << "Il y a un zero en position " << position+1 << endl;
        // On afiche position+1 afin de savoir que l'on se situe dans la i+1 i�me cellule du tableau (pour �viter i=0)
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

    // Parcours complet avec traitement conditionn�
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
    // Recherche de premi�re occurrence
    while(true)
    {
        if (position == tailleTab)
        {
            break; // Si on est � la fin du tableau, on sort
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
                position++; // Dans tous les autres cas, on incr�mente la position
            }
        }
    }
}
