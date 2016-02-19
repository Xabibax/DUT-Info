#include "Fenetre.h"
#include "Souris.h"
#include "Carre.h"
#include "CaseACocher.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    f.apparait("Test TP4");
    f.choixCouleurTrace(Couleur(0,0,0));
    s.associerA(f);

    Carre c1;
    Carre c2(40,40,10, Couleur(65535,0,0));
    Carre c3(40,40,20);
    Carre c4 (c3);

    if (c4.cote() == 20 &&
	c4.coordX() == 40 &&
	c4.coordY() == 40 &&
	c4.couleur().rouge()== 0 &&
	c4.couleur().vert()== 0 &&
	c4.couleur().bleu()== 0)
        f.ecrit(10,20,"Constructeur de copie de la classe Carre : OK");
    else
        f.ecrit(10,20,"Constructeur de copie de la classe Carre : PAS OK");

    if (c1.cote() == 20 &&
	c1.coordX() == 10 &&
	c1.coordY() == 10 &&
	c1.couleur().rouge()== 0 &&
	c1.couleur().vert()== 0 &&
	c1.couleur().bleu()== 0)

        f.ecrit(10,40,"Constructeur par défaut de la classe Carre : OK");
    else
        f.ecrit(10,40,"Constructeur par défaut de la classe Carre : PAS OK");

    if (c2.cote() == 10 &&
	c2.coordX() == 40 &&
	c2.coordY() == 40 &&
	c2.couleur().rouge()== 65535 &&
	c2.couleur().vert()== 0 &&
	c2.couleur().bleu()== 0 &&
	c3.couleur().rouge()== 0 &&
	c3.couleur().vert()== 0 &&
	c3.couleur().bleu()== 0)

        f.ecrit(10,60,"Constructeur complet de la classe Carre : OK");
    else
        f.ecrit(10,60,"Constructeur complet de la classe Carre : PAS OK");



    CaseACocher cac1 (40,40,60,Couleur(65535,0,0), 'h');
    CaseACocher cac2 (c3,'C');
    CaseACocher cac3(cac2);
    CaseACocher cac4;

    if (cac4.cadre().cote() == 20 &&
	cac4.cadre().coordX() == 10 &&
	cac4.cadre().coordY() == 10 &&
	cac4.cadre().couleur().rouge()== 0 &&
	cac4.cadre().couleur().vert()== 0 &&
	cac4.cadre().couleur().bleu()== 0 &&
	cac4.etat()=='N'
        )
        f.ecrit(10,80,"Constructeur par défaut de la classe CaseACocher : OK");
    else
        f.ecrit(10,80,"Constructeur par défaut de la classe CaseACocher : PAS OK");

    if (cac1.cadre().cote() == 60 &&
	cac1.cadre().coordX() == 40 &&
	cac1.cadre().coordY() == 40 &&
	cac1.cadre().couleur().rouge()== 65535 &&
	cac1.cadre().couleur().vert()== 0 &&
	cac1.cadre().couleur().bleu()== 0 &&
	cac1.etat()=='N')
        f.ecrit(10,100,"Constructeur (int, int, int, Couleur, char) de la classe CaseACocher : OK");
    else
        f.ecrit(10,100,"Constructeur (int, int, int, Couleur, char) de la classe CaseACocher : PAS OK");

    if (cac2.cadre().cote() == 20 &&
	cac2.cadre().coordX() == 40 &&
	cac2.cadre().coordY() == 40 &&
	cac2.cadre().couleur().rouge()== 0 &&
	cac2.cadre().couleur().vert()== 0 &&
	cac2.cadre().couleur().bleu()== 0 &&
	cac2.etat()=='C')
        f.ecrit(10,120,"Constructeur (Carre, char) de la classe CaseACocher : OK");
    else
        f.ecrit(10,120,"Constructeur (Carre, char) de la classe CaseACocher : PAS OK");





    f.ecrit(100,200,"CLIQUER POUR QUITTER");

    int x,y,b;
    while (!s.testeBoutons(x, y, b));

    f.disparait();

    return 0;
}
