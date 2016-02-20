#include "Fenetre.h"
#include "Souris.h"
#include "Image.h"
#include "caseACocher.h"

int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    int xSouris, ySouris, boutonAppuye; // les infos de la souris
    CaseACocher c;
    Couleur color;

    f.apparait("Exo3 - Case à cocher");
    s.associerA(f);
    color.changeCouleur(0,0,65535);

    c.definirCadre(175, 175, 30, color); // place the box depending window's size
    c.definirEtat('N');
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
