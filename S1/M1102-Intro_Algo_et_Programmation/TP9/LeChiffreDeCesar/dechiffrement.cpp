#include "dechiffrement.h"

void dechiffrement(char motInitial[], unsigned short int tailleMot, short int cle)
{
    for (int i=0; i<tailleMot; i++)
    {
        if(motInitial[i] >= 'A' && motInitial[i] <= 'Z')
        {
            motInitial[i] = (motInitial[i] - 65 - cle) % 26 + 65;
        }
        else
        {
            if (motInitial[i] >= 'a' && motInitial[i] <= 'z')
            {
                motInitial[i] = (motInitial[i] - 97 - cle) % 26 + 97;
            }
        }
    }
}
