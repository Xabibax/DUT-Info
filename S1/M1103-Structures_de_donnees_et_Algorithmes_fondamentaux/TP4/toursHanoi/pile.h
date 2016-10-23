/* Permet de manipuler des piles
   Plusieurs piles peuvent etre manipulees a condition qu'elles contiennent
   toutes le meme type d'elements */

#ifndef PILE_H
#define PILE_H

#include <stack>
using namespace std;

/* *****************************************************
   DEFINITION DU TYPE DES ELEMENTS CONTENUS DANS LA PILE
   *****************************************************

   Pour faire une pile avec des types de base :
   typedef int UnElement;


   Pour faire une pile avec des elements de type struct :
   typedef struct
   {
   int coordX; // abscisse du point
   int coordY; // ordonnee du point
   } UnElement;


   Pour faire une pile avec des elements dont le type est defini dans un autre fichier :
   #include "leFichierOuEstDefiniLeType.h"
   typedef leTypeDefiniDansLeFichier UnElement;
*/

typedef unsigned int UnElement;

/* *************************************************** */


typedef stack<UnElement> UnePile;


void initialiser (UnePile& p);
// Initialise ou ré-initialise une pile vide prête à l'emploi

unsigned int taille (const UnePile& p);
// Retourne le nombre d'elements contenus dans la pile p

bool estVide (const UnePile& p);
// Retourne vrai si la pile p est vide, faux sinon

UnElement sommet (const UnePile& p);
// Retourne l'element situe au sommet de la pile p
//  Genere l'exception "pileVide" si la pile p est vide


void empiler (UnePile& p, UnElement e);
// Ajoute l'element e au sommet de ma pile p


void depiler (UnePile& p);
// Retire l'element situe au sommet de la pile p
//   Genere l'exception "pileVide" si la pile p est vide

void depiler (UnePile& p, UnElement& e);
// Retire l'element situe au sommet de la pile p et le stocke dans e
//   Genere l'exception "pileVide" si la pile p est vide

#endif
