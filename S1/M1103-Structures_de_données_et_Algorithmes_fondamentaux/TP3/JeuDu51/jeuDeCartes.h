/*
 Ce paquetage permet de manipuler un (et un seul) jeu de cartes dans un programme.
 Le paquetage gère un paquet de 52 cartes comme le ferait le banquier d'un jeu de casino :
 il peut battre un nouveau paquet et vous donner une carte à votre demande.
*/

#ifndef JEUDECARTES_H
#define JEUDECARTES_H

using namespace std;

enum UneValeur {as=1, deux, trois, quatre, cinq, six, sept, huit, neuf, dix, valet, dame, roi};

enum UneCouleur {coeur=3, carreau, trefle, pique};

typedef struct
{
    UneValeur valeur;
    UneCouleur couleur;
} UneCarte;


void nouveauPaquet (void);
// mélange un nouveau jeu de 52 cartes

UneCarte nouvelleCarte (void);
// pioche une nouvelle carte dans le paquet et la retourne.
// génère l'exception 'paquetEpuise' si toutes les cartes du paquet ont déjà été piochées.

void afficheCarte (UneCarte c);
// affiche une carte àempty() qui renvoie true si le conteneur est vide et false sinon l'écran

/*  Exceptions générées
'paquetEpuise', par nouvelleCarte, si toutes les cartes du paquet ont déjà été piochées.

*/

#endif // JEUDECARTES_H
