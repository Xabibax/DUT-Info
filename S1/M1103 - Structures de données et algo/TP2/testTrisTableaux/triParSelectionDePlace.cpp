#include "triParSelectionDePlace.h"
#include "echanger.h"

#include <iostream>
using namespace std;

void triParSelectionDePlace(int tab[], unsigned short int nbCases)
{
    int position = nbCases-1;
    int maximum = tab[0];
    int save;
    int positionMaximum;

    while(!(position == 0))
    {
        maximum = tab[0];

        // Déterminer maximum*/
        for(int i=0; i<position; i++)
        {
            if(maximum < tab[i])
            {
                maximum = tab[i];
                positionMaximum = i;
            }
        }

        save = tab[position];
        tab[position] = maximum;
        tab[positionMaximum] = save;

        position--;
   }
}
