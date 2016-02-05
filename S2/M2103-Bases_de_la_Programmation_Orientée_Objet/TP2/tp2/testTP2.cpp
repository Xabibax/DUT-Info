#include "Fenetre.h"
#include "Souris.h"
#include "Carre.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    Carre carre1, carre2;
    int b, x, y;

    f.apparait("Test TP2");
    f.choixCouleurTrace(0,0,0);

    carre1.placer(100,20);
    carre1.dimensionner(40);
    carre1.definirCouleur(65535,0,0);

    const Carre& c1 = carre1;

    c1.afficher(f);

    s.associerA(f);

    if (c1.cote() == 40)
	f.ecrit(10,80,"Dimensions : OK");
    else
	f.ecrit(10,80,"Dimensions : PAS OK");

    if (c1.coordX() == 100 && c1.coordY() == 20)
	f.ecrit(10,100,"Position : OK");
    else
	f.ecrit(10,100,"Position : PAS OK");

    if (carre1.couleur().rouge() == 65535 && carre1.couleur().vert()==0 &&
	carre1.couleur().bleu() == 0)
	f.ecrit(10,120,"Couleur : OK");
    else
	f.ecrit(10,120,"Couleur : PAS OK");

    if (c1.touche(100,20) && c1.touche(140,20) &&
	c1.touche(100,60) && c1.touche(140,60) &&
	!c1.touche(90,30) && !c1.touche(110,70))
	f.ecrit(10,140,"Touche : OK");
    else
	f.ecrit(10,140,"Touche : PAS OK");


    c1.effacer(f);
    carre1.definirCouleur(Couleur(0,0,65535));
    carre1.placer (150,20);
    carre1.afficher(f);
   
    f.choixCouleurTrace(0,0,0);
    f.ecrit(10,180,"Si vous voyez un carre bleu et uniquement ça, alors l'affichage est OK");
 
    f.ecrit(100,240,"CLIQUER POUR QUITTER");

    while (!s.testeBoutons(x, y, b));

    f.disparait();

    return 0;
}
