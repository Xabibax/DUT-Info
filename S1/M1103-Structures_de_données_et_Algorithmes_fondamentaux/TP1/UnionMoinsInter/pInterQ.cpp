#include "pInterQ.h"

void pInterQ(int tabP, int tabQ, unsigned short int taille, int tabR)
{
    for (int i=0; i<taille; i++)
    {
        if (tabP[i] == tabQ[i])
        {
            tabR[i] = tabP[i];
        }
    }
}
