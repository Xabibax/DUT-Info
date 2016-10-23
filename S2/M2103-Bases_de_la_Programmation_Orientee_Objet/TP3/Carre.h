#ifndef _CARRE
#define _CARRE

#include "Couleur.h"
#include "Fenetre.h"

class Carre {

protected:
    int x, y, longueur;
    Couleur color;
    void dessiner(Fenetre, Couleur) const;

public:
    void placer(int, int);
    int coordX() const;
    int coordY() const;
    void dimensionner(int);
    int cote() const;
    void definirCouleur(Couleur);
    void definirCouleur(int, int, int);
    Couleur couleur() const;
    void afficher(Fenetre) const;
    void effacer(Fenetre) const;
    bool touche(int, int) const;
};

#endif // _CARRE
