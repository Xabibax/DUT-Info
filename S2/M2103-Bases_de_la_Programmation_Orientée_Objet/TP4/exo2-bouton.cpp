#include "Fenetre.h"
#include "Souris.h"
#include "Image.h"
#include "Bouton.h"

int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);

    Souris s;
    int xSouris, ySouris, boutonAppuye; // les infos de la souris

    Fenetre f("Exo2 - Bouton (avec constructeurs)", 500, 500);
    s.associerA(f);

    Bouton b(f.largeur()/2 - 15, f.hauteur()/2 - 15, 30, Couleur(0, 0, 65535), false);
    b.afficher(f);

    while (!s.testeBoutons(xSouris, ySouris, boutonAppuye)); // attendre le premier clique

    while (boutonAppuye!=3) // clique droit : stop le programme
    {
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
