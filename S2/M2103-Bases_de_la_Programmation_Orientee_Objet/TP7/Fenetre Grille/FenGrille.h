#ifndef __FENGRILLE_H
#define __FENGRILLE_H

#include "Fenetre.h"
#include "CaseACocher.h"
#include "CaseAvecTexte.h"

class FenGrille : public Fenetre {

protected:
	int dimColonne; // Largeur des colonnes
	int dimLigne; // Largeur des lignes
	void dessinerGrille();

public:
	FenGrille(int = 20, int = 20);
	FenGrille(const char*, int, int, int = 20, int = 20, int = 0, int = 0, int = 65535, int = 65535, int = 65535);
	FenGrille(const FenGrille&);
    void apparait(const char* ="Sans nom", int=400, int=400, int=0, int=0, int=65535, int=65535, int=65535);
	void effacer();
	void afficherCase(CaseACocher);
};

#endif //__FENGRILLE_H
