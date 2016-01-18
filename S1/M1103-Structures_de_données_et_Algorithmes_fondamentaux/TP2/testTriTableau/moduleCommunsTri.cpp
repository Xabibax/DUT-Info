#include <iostream>
#include "moduleCommunsTri.h"

using namespace std;

void afficheTableauEntiers (const int tab[], unsigned int nbTab)
{
    cout << "{";

    for (unsigned int i = 0; i<nbTab-1; i++)
    {
        cout << tab[i] << ", " ;
    }

    cout << tab[nbTab-1] << "} "<< endl;
}

void echanger (int& a, int& b) // échange le contenu des 2 paramètres entiers a et b
{
    int c;
    c=a;
    a=b;
    b=c;
}

void triUnElement(int tab[], unsigned int nbCasesNonTrie)
{
    for (int i=0; i<=nbCasesNonTrie-2; i++ )
    {
        if (tab[i]>tab[i+1])
        {
            echanger(tab[i], tab[i+1]);
        }
    }
}

void triParBulle(int tab[], unsigned int nbCasesNonTrie)
{
    for (int i=nbCasesNonTrie-1; i>=1; i--)
    {
        triUnElement(tab,nbCasesNonTrie);
    }
}

unsigned int positionDuMax (int tab[], unsigned int nbCasesNonTrie)
{
    int pos=0;

    for (int i=1; i<=nbCasesNonTrie-1; i++ )
    {
        if (tab[pos]<tab[i])
        {
            pos=i;

        }
    }

    return pos;
}


void triSelectUnElement(int tab[], unsigned int nbCasesNonTrie)
{
    echanger(tab[positionDuMax(tab,nbCasesNonTrie)],tab[nbCasesNonTrie-1]);
}

void triSelect(int tab[], unsigned int nbCasesNonTrie)
{
    for (int i=nbCasesNonTrie-1; i>=0; i--)
    {
        triSelectUnElement(tab,i+1);
    }
}
