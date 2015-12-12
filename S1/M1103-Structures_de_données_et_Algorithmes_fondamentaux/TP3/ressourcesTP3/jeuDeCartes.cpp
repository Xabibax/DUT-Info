#include <iostream>
using namespace std;
#include "jeuDeCartes.h"
#include "file.h"
#include <stdlib.h>
#include <time.h>

const unsigned int nbCartes = 52;
const UneCarte jeuStandard[nbCartes] =
{
   {as, coeur}, {as, carreau}, {as, trefle}, {as, pique},
   {deux, coeur}, {deux, carreau}, {deux, trefle}, {deux, pique},
   {trois, coeur}, {trois, carreau}, {trois, trefle}, {trois, pique},
   {quatre, coeur}, {quatre, carreau}, {quatre, trefle}, {quatre, pique},
   {cinq, coeur}, {cinq, carreau}, {cinq, trefle}, {cinq, pique},
   {six, coeur}, {six, carreau}, {six, trefle}, {six, pique},
   {sept, coeur}, {sept, carreau}, {sept, trefle}, {sept, pique},
   {huit, coeur}, {huit, carreau}, {huit, trefle}, {huit, pique},
   {neuf, coeur}, {neuf, carreau}, {neuf, trefle}, {neuf, pique},
   {dix, coeur}, {dix, carreau}, {dix, trefle}, {dix, pique},
   {valet, coeur}, {valet, carreau}, {valet, trefle}, {valet, pique},
   {dame, coeur}, {dame, carreau}, {dame, trefle}, {dame, pique},
   {roi, coeur}, {roi, carreau}, {roi, trefle}, {roi, pique}
};
unsigned int jeuMelange[nbCartes]; // une permutation du jeu stabdard
bool pris[nbCartes] ; // indique, pour chaque carte du jeu mélangé, si elle déjà prise ou non
unsigned int prochaineCarte;

void nouveauPaquet (void)
{
   static int lancement = 0;
   unsigned int num ;
   if (lancement == 0)
      {
         srand (time (NULL));
         lancement = 1;
      }
   // aucune carte n' encore été piochée
   for (unsigned int i = 0; i < nbCartes ; i++)
      {
         pris[i] = false;
      }
   // initialisasto du jeu mélange
   for (unsigned int i = 0; i < nbCartes ; i++)
      {
         num = (rand () % nbCartes);
         while (pris[num])
            {
               // chercher un aute numéro
               num = ((num+1) % nbCartes);
            }
         pris[num] = true;
         jeuMelange[i] = num;
      }
   prochaineCarte = 0;
}

UneCarte nouvelleCarte (void)
// sinon jeuEpuise
{
   if (prochaineCarte == 52)
      {
         throw string ("paquetEpuise");
      }
   else
      {
         prochaineCarte = prochaineCarte + 1;
         return (jeuStandard[jeuMelange[prochaineCarte-1]]);
      }
}
// retourne une nouvelle carte piochée dan sle paquet
// génère l'erreur 'paquetVide' si toutes les cartes du paquet ont été piochées.

void afficheCarte (UneCarte c)
{
   // Affiche une carte
   char laCouleur;
   char laValeurBis;
   string laValeur;

   laCouleur = (char) c.couleur;
   if ( (c.valeur >= 1) && (c.valeur <= 9) )
      {
         laValeurBis = (char) (c.valeur + 48);
        cout << laValeurBis << "_" << laCouleur << "  ";
      }
   else
      {
         switch (c.valeur)
            {
            case dix :
               laValeur = "10";
               break;
            case valet :
               laValeur = 'V';
               break;
            case dame :
               laValeur = 'D';
               break;
            case roi :
               laValeur = 'R';
               break;
            default :
               break;
            }
        cout << laValeur << "_" << laCouleur << "  ";
      }
}

