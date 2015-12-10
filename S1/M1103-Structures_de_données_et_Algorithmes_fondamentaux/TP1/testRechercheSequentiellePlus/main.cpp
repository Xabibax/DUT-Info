#include <iostream>
#include "recherchePremiereOcc.h"

using namespace std;

int main()
{
    // VARIABLES
    unsigned short int taille = 10;
    int tab[taille];
    tab[0] = 42;
    tab[1] = 35;
    tab[2] = 27;
    tab[3] = 21;
    tab[4] = 19;
    tab[5] = 17;
    tab[6] = 13;
    tab[7] = 9;
    tab[8] = 5;
    tab[9] = 2;

    int val;

    bool trouve = false;
    unsigned short int position = 0;


    // TRAITEMENTS
    cout << "Saisissez la valeur a rechercher : ";
    cin >> val;

    recherchePremiereOcc(tab, taille, val, trouve, position);

    // TODO : affichage
    if (trouve)
    {
        cout << "Valeur trouve sur la cellule n°" << position+1 << endl;
    }
    else
    {
        cout << "Valeur non trouve" << endl;
    }

    return 0;
}
