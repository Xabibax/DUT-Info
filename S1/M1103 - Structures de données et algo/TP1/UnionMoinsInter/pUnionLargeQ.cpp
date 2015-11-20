#include "pUnionLargeQ.h"

void pUnionLargeQ(int tabP, int tabQ, unsigned short int taille, int tabR)
{


    for (int i=0; i<taille; i++)
    {
        tabR[i] = tabP[i];
    }

    for (int i=0; i<taille; i++)
    {
        tabR[i+taille] = tabQ[i];
    }
}
