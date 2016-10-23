#ifndef CASEACOCHER_H
#define CASEACOCHER_H

#include "Carre.h"

class CaseACocher : public Carre
{
protected:
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
    void dessiner(Fenetre&, Couleur) const;
    virtual void afficher(Fenetre& ) const;
    virtual void effacer(Fenetre& ) const;
    string quiSuisJe() const;
};

#endif // CASEACOCHER_H
