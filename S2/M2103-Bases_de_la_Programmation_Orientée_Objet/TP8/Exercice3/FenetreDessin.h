#ifndef FENETRE_DESSIN_H
#define FENETRE_DESSIN_H

#include "Fenetre.h"
#include "ElementGraphique.h"
#define MAXTAB 50

class FenetreDessin : public Fenetre
{
protected:
    int largeurMarge;
    ElementGraphique* elements[MAXTAB];
    int nbElements;

public:
    FenetreDessin(const char* = "Sans titre", int=400, int=400, int=0, int=0, int=65535, int=65535, int=65535, int=150);
    virtual ~FenetreDessin();
    void ajouter(ElementGraphique*);
    void enlever(int);
    int touche(int, int) const;
    void effacer();
    int largeur() const;
    int largeurBoiteOutils() const;
    void disparait();
};

#endif // FENETRE_DESSIN_H
