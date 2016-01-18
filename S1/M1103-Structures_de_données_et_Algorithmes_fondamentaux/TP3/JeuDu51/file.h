/* Permet de manipuler des files d'attente
   Plusieurs files peuvent etre manipulees a condition qu'elles contiennent
   toutes le meme type d'elements */

#ifndef FILE_H
#define FILE_H
#include <queue>
using namespace std;



/* *****************************************************
   DEFINITION DU TYPE DES ELEMENTS CONTENUS DANS LA FILE
   *****************************************************

   Pour faire une file avec des types de base :
   typedef int UnElement;


   Pour faire une file avec des elements de type struct :
   typedef struct
   {
   int coordX; // abscisse du point
   int coordY; // ordonnee du point
   } UnElement;


   Pour faire une file avec des elements dont le type est defini dans un autre fichier :
   #include "leFichierOuEstDefiniLeType.h"
   typedef leTypeDefiniDansLeFichier UnElement;
*/

#include "jeuDeCartes.h"
typedef UneCarte UnElement;


/* *************************************************** */

typedef queue<UnElement> UneFile;

void initialiser (UneFile& f);
// Initialise ou ré-initialise une file vide prête à l'emploi

unsigned int taille (const UneFile& f);
// Retourne le nombre d'elements stockes dans la file f

bool estVide (const UneFile& f);
// Retourne vrai si la file f est vide, faux sinon

UnElement premier (const UneFile& f);
/* Retourne l'element situe en tete de la file f
   Genere l'exception "fileVide" si la file f est vide */

void enfiler (UneFile& f, UnElement e);
// Ajoute l'element e en queue de la file f

void defiler (UneFile& f);
/* Retire l'element situe en tete de la file f
   Genere l'exception "fileVide" si la file f est vide */

void defiler (UneFile& f, UnElement& e);
/* Retire l'element situe en tete de la file f et le stocke dans e
   Genere l'exception "fileVide" si la file f est vide */


#endif
