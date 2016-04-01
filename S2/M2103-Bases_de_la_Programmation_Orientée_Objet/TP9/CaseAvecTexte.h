#ifndef CASE_AVEC_TEXTE_H
#define CASE_AVEC_TEXTE_H

#include "Couleur.h"
#include "Fenetre.h"
#include "Carre.h"
#include "CaseACocher.h"

class CaseAvecTexte : public CaseACocher{

protected:
	char *texte;
	void affecterTexte(const char*);

public:
	CaseAvecTexte(const CaseAvecTexte&);
	CaseAvecTexte(CaseACocher = CaseACocher(), const char* ="Sans texte");
	~CaseAvecTexte();
	void definirTexte(const char*);
	virtual void afficher(Fenetre&) const;
	virtual void effacer(Fenetre&) const;
	string quiSuisJe() const;
};

#endif
