#include <iostream>
#include <stdlib.h>

#include "file.h"
#include "jeuDeCartes.h"

using namespace std;

unsigned int pointsCarte (UneCarte c) ;
// retourne le nombre de points apportés par la carte c

void afficherTapis (UneFile& t);
// affiche les cartes du joueur, les plus anciennement arrivées à gauche
// les plus nouvellement rajoutées à droite


int main()
{
    // VARIABLES
    enum UneFinDuJeuDu51 {abandon, gagne, perduPlusDeCartes, perduPlusDe51 };

    UneFinDuJeuDu51 finDePartie; /* indique la manière dont la partie se termine :
                                   - perdu pour cause de paquet épuisé (plus de cartes)
                                   - perdu car le score est > 51 points
                                   - perdu par abandon du joueur
                                   - gagné avec un score = 51 */

    unsigned int score ; // score du joueur
    char choixJoueur ; /* choix de l'action du joueur :  (a/A) abandon de la partie ;
                                                         (g/G) garder la carte de gauche
                                                         (r/R) retirer la carte de gauche */

    UneCarte  carteCourante ;  /* carte courante manipulée par le joueur :
                                    - soit piochée du paquet, et ajoutée à droite du tapis
                                    - soit retirée à gauche du tapis */

    UneFile tapis; // cartes du joueur déposées sur le tapis


    // TRAITEMENTS
    // Initialisation du jeu >> tapis, score (et un nouveau paquet de cartes)
    initialiser(tapis);
    score = 0;
    nouveauPaquet();

    // tapis, score >> Jouer >> finDePartie
    while (true)
    {
        /* tapis, score >> JOUER UN COUP >> finDePartie */


        // piocher une carte >>  carteCourante
        try
        {
            carteCourante = nouvelleCarte();
        }
        catch (string const& chaine)
        {
            finDePartie = perduPlusDeCartes;
            break;
        }

        // poser la carte sur le tapis
        /* à compléter*/


        // carteCourante, score >> mise à jour du score >> score
        /* à compléter*/

        // score, tapis >> afficher le jeu (tapis et score)>> (écran)
        afficherTapis(tapis);
        cout << endl << endl << endl << "    score = " << score << endl;

        // score >> Analyse du score >> finDePartie
        /* à compléter*/

        // saisie-verif >> choixJoueur
        cout << endl << endl <<  "    <G>arder carte de gauche   <R>ejeter carte de gauche   <A>bandonner   : " ;
        cin >> choixJoueur;

        // choix >> traiter choix du joueur
        /* à compléter*/
        switch choixJoueur
    {

    }

}

// finDePartie >> Terminer la partie >> --
switch(finDePartie)
    {
    case abandon :
        cout << endl << endl  << "    perdu, par abandon " << endl << endl;
        break;
    case perduPlusDeCartes :
        cout << endl << endl  << "    perdu, plus de cartes dans le paquet " << endl << endl;
        break;
    case perduPlusDe51 :
        cout << endl << endl  << "    perdu, votre score  = " << score << " est > 51 points " << endl << endl;
        break;
    case gagne :
        cout << endl << endl  << "    bravo#include <iostream>
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

             , gagne. Votre score = " << score << " points." << endl << endl;
        break;
    default :
        break;
    }

    return 0;
}


unsigned int pointsCarte (UneCarte c)
{
    /* à compléter*/
    return 0;
}


void afficherTapis (UneFile& t)
{
    UneCarte carteCourante;

    // effacer écran
    system("cls"); //  avec #include "stdlib.h" // system("clear"); pour Linux
    // system("cls"); pour Windows

    cout << endl << endl << endl << "    ";

    for (int i=1; i<taille(t); i++)
    {
        defiler(t, carteCourante);
        afficheCarte(carteCourante);
        enfiler(t, carteCourante);
    }

    // affichage du contenu du tapis : /*à compléter*/
    // mise en page à respecter : afficher toutes les cartes sur la même ligne, PAS de saut de ligne à la fin (ce sera fait dans le main)
}
