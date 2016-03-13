#include "Fenetre.h"
#include "Souris.h"
#include "Cercle.h"
#include "Bouton.h"
#include "BoutonAvecTexte.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    f.apparait("Test TP5 - Bouton");
    f.choixCouleurTrace(Couleur(0,0,0));
    s.associerA(f);

    Bouton bt1(40,40,30,Couleur(65535,0,0), 'h');
    BoutonAvecTexte bat1(bt1, "cliquer pour faire disparaitre le bouton vert");

    Bouton bt2 (40,120,30,Couleur(0,50000,0), 'C');
    BoutonAvecTexte bat2(bt2);

    BoutonAvecTexte bat3(bat2);
    bat2.definirTexte("si vous voyez ce texte il y a une erreur");

    bat1.afficher(f);
    bat3.afficher(f);

    f.choixCouleurTrace(Couleur(0,0,0));
    f.ecrit(10,200,"Si vous voyez un bouton rouge et un bouton vert, ");
    f.ecrit(10,220,"Si le texte du bouton vert est 'Sans Texte', ");
    f.ecrit(10,240,"Et si les clics sur le bouton rouge font bien disparaitre le bouton vert");
    f.ecrit(10,260,"alors votre classe est correcte !!");

    f.ecrit(100,300,"CLIC-DROIT POUR QUITTER");

    int x,y,b;
    while (!s.testeBoutons(x, y, b));
    while (b!=3)
    {
        if (bat1.circle().touche(x,y))
        {
            bat1.effacer(f);
            if (bat1.etat()=='C')
            {
                bat3.afficher(f);
                bat1.definirTexte("cliquer pour faire disparaitre le bouton vert");
                bat1.definirEtat('N');
            }
            else
            {
                bat3.effacer(f);
                bat1.definirTexte("cliquer pour faire apparaitre le bouton vert");
                bat1.definirEtat('C');
            }
            bat1.afficher(f);
        }
        while (!s.testeBoutons(x, y, b));
    }

    f.disparait();

    return 0;
}
