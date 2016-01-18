#include "RechercheDichotomiqueValeur.h"

// Déclaration des sous-programmes
void recherchePremiereOcc (const short int tab[], const unsigned short int TAILLE, short int val, unsigned short int& pos, bool& trouve)
{
    // VARIABLES
    unsigned short int bInf;// La borne supérieure du tableau
    unsigned short int bSup;// La borne supérieure du tableau
    unsigned short int milieu;// Le milieu du tableau

    // TRAITEMENTS
    // Initialiser la recherche
    trouve=false;

    // Initialiser bInf et bSup
    bInf=0;
    bSup=TAILLE-1;


    // Effectuer la recherche
    while (!(bInf>bSup))
    {
        // Calculer le milieu
        milieu=(bSup+bInf)/2;

        // Occurence trouvé ?
        if (tab[milieu]==val)
        {
            trouve=true;
            pos=milieu;
            break;
        }

        // Progresser dans l'espace de recherche
        if (tab[milieu]>val)
        {
            bSup=milieu-1;
        }
        else
        {
            bInf=milieu+1;
        }
    }
}
