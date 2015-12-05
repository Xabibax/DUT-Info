#include "pUnionStricteQ.h"
#include "pUnionLargeQ.h"

void UnionStricteQ(int tabP, int tabQ, unsigned short int taille, int tabR);
{
        pUnionLargeQ(tabP, tabQ, taille, tabR);
        pMoinsQ(tabP, tabQ, taille, tabR);
}
