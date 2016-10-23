#include "FenGrille.h"
#include "Souris.h"
#include "Carre.h"
#include "CaseACocher.h"
#include "CaseAvecTexte.h"

int main (int argc, char **argv)
{
    gtk_init(&argc, &argv);

    FenGrille f;
    Souris s;
    f.apparait("TP7 - exo 3");
    //f.choixCouleurTrace(Couleur(0,0,0));
    s.associerA(f);

	CaseACocher cac1(40,40,40,Couleur(65535,0,0), 'h');
	CaseAvecTexte cat1(cac1, " ");

	CaseACocher cac2(40,120,40,Couleur(0,50000,0), 'C');
	CaseAvecTexte cat2(cac2, "jilglojk");

	f.afficherCase(cat1);
	f.afficherCase(cat2);

	int x,y,b;
    while (!s.testeBoutons(x, y, b));

    return 0;
}
