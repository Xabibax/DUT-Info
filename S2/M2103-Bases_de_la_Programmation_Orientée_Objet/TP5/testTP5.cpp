#include "Fenetre.h"
#include "Souris.h"
#include "Carre.h"
#include "CaseACocher.h"
#include "CaseAvecTexte.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    f.apparait("Test TP5");
    f.choixCouleurTrace(Couleur(0,0,0));
    s.associerA(f);

    CaseACocher cac1(40,40,30,Couleur(65535,0,0), 'h');
    CaseAvecTexte cat1(cac1, "cliquer pour faire disparaitre la case verte");

    CaseACocher cac2 (40,80,30,Couleur(0,50000,0), 'C');
    CaseAvecTexte cat2(cac2);

    CaseAvecTexte cat3(cat2);
    cat2.definirTexte("si vous voyez ce texte il y a une erreur");

    cat1.afficher(f);
    cat3.afficher(f);

    f.choixCouleurTrace(Couleur(0,0,0));
    f.ecrit(10,140,"Si vous voyez une case rouge et une case verte, ");
    f.ecrit(10,160,"Si le texte de la case verte est 'Sans Texte', ");
    f.ecrit(10,180,"Et si les clics sur la case rouge font bien disparaitre la case verte");
    f.ecrit(10,200,"alors votre classe est correcte !!");

    f.ecrit(100,240,"CLIC-DROIT POUR QUITTER");

    int x,y,b;
    while (!s.testeBoutons(x, y, b));
    while (b!=3)
    {
        if (cat1.cadre().touche(x,y))
        {
            cat1.effacer(f);
            if (cat1.etat()=='C')
            {
                cat3.afficher(f);
                cat1.definirTexte("cliquer pour faire disparaitre la case verte");
                cat1.definirEtat('N');
            }
            else
            {
                cat3.effacer(f);
                cat1.definirTexte("cliquer pour faire apparaitre la case verte");
                cat1.definirEtat('C');
            }
            cat1.afficher(f);
        }
        while (!s.testeBoutons(x, y, b));
    }

    f.disparait();

    return 0;
}
