#ifndef _SOURIS
#define _SOURIS
#include "Fenetre.h"

class Souris {
private :
    Fenetre* associee; // pointeur vers la fenêtre à laquelle la souris est associée
public :
    void associerA(Fenetre &); // associer la souris à une fenêtre
    void position(int&, int&) const; // retourne la position actuelle de la souris
    // retourne TRUE si un bouton de la souris est actif (FALSE sinon)
    // dans ce cas, place dans les 2 1ers paramètres les coordonnées de la souris
    // les dernier paramètre désigne le bouton : 1=gauche, 2=centre, 3=droit
    gboolean testeBoutons(int &, int &, int &) const;
};
#endif


