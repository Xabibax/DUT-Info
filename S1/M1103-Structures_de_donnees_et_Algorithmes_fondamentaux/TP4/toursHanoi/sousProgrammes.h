#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include <iostream>
#include "pile.h"

void deplacerPetit (UnePile& tA, UnePile& tB, UnePile& tC);
// déplace le petit disque vers une autre tour
// on choisit toujours la suivante, dans le sens des aiguilles d'une montre

void deplacerAutre (UnePile& tA, UnePile& tB, UnePile& tC);
// déplace un autre disque que le petit dans la tour qui reste

void afficherTour (UnePile& p);
// affiche à l'écran le contenu de la pile

#endif
