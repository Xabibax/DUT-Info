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

    FenetreDessin f("TP9", 1024, 720);
    Souris s;
    f.choixCouleurTrace(0, 0, 0);
    s.associerA(f);

    CaseAvecTexte cat1 ((CaseACocher(Carre(f.largeur() + 30, 30, 15), true)), "Carre");
    CaseAvecTexte cat2 ((CaseACocher(Carre(f.largeur() + 30, 60, 15), true)), "Case a cocher");
    CaseAvecTexte cat3 ((CaseACocher(Carre(f.largeur() + 30, 90, 15), true)), "Case avec texte");
    CaseAvecTexte cat4 ((CaseACocher(Carre(f.largeur() + 30, 120, 15), true)), "Couleur Noire");
    CaseAvecTexte cat5 ((CaseACocher(Carre(f.largeur() + 30, 150, 15), true)), "Couleur Bleue");
    CaseAvecTexte cat6 ((CaseACocher(Carre(f.largeur() + 30, 180, 15), true)), "Activer");
    CaseAvecTexte cat7 ((CaseACocher(Carre(f.largeur() + 30, 210, 15), true)), "Desactiver");
    CaseAvecTexte cat8 ((CaseACocher(Carre(f.largeur() + 30, 240, 15), true)), "SUPPRIMER");

    cat1.afficher(f);
    cat2.afficher(f);
    cat3.afficher(f);
    cat4.afficher(f);
    cat5.afficher(f);
    cat6.afficher(f);
    cat7.afficher(f);
    cat8.afficher(f);

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
                if(f.estDansLaFenetre(x, y))
                {
                    //f.definirCouleur(f.touche(x, y), Couleur(0, 0, 0));
                    if(f.touche(x, y) >= 0)
                    {
                        f.element(f.touche(x, y))->definirCouleur(Couleur(0, 0, 0));
                        f.actualiser();
                    }
                }
            }
            else if(cat5.touche(x, y))
            {
                while (!s.testeBoutons(x, y, b));
                if(f.estDansLaFenetre(x, y))
                {
                    //f.definirCouleur(f.touche(x, y), Couleur(0, 0, 65535));
                    if(f.touche(x, y) >= 0)
                    {
                        f.element(f.touche(x, y))->definirCouleur(Couleur(0, 0, 65535));
                        f.actualiser();
                    }
                }
            }
            else if(cat6.touche(x, y))
            {
                while (!s.testeBoutons(x, y, b));
                if(f.touche(x, y) >=0)
                {
                    if((f.element(f.touche(x, y))->quiSuisJe() == "CaseACocher") ||
                            (f.element(f.touche(x, y))->quiSuisJe() == "CaseAvecTexte"))
                    {
                        CaseACocher* tmp = (CaseACocher*) f.element(f.touche(x, y));
                        tmp->definirEtat('C');
                        f.actualiser();
                    }
                }

            }
            else if(cat7.touche(x, y))
            {
                while (!s.testeBoutons(x, y, b));
                if(f.touche(x, y) >=0)
                {
                    if((f.element(f.touche(x, y))->quiSuisJe() == "CaseACocher") ||
                            (f.element(f.touche(x, y))->quiSuisJe() == "CaseAvecTexte"))
                    {
                        CaseACocher* tmp = (CaseACocher*) f.element(f.touche(x, y));
                        tmp->definirEtat('N');
                        f.actualiser();
                    }
                }
            }
            else if(cat8.touche(x, y))
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
