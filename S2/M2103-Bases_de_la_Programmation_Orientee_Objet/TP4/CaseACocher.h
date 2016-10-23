#ifndef CASEACOCHER_H
#define CASEACOCHER_H

#include "Carre.h"

class CaseACocher
{
protected:
    Carre c;
    bool estActif;

public:
    CaseACocher(const CaseACocher&);
    CaseACocher();
    CaseACocher(int, int, int, Couleur, char);
    CaseACocher(Carre, char);

    void definirCadre(int, int, int, Couleur);
    Carre cadre() const;
    void definirEtat(char);
    char etat() const;
    void dessiner(Fenetre, Couleur) const;
    void afficher(Fenetre& f) const;
    void effacer(Fenetre& f) const;
};

#endif // CASEACOCHER_H
