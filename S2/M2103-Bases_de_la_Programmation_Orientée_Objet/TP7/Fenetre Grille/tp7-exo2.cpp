#include "FenGrille.h"
#include "Souris.h"

int main (int argc, char **argv)
{
    gtk_init(&argc, &argv);

    FenGrille f;
    Souris s;
    f.apparait("TP7 - exo 2");
    f.choixCouleurTrace(Couleur(0,0,0));
    s.associerA(f);

	CaseACocher cac1(40,40,30,Couleur(65535,0,0), 'h');
	CaseACocher cac2(40,80,30,Couleur(0,50000,0), 'h');

	f.afficherCase(cac1);
	f.afficherCase(cac2);

	int x,y,b;
    while (!s.testeBoutons(x, y, b));

    return 0;
}
