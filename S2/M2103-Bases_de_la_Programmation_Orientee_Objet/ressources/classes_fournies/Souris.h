#ifndef _SOURIS
#define _SOURIS
#include "Fenetre.h"

class Souris {
private :
    Fenetre* associee; // pointeur vers la fen�tre � laquelle la souris est associ�e
public :
    void associerA(Fenetre &); // associer la souris � une fen�tre
    void position(int&, int&) const; // retourne la position actuelle de la souris
    // retourne TRUE si un bouton de la souris est actif (FALSE sinon)
    // dans ce cas, place dans les 2 1ers param�tres les coordonn�es de la souris
    // les dernier param�tre d�signe le bouton : 1=gauche, 2=centre, 3=droit
    gboolean testeBoutons(int &, int &, int &) const;
};
#endif


