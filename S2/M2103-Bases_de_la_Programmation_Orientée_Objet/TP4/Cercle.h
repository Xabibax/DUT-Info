#ifndef CERCLE_H
#define CERCLE_H

#include "Couleur.h"
#include "Fenetre.h"

class Cercle
{
protected:
    int x, y, r;
    Couleur color;
    void dessiner(Fenetre, Couleur) const;

public:
    Cercle(const Cercle&);
    Cercle();
    Cercle(int, int, int, Couleur = Couleur(0, 0, 0));

    void placer(int, int);
    int coordX() const;
    int coordY() const;
    void dimensionner(int);
    int rayon() const;
    void definirCouleur(Couleur);
    void definirCouleur(int, int, int);
    Couleur couleur() const;
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
    bool touche(int, int) const;
};

#endif // CERCLE_H
