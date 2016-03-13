#include <iostream>
#include <string.h>
#include "BoutonAvecTexte.h"

BoutonAvecTexte::BoutonAvecTexte(Bouton b, const char *t) :
    Bouton(b) {
    this->affecterTexte(t);
}

BoutonAvecTexte::BoutonAvecTexte(const BoutonAvecTexte& source) :
    Bouton(source) {
    this->affecterTexte(source.texte);
}

BoutonAvecTexte::~BoutonAvecTexte() {
    delete [] this->texte;
}

void BoutonAvecTexte::definirTexte(const char *t)
{
    delete [] this->texte;
    this->affecterTexte(t);
}

void BoutonAvecTexte::afficher(Fenetre& f) const
{
    this->Bouton::afficher(f);
    this->afficherTexte(f, this->couleur());
}

void BoutonAvecTexte::effacer(Fenetre& f) const
{
    this->Bouton::effacer(f);

    Couleur coul;
    coul = (f.couleurFond());
    this->afficherTexte(f, coul);
}

void BoutonAvecTexte::affecterTexte(const char *t)
{
    this->texte = new char [strlen(t) + 1];
    strcpy(this->texte, t);
}

void BoutonAvecTexte::afficherTexte(Fenetre& f, Couleur color) const
{
    f.choixCouleurTrace(color);
    f.ecrit(this->circle().coordX() + 3 * this->circle().rayon() / 2,
            this->circle().coordY(),
            this->texte);
}

