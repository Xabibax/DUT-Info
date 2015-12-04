#include "parcoursParallele.h"
#include <iostream>

using namespace std;

void parcoursParallele(int tabP[], unsigned short int nbCasesP, int tabQ[], unsigned short int nbCasesQ)
{
    int iP = 0;
    int iQ = 0;

    while(!((iP == nbCasesP) && (iQ == nbCasesQ)))
    {
        if((iP > nbCasesP) && (iQ <= nbCasesQ-1))
        {
            cout << tabQ[iQ] << endl;
            iQ++;
        }
        else
        {
            if((iP <= nbCasesP-1) && (iQ > nbCasesQ))
            {
                cout << tabP[iP] << endl;
                iP++;
            }
            else
            {
                if(tabP[iP] < tabQ[iQ])
                {
                    cout << tabP[iP] << endl;
                    iP++;
                }
                else
                {
                    if(tabP[iP] == tabQ[iQ])
                    {
                        cout << tabP[iP] << endl;
                        cout << tabQ[iQ] << endl;
                        iP++;
                        iQ++;
                    }
                    else
                    {
                        cout << tabQ[iQ] << endl;
                        iQ++;
                    }
                }
            }
        }
    }
}
