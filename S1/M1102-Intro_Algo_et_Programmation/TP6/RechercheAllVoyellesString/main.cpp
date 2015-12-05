/*
 Programme : RechercheAllVoyelleString
 But : Déterminer et afficher toutes les voyelles d'un tableau de caractères saisis par l'utilisateur
 Date de création : 21/10/15
 Date de dernière modification : 11/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    unsigned short int tailleTab; // La taille du tableau saisie par l'utilisateur
    unsigned int compteur = 0; // Initialisation du compteur


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

    cout << endl;

    // tableau, tailleTab, compteur >> RechercherVoyelles >> compteur
    for(int i=0; i<=tailleTab-1; i++)
    {
        if ((tableau[i] == 'a') || (tableau[i] == 'e') || (tableau[i] == 'i') || (tableau[i] == 'o') || (tableau[i] == 'u') || (tableau[i] == 'y'))
        {
            cout << "La " << i+1 << "ieme case est une voyelle." << endl;
            compteur++;
        }
    }

    // compteur >> AfficherCompteur >> (écran)
    cout << compteur << " voyelle(s) trouvee(s)." << endl;

    return 0;
}
