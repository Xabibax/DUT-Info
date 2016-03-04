#ifndef BOUTON_H
#define BOUTON_H

#include "Cercle.h"

class Bouton : public Cercle
{
protected:
    char estActif;
    void dessiner(Fenetre, Couleur) const;

public:
    Bouton(const Bouton&);
    Bouton();
    Bouton(Cercle, char);

    void definir(int, int, int, int, int, int, char);
    void definir(int, int, int, Couleur, char);
    void activer();
	void desactiver();
    bool estActif() const;
    Couleur couleur() const;
    void afficher(Fenetre& f) const;
    void effacer(Fenetre& f) const;
};

#endif // BOUTON_H
