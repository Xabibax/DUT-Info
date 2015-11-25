#include <iostream>
#include "parcoursParallele.h"

using namespace std;

int main()
{
    const unsigned short int NBCASESP = 4;
    const unsigned short int NBCASESQ = 7;

    int tabP[NBCASESP] = {-44, -20, -2, 1};
    int tabQ[NBCASESQ] = {-60, -20, -2, -1, 0, 40, 55};

    parcoursParallele(tabP, NBCASESP, tabQ, NBCASESQ);

    return 0;
}
