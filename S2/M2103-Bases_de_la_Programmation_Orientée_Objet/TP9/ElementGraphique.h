#ifndef ELEMENT_GRAPHIQUE_H
#define ELEMENT_GRAPHIQUE_H

#include "Fenetre.h"
#include <iostream>

using namespace std;

class ElementGraphique
{
public :
    virtual void afficher(Fenetre&) const = 0;
    virtual void effacer(Fenetre&) const = 0;
    virtual bool touche(int, int) const = 0;
    virtual void definirCouleur(Couleur) = 0;
    virtual string quiSuisJe() const = 0;
    virtual ~ElementGraphique() {};
};

#endif // ELEMENT_GRAPHIQUE_H
