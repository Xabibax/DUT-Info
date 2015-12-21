#include "recherchePremierDernier.h"

unsigned short int rechercheDichotomiquePremierDernier(const int tab[], unsigned short int taille, int valeur, bool& trouve, unsigned short int& position)
{
    unsigned short int bInf = 0;
    unsigned short int bSup = taille-1;

    unsigned short int milieu;

    trouve = false;

    while(true)
    {
        if(bInf >= bSup)
            break;

        milieu = (bSup + bInf) / 2;

        if(tab[milieu] == valeur)
        {
            trouve = true;
            position = milieu;
            break;
        }
        else
        {
            if(tab[bInf] == valeur)
            {
                trouve = true;
                position = bInf;
                break;
            }
            else
            {
                if(tab[bSup] == valeur)
                {
                    trouve = true;
                    position = bSup;
                    break;
                }
            }
        }

        if(tab[milieu] > valeur)
            bSup = milieu-1;
        else
            bInf = milieu+1;
    }

    return trouve;
}
