#include <iostream>
#include "ElaguerDoublons.h"

using namespace std;

int main()
{
    // VARIABLES
    const unsigned short int TAILLE = 10;
    int tabP[TAILLE] = {2, 5, 8, 6, 2, 8, 3 ,7, 2, 10};
    int tabR[TAILLE];

    // TRAITEMENT
    elaguerDoublons(tabP, TAILLE, tabR);

    for (int i=0; i<TAILLE; i++)
    {
        cout << "tabR[" << i << "] = " << tabR[i] << endl;
    }

    return 0;
}
