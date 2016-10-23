#include "Couleur.h"

Couleur::Couleur(int r, int v, int b) {
// mise en place des composantes RVB
    changeCouleur(r, v, b);
    }

void Couleur::changeCouleur(int r, int v, int b) {
// modification des composantes RVB
    coul.red=r; coul.green=v; coul.blue=b;
    }

int Couleur::rouge() const { return coul.red; }
int Couleur::vert() const { return coul.green; }
int Couleur::bleu() const { return coul.blue; }

