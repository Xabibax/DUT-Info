#ifndef ELEMENT_GRAPHIQUE_H
#define ELEMENT_GRAPHIQUE_H

#include "Fenetre.h"

class ElementGraphique
{
public :
    virtual void afficher(Fenetre&) const = 0;
    virtual void effacer(Fenetre&) const = 0;
    virtual bool touche(int, int) const = 0;
    virtual ~ElementGraphique() {};
};

#endif // ELEMENT_GRAPHIQUE_H
