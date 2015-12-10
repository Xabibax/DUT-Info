/*
 Ce paquetage permet de manipuler un (et un seul) jeu de cartes dans un programme.
 Le paquetage g�re un paquet de 52 cartes comme le ferait le banquier d'un jeu de casino :
 il peut battre un nouveau paquet et vous donner une carte � votre demande.
*/

#ifndef JEUDECARTES
#define JEUDECARTES

using namespace std;

// D�finition du type UneCarte
enum UneValeur {as=1, deux, trois, quatre, cinq, six, sept, huit, neuf, dix, valet, dame, roi};

enum UneCouleur {coeur=3, carreau, trefle, pique};

typedef struct
{
    UneValeur valeur;
    UneCouleur couleur;
} UneCarte;


void nouveauPaquet (void);
// m�lange un nouveau jeu de 52 cartes

UneCarte nouvelleCarte (void);
// pioche une nouvelle carte dans le paquet et la retourne.
// g�n�re l'exception 'paquetEpuise' si toutes les cartes du paquet ont d�j� �t� pioch�es.

void afficheCarte (UneCarte c);
// affiche une carte � l'�cran

/*  Exceptions g�n�r�es
'paquetEpuise', par nouvelleCarte, si toutes les cartes du paquet ont d�j� �t� pioch�es.

*/
#endif // JEUDECARTES_H
