#include "Fenetre.h"
#include "Souris.h"
#include "caseACocher.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    CaseACocher cac;
    CaseACocher cac2;
    const CaseACocher& c = cac;
    int b, x, y;


    f.apparait("Test TP3");
    s.associerA(f);
    f.choixCouleurTrace(0,0,0);

    cac.definirCadre(100,20,40,Couleur(65535,0,0));
    cac.definirEtat('R');

    if ((c.cadre().cote() == 40) &&
	(c.cadre().coordX() == 100 && c.cadre().coordY() == 20) &&
	(c.cadre().couleur().rouge() == 65535 && c.cadre().couleur().vert()==0 &&
	 c.cadre().couleur().bleu() == 0))
	f.ecrit(10,100,"Gestion du cadre : OK");
    else
	f.ecrit(10,100,"Gestion du cadre : PAS OK");

    cac.definirCadre(150,20, 40, Couleur(0,0,65535));

    c.afficher(f);

    cac2.definirCadre(20,20,40,Couleur(65535,0,65335));
    cac2.definirEtat('C');
    cac2.afficher(f);
    cac2.effacer(f);

    f.choixCouleurTrace(0,0,0);
    f.ecrit(10,130,"Si vous voyez une case a cocher bleue, initialement decochee, qui se coche/decoche lorsque");
    f.ecrit (10,150,"vous cliquez alors l'affichage et la gestion de l'etat sont OK");

    f.ecrit(100,240,"CLIC DROIT POUR QUITTER");

    while (!s.testeBoutons(x, y, b));
    while(b!=3){
	if (cac.cadre().touche(x,y)){
	    cac.effacer(f);
	    if (c.etat()=='N')
		cac.definirEtat('C');
	    else
		cac.definirEtat('T');
	    cac.afficher(f);
	}
	while (!s.testeBoutons(x, y, b));

    }

    f.disparait();

    return 0;
}
