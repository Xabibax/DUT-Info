#include "Fenetre.h"
#include "Souris.h"
#include "Image.h"
#include "CaseACocher.h"

int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);

    Souris s;
    int xSouris, ySouris, boutonAppuye; // les infos de la souris

    Fenetre f("Exo2 - Case à cocher (avec constructeurs)", 500, 500);
    s.associerA(f);

    CaseACocher c(f.largeur()/2 - 15, f.hauteur()/2 - 15, 30, Couleur(0, 0, 65535), false);
    c.afficher(f);

    while (!s.testeBoutons(xSouris, ySouris, boutonAppuye)); // attendre le premier clique

    while (boutonAppuye!=3) // clique droit : stop le programme
    {
        if(boutonAppuye==1 && c.cadre().touche(xSouris, ySouris)) // si clique gauche
        {
            c.effacer(f);
            if(c.etat()=='C') 
                c.definirEtat('N'); 
            else
                c.definirEtat('C');
            
            c.afficher(f);
        }

        while (!s.testeBoutons(xSouris, ySouris, boutonAppuye)); // wainting for an other click
    }

    f.disparait();

    return 0;
}
