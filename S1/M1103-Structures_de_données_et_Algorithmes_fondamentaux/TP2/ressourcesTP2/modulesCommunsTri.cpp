#include<iostream>
#include "ModulesCommunsTri.h"
using namespace std;

void afficherTableauEntiers  (const int tab[],
                              unsigned int nbTab)
{
    cout << "{";
    for (unsigned int i = 0; i<nbTab-1; i++)
    {
        cout << tab[i] << ", " ;

    };
    cout << tab[nbTab-1] << "} "<< endl;
}

void echanger (int &a, int &b)
{
    // à vous de faire
}

