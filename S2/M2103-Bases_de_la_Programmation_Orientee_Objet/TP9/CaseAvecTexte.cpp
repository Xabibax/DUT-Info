#include <iostream>
#include <string.h>
#include "CaseAvecTexte.h"

CaseAvecTexte::CaseAvecTexte(const CaseAvecTexte& source):
	CaseACocher(source){
	this->affecterTexte(source.texte);
}

CaseAvecTexte::CaseAvecTexte(CaseACocher cacSource, const char* text):
	CaseACocher(cacSource){
	this->affecterTexte(text);
}

CaseAvecTexte::~CaseAvecTexte(){
	delete[] this->texte;
}

void CaseAvecTexte::affecterTexte(const char *txtSource){
	this->texte = new char[1+strlen(txtSource)];
	strcpy(this->texte, txtSource);
}

void CaseAvecTexte::definirTexte(const char *newText){
	affecterTexte(newText);
}

void CaseAvecTexte::afficher(Fenetre& f) const{
	this->CaseACocher::afficher(f);
	f.choixCouleurTrace(this->CaseACocher::couleur());
	f.ecrit(this->cadre().coordX() + this->cadre().cote()*2,
        this->cadre().coordY() + this->cadre().cote()/2,
        this->texte);
}

void CaseAvecTexte::effacer(Fenetre& f) const{
	this->CaseACocher::effacer(f);
	f.choixCouleurTrace(f.couleurFond());
	f.ecrit(this->cadre().coordX() + this->cadre().cote()*2,
        this->cadre().coordY() + this->cadre().cote()/2,
        this->texte);
}

string CaseAvecTexte::quiSuisJe() const
{
    return "CaseAvecTexte";
}
