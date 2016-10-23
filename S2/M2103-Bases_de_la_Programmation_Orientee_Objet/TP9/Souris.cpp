#include "Souris.h"

void Souris::associerA(Fenetre &fen) {
    associee=&fen; // garder l'adresse de la fenêtre
    }

void Souris::position(int& x, int& y) const {
// on récupè les infos de position auprès de la fenêtre
    x=associee->getSourisX(); 
    y=associee->getSourisY();
}

gboolean Souris::testeBoutons(int & sx, int & sy, int & bouton) const {
// on récupère les infos de position et de bouton actif auprès de la fenêtre
    if ((bouton=associee->getSourisBouton())==-1)
        return FALSE; // aucun bouton n'est actif
    else { // un bouton est actif
        sx=associee->getSourisX(); // coordonnées asoociées
        sy=associee->getSourisY();
        return TRUE; // bouton actif
        }
}

