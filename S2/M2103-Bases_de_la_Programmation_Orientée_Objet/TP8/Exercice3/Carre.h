#ifndef _CARRE
#define _CARRE

#include "Couleur.h"
#include "Fenetre.h"
#include "ElementGraphique.h"

class Carre : public ElementGraphique
{

protected:
    int x, y, longueur;
    Couleur color;
    void dessiner(Fenetre&, Couleur) const;

public:
    Carre(const Carre&);
    Carre();
    Carre(int, int, int, Couleur = Couleur(0, 0, 0));

    void placer(int, int);
    int coordX() const;
    int coordY() const;
    void dimensionner(int);
    int cote() const;
    void definirCouleur(Couleur);
    void definirCouleur(int, int, int);
    Couleur couleur() const;
    virtual void afficher(Fenetre&) const;
    virtual void effacer(Fenetre&) const;
    virtual bool touche(int, int) const;
    virtual ~Carre() {};
};

#endif // _CARRE
