#include "recherchePremiereOcc.h"

int recherchePremiereOcc(int tab[], unsigned short int taille, int val, bool& trouve, unsigned short int& position)
{
    while(true)
    {
        if (position == taille)
        {
            break;
        }

        if (tab[position] == val)
        {
            trouve = true;
            break;
        }

        position++;
    }

    return position;
}
