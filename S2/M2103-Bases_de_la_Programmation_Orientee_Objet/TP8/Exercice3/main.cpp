#include <iostream>

#include "FenetreDessin.h"
#include "Souris.h"
#include "CaseAvecTexte.h"
#include "CaseACocher.h"
#include "Carre.h"

using namespace std;

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    FenetreDessin f("TP8 - Exercice 3", 400, 400);
    Souris s;
    //f.apparait("TP8 - Exercice 3");
    f.choixCouleurTrace(0, 0, 0);
    s.associerA(f);

    CaseAvecTexte cat1 ((CaseACocher(Carre(f.largeur() + 30, 30, 15), true)), "Carre");
    CaseAvecTexte cat2 ((CaseACocher(Carre(f.largeur() + 30, 60, 15), true)), "Case à cocher");
    CaseAvecTexte cat3 ((CaseACocher(Carre(f.largeur() + 30, 90, 15), true)), "Case avec texte");
    CaseAvecTexte cat4 ((CaseACocher(Carre(f.largeur() + 30, 120, 15), true)), "SUPPRIMER");

    cat1.afficher(f);
    cat2.afficher(f);
    cat3.afficher(f);
    cat4.afficher(f);

    int x, y, b;

    while (!s.testeBoutons(x, y, b));

    while (b!=3)
    {
        if(b==1)
        {
            if(cat1.touche(x, y))
            {
                while (!s.testeBoutons(x, y, b));
                if(f.estDansLaFenetre(x, y))
                    f.ajouter(new Carre(x-10, y-10, 20, Couleur()));
            }
            else if(cat2.touche(x, y))
            {
                while (!s.testeBoutons(x, y, b));
                if(f.estDansLaFenetre(x, y))
                    f.ajouter(new CaseACocher(Carre(x-10, y-10, 20, Couleur()), 'C'));
            }
            else if(cat3.touche(x, y))
            {
                while (!s.testeBoutons(x, y, b));
                if(f.estDansLaFenetre(x, y))
                    f.ajouter(new CaseAvecTexte(CaseACocher(Carre(x-10, y-10, 20, Couleur()), true), "Texte"));
            }
            else if(cat4.touche(x, y))
            {
                while (!s.testeBoutons(x, y, b));
                f.enlever(f.touche(x, y));
            }
        }
        while (!s.testeBoutons(x, y, b));
    }

    f.disparait();

    return 0;
}
