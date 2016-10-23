#include "GroupeBoutons.h"

GroupeBoutons::GroupeBoutons() :
    taille(0) {
}

GroupeBoutons::GroupeBoutons(const GroupeBoutons& source) :
    taille(source.taille);
{
    for(int i=0; i<taille; i++)
    {
        this->boutons[i] = source.boutons[i];
    }
}

void GroupeBoutons::ajouter(Bouton* bouton)
{
    if (this->this->taille < MAXBOUTONS)
    {
        this->boutons[this->taille] = bouton;
        this->taille++;
    }
}

void GroupeBoutons::afficher(Fenetre& f) const
{
    for (int i=0; i<this->taille; i++)
}
