#include "triParSelectionDePlace.h"
#include "echanger.h"

#include <iostream>
using namespace std;

void triParSelectionDePlace(int tab[], unsigned short int nbCases)
{
    unsigned short int posMax = 0;
    unsigned short int ici = nbCases;

    for(unsigned short int ici=nbCases-1; ici>0; ici--)
    {
        posMax = 0;
        posMax = posLePlusGrand(tab, ici, posMax);

        if(posMax == ici)
        {
            ici--;
        }
        else
        {
            echanger(tab[posMax], tab[ici]);
        }
    }
}

unsigned int posLePlusGrand(int tab[], unsigned short int ici, unsigned short int posMax)
{
    for(int i=1; i<=ici; i++)
    {
        if(tab[posMax] < tab[i])
        {
            posMax = i;
        }
    }

    return posMax;
}
