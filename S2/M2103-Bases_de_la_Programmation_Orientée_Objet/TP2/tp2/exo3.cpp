#include "Fenetre.h"
#include "Souris.h"
#include "Image.h"
#include "Carre.h"

int main (int argc, char* argv[])
{
    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    Carre c;
    int x, y, b;

    f.apparait("Exo 3", 400, 400, 0, 0);
    f.choixCouleurTrace(0,0,0);

    c.placer(100,20);
    c.dimensionner(40);
    c.definirCouleur(65535,0,0);


    c.afficher(f);

    s.associerA(f);

    f.choixCouleurTrace(65535, 0, 0);

    while (!s.testeBoutons(x, y, b));

    while (b!=3)
    {
        if(b==1 && c.touche(x, y) && (c.couleur().rouge() == 65535) && (c.couleur().vert()==0) && (c.couleur().bleu() == 0))
        {
            c.definirCouleur(Couleur(0,0, 65535));
            c.afficher(f);
        }
        else if(b==1 && c.touche(x, y) && (c.couleur().rouge() == 0) && (c.couleur().vert()==0) && (c.couleur().bleu() == 65535))
        {
            c.definirCouleur(Couleur(65535,0, 0));
            c.afficher(f);
        }
        while (!s.testeBoutons(x, y, b));
    }

    f.disparait();

    return 0;
}
