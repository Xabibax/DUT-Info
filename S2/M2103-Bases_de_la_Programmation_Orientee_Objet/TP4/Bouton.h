#ifndef BOUTON_H
#define BOUTON_H

#include "Cercle.h"

class Bouton
{
protected:
    Cercle c;
    char estActif;

public:
    Bouton(const Bouton&);
    Bouton();
    Bouton(int, int, int, Couleur, char);
    Bouton(Cercle, char);

    void definir(int, int, int, int, int, int);
    void definir(int, int, int, Couleur);
    Cercle circle() const;
    void definirEtat(char);
    char etat() const;
    Couleur couleur() const;
    void dessiner(Fenetre, Couleur) const;
    void afficher(Fenetre& f) const;
    void effacer(Fenetre& f) const;
};

#endif // BOUTON_H
