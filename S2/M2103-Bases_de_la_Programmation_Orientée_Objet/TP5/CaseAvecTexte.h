#ifndef CASE_AVEC_TEXTE_H
#define CASE_AVEC_TEXTE_H

#include "Couleur.h"
#include "Fenetre.h"
#include "Carre.h"
#include "CaseACocher.h"

class CaseAvecTexte : public CaseACocher{

private:
	char *texte;
	void affecterTexte(const char*);

public:
	CaseAvecTexte(const CaseAvecTexte&);
	CaseAvecTexte(CaseACocher = CaseACocher(), const char* ="Sans texte");
	~CaseAvecTexte();
	void definirTexte(const char*);
	void afficher(Fenetre&) const;
	void effacer(Fenetre&) const;
};

#endif
