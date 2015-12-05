#include "recherchePremierDernier.h"

int recherchePremiereOcc(int tab[], unsigned short int taille, int val, bool& trouve, unsigned short int& position)
{
    // VARIABLES
    unsigned short int bInf = 0;
    unsigned short int bSup = taille-1;
    unsigned short int milieu;


    // TRAITEMENTS
    while(true)
    {
        if (bInf > bSup)
        {
            break;
        }

        milieu = (bSup + bInf) / 2;

        if (tab[milieu] == val)
        {
            trouve = true;
            position = milieu;
            break;
        }

        if (tab[milieu] > val)
        {
            bSup = milieu-1;
        }
        else
        {
            bInf = milieu+1;
        }
    }

    return position;
}
