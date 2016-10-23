#include <iostream>
#include "sousProgrammes.h"

using namespace std;

void afficherTour (UnePile& p)
{
    UnePile stockage; //pile de stockage
    initialiser(stockage);
    UnElement elementCourant; // variable de stockage de l'élément à afficher
  // Déplacer tous les éléments de la tour pour les afficher
  while (!estVide(p))
  {
      depiler(p, elementCourant);
      cout << elementCourant << " ";
      empiler(stockage, elementCourant);
  }
  // Reconstruire la tour
  while (!estVide(stockage))
  {
      depiler(stockage, elementCourant);
      empiler(p, elementCourant);
  }
}

void deplacerPetit (UnePile& tA, UnePile& tB, UnePile& tC)
// déplace le petit disque vers une autre tour
// on choisit toujours la suivante, dans le sens des aiguilles d'une montre
{
    if (!estVide(tA) && sommet(tA)==1)
    {
        depiler(tA);
        empiler(tB, 1);
    }
    else if (!estVide(tB) && sommet(tB)==1)
    {
        depiler(tB);
        empiler(tC, 1);
    }
    else
    {
        depiler(tC);
        empiler(tA, 1);
    }
}

void deplacerAutre (UnePile& tA, UnePile& tB, UnePile& tC)
// déplace un autre disque que le petit dans la tour qui reste
{
    unsigned int cas;

    // identifier le cas

    if (! estVide (tA))
    {
        if (sommet(tA) != 1)
        {
            // transfert de sommet(tA) vers (tB ou tC)
            if (! estVide (tB))
            {
                if (sommet(tB) == 1)
                {
                    // tB contient petit,
                    // transfert de l'autre entre tA et TC
                    if (!estVide(tC))
                    {
                        if (sommet(tA) < sommet(tC))
                        {
                            // transfert tA -> tC
                            cas = 13;
                        }
                        else
                        {
                            // transfert de tC -> tA
                            cas = 31;
                        }
                    }
                    else
                    {
                        // tB contient petit, tC est vide
                        // transfert tA -> tC
                        cas = 13;
                    }

                }
                else
                {
                    //sommet(tB) != petit et sommet(tA) != petit
                    // ==> le petit est donc en tC
                    // transfert entre tA et tB
                    if (sommet(tA) < sommet(tB))
                    {
                        // transfert tA -> tC
                        cas = 12;
                    }
                    else
                    {
                        // transfert de tC -> tA
                        cas = 21;
                    }

                }
            }
            else
            {
                // sommet(tA) != petit et tB vide
                // ==> sommet(tC) = petit
                // transfert de tA vers tB
                cas = 12;
            }

        }
        else
        {
            // sommet(tA) = petit; le transfert de l'autre est donc entre tB et tC
            if (! estVide (tB))
            {
                if (!estVide(tC))
                {
                    if (sommet(tB) < sommet(tC))
                    {
                        // transfert tB -> tC
                        cas = 23;
                    }
                    else
                    {
                        // transfert de tC -> tB
                        cas = 32;
                    }
                }
                else
                {
                    // tA contient petit, tC est vide
                    // transfert tB -> tC
                    cas = 23;
                }

            }
            else
            {
                // sommet(tA) = petit et tB vide
                // transfert de tC vers tB
                cas = 32;
            }

        }
    }

    else // tA est vide, le deplacement sera entre (tB ou tC) --> tA

        if (! estVide (tB))
        {
            if (sommet(tB) == 1)
            {
                // le petit est en tB
                if (!estVide(tC))
                {
                    // l'Autre est donc en tC, et on le deplace vers tA
                    cas = 31;
                }
                else
                {
                    // tC est vide aussi, TOUT est dans tB
                    // ==> on ne fait rien
                }
            }
            else
            {
                // tB ne contient pas le petit; et tA est vide,
                // ==> le petit est en TC
                // on déplace donc sommet(tB) vers tA
                cas = 21;
            }
        }
        else
        {
            // tA est vide, tB aussi ==> tout est en tC
            // ne devrait jamais se produire, car situation finale
        }


    // traiter le cas : le déplacement du petit va dans le ses des aiguilles d'une montre

    switch (cas)
    {
    case 12 :
        empiler (tB, sommet(tA));
        depiler (tA);
        break;

    case 13 :
        empiler (tC, sommet(tA));
        depiler (tA);
        break;

    case 21 :
        empiler (tA, sommet(tB));
        depiler (tB);
        break;

    case 23 :
        empiler (tC, sommet(tB));
        depiler (tB);
        break;

    case 31 :
        empiler (tA, sommet(tC));
        depiler (tC);
        break;

    case 32 :
        empiler (tB, sommet(tC));
        depiler (tC);
        break;

    default :
        break;
    }

}

