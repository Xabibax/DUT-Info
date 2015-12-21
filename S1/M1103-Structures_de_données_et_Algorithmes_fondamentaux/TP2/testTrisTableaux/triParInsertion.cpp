#include "triParInsertion.h"

void triParInsertion(int tab[], unsigned short int nbCases)
{
    for(int i=1; i<nbCases; i++)
    {
        while(tab[i] < tab[i-1])
        {
            echanger(tab[i], tab[i-1]);
        }
    }
}
