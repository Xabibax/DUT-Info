#include <iostream>
#include "recherchePremiereOcc.h"

using namespace std;

int main()
{
    // VARIABLES
    const unsigned short int TAILLE = 10;
    int tab[TAILLE] = {42, 35, 27, 21, 19, 17, 13, 9, 5, 2};

    int val;

    bool trouve = false;
    unsigned short int position = 0;


    // TRAITEMENTS
    cout << "Saisissez la valeur a rechercher : ";
    cin >> val;

    recherchePremiereOcc(tab, TAILLE, val, trouve, position);

    if (trouve)
    {
        cout << "Valeur trouve sur la cellule numero " << position+1 << endl;
    }
    else
    {
        cout << "Valeur non trouve" << endl;
    }

    return 0;
}
