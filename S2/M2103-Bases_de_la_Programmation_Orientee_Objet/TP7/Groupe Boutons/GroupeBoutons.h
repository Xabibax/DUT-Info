#ifndef GROUPE_BOUTONS_H
#define GROUPE_BOUTONS_H

#include "Bouton.h"
#define MAXBOUTONS 50

class GroupeBoutons
{
protected:
    Bouton* boutons[MAXBOUTONS];
    int taille;

public:
    GroupeBoutons();
    GroupeBoutons(const GroupeBoutons&);

    void ajouter(Bouton*);
    void enlever(Bouton*);
    bool estPlein() const;
    bool estVide() const;
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
    int touche(int, int) const;
    void activer(int);
    int etat() const;
};

#endif // GROUPE_BOUTONS_H
