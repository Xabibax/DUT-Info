#include "Fenetre.h"
#include "Souris.h"
#include "Carre.h"
#include "CaseACocher.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    f.apparait("Test TP8");
    f.choixCouleurTrace(Couleur(0,0,0));
    s.associerA(f);

    Carre c1(40,40,20,Couleur(65535,0,0));
    const Carre& constC1 = c1;
    Carre c2 = constC1 + 40;
    const Carre& constC2 = c2;

    Carre c3(160,60,20,Couleur(0,65535,65535));
    const Carre& constC3 = c3;
    Carre c4;
    
    c4 = constC2 + constC3;


    if (c4.cote() == 40 &&
	c4.coordX() == 100 &&
	c4.coordY() == 50 &&
	c4.couleur().rouge()== 65535/2 &&
	c4.couleur().vert()== 65535/2 &&
	c4.couleur().bleu()== 65535/2)
	
        f.ecrit(10,80,"Operateurs de la classe Carre : OK");
    else
        f.ecrit(10,80,"Operateurs de la classe Carre : PAS OK");

    CaseACocher cac1 (40,40,60,Couleur(65535,0,0), 'h');
    const CaseACocher& constCac1 = cac1;
    CaseACocher cac2 (c3,'C');
    CaseACocher cac3(cac2);
    const CaseACocher& constCac3 = cac3;
    CaseACocher cac4;

    cac4 = constCac1 + constCac3;
    
    if (cac4.cadre().cote() == 40 &&
	cac4.cadre().coordX() == 100 &&
	cac4.cadre().coordY() == 50 &&
	cac4.cadre().couleur().rouge()== 65535/2 &&
	cac4.cadre().couleur().vert()== 65535/2 &&
	cac4.cadre().couleur().bleu()== 65535/2 && 
	cac4.etat()=='C')
        f.ecrit(10,120,"Operateurs de la classe CaseACocher : OK");
    else
        f.ecrit(10,120,"Operateurs de la classe CaseACocher : PAS OK");


    f.ecrit(100,200,"CLIQUER POUR QUITTER");

    int x,y,b;
    while (!s.testeBoutons(x, y, b));

    f.disparait();

    return 0;
}
