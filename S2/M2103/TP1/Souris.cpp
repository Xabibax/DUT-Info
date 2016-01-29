#include "Souris.h"

void Souris::associerA(Fenetre &fen) {
    associee=&fen; // garder l'adresse de la fen�tre
    }

void Souris::position(int& x, int& y) const {
// on r�cup� les infos de position aupr�s de la fen�tre
    x=associee->getSourisX(); 
    y=associee->getSourisY();
}

gboolean Souris::testeBoutons(int & sx, int & sy, int & bouton) const {
// on r�cup�re les infos de position et de bouton actif aupr�s de la fen�tre
    if ((bouton=associee->getSourisBouton())==-1)
        return FALSE; // aucun bouton n'est actif
    else { // un bouton est actif
        sx=associee->getSourisX(); // coordonn�es asooci�es
        sy=associee->getSourisY();
        return TRUE; // bouton actif
        }
}

