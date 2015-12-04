#include "triDeLaBulle.h"
#include "echanger.h"

#include <iostream>
using namespace std;

void triBulle(int tab[], unsigned short int nbCases)
{
    // VARIABLES
    unsigned short int ici = 0;
    unsigned short int eltCourant;

    // TRAITEMENTS
    for(int i=0; i<=nbCases-1; i++)
    {
        eltCourant = 0;
        ici = 0;

        while(true)
        {
            if(ici==nbCases)
                break;

            if(tab[eltCourant] > tab[eltCourant+1])
            {
                echanger(tab[eltCourant], tab[eltCourant+1]);
            }
            eltCourant++;
            ici++;
        }
    }
}
