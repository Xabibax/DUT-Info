#include "Fenetre.h"
#include "Souris.h"
#include "Image.h"
#include "Bouton.h"

int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    int xSouris, ySouris, boutonAppuye;
    Bouton b;
    Couleur color;

    f.apparait("Exo3 - Bouton");
    s.associerA(f);
    color.changeCouleur(0,0,65535);

    b.definir(175, 175, 30, color);
    b.definirEtat('N');
    b.afficher(f);

    while (!s.testeBoutons(xSouris, ySouris, boutonAppuye)); // attendre le premier clique

    while (boutonAppuye!=3) // clique droit : stop le programme
        if(boutonAppuye==1 && b.circle().touche(xSouris, ySouris)) // si clique gauche
        {
            b.effacer(f);

            if(b.etat()=='C')
                b.definirEtat('N');
            else
                b.definirEtat('C');

            b.afficher(f);
        }

        while (!s.testeBoutons(xSouris, ySouris, boutonAppuye)); // attendre un autre clique
    }

    f.disparait();

    return 0;
}
