#include "FenGrille.h"
#include "Souris.h"
#include "Bouton.h"

int main (int argc, char **argv)
{
    gtk_init(&argc, &argv);

    FenGrille f;
    Souris s;
    f.apparait("TP7 - exo 2 - Bouton");
    f.choixCouleurTrace(Couleur(0,0,0));
    s.associerA(f);

	Bouton bt1(40,40,30,Couleur(65535,0,0), 'h');
	Bouton bt2(40,80,30,Couleur(0,50000,0), 'h');


	int x,y,b;
    while (!s.testeBoutons(x, y, b));

    return 0;
}
