#ifndef CERCLE_H
#define CERCLE_H

#include "Couleur.h"
#include "Fenetre.h"

class Cercle
{
protected:
    int x, y, r;
    Couleur color;

public:
    void placer(int, int);
    void dimensionner(int);
    void definirCouleur(int, int, int);
    void definirCouleur(Couleur);
    int coordX() const;
    int coordY() const;
    int rayon() const;
    Couleur couleur() const;
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
    bool touche(int, int) const;
};

#endif // CERCLE_H
