#include "Fenetre.h"
#include "Souris.h"
#include "Image.h"
#include "CaseACocher.h"

int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);

    Souris s;
    int xSouris, ySouris, boutonAppuye; // les infos de la souris

    Fenetre f("Exo2", 500, 500);
    s.associerA(f);

    CaseACocher c(f.largeur()/2 - 15, f.hauteur()/2 - 15, 30, Couleur(0, 0, 65535), false);
    c.afficher(f);

    while (!s.testeBoutons(xSouris, ySouris, boutonAppuye)); // waiting fist click

    while (boutonAppuye!=3) // right button stop the loop
    {
        if(boutonAppuye==1 && c.cadre().touche(xSouris, ySouris)) // left button tick the box
        {
            c.effacer(f);
            if(c.etat()=='C') // if the box is already activated
                c.definirEtat('N'); // desactivate it
            else
                c.definirEtat('C'); // else (it's desactivated) -> activate it
            // display the new box
            c.afficher(f);
        }

        while (!s.testeBoutons(xSouris, ySouris, boutonAppuye)); // wainting for an other click
    }

    f.disparait();

    return 0;
}
