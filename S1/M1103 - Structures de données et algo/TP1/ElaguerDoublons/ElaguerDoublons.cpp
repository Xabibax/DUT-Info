#include "ElaguerDoublons.h"

void elaguerDoublons(int tabP[], unsigned short int taille, int tabR[])
{
    unsigned short int position = 1;

    tabR[0] = tabP[0];

    for (int i=1; i<taille; i++)
    {
        for (int z=0; z<i; z++)
        {
            if (tabP[z] == tabP[i])
            {
                break;
            }

            tabR[i] = tabP[i];
        }
    }
}
