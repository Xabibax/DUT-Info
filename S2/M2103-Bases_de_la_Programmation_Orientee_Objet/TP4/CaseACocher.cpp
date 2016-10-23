#include "CaseACocher.h"

CaseACocher::CaseACocher(const CaseACocher& source) :
    c(source.c),
    estActif(source.estActif){
}

CaseACocher::CaseACocher() :
    c(),
    estActif(false){
}

CaseACocher::CaseACocher(int x, int y, int longueur, Couleur color, char estActif) :
    c(x, y, longueur, color),
	estActif(estActif=='C'){
}

CaseACocher::CaseACocher(Carre pc, char pestActif) :
    c(pc),
    estActif(pestActif == 'C'){
}

void CaseACocher::definirCadre(int x, int y, int longueur, Couleur couleur)
{
    this->c.placer(x, y);
    this->c.dimensionner(longueur);
    this->c.definirCouleur(couleur);
}

Carre CaseACocher::cadre() const
{
    return this->c;
}

void CaseACocher::definirEtat(char lettre)
{
    this->estActif = (lettre=='C') ? true : false;
}

char CaseACocher::etat() const
{
    return (this->estActif) ? 'C' : 'N';
}

void CaseACocher::afficher(Fenetre& f) const
{
    this->c.afficher(f);
	this->dessiner(f, this->c.couleur());
}

void CaseACocher::effacer(Fenetre& f) const
{
    this->c.effacer(f);
	this->dessiner(f, f.couleurFond());
}

void CaseACocher::dessiner(Fenetre f, Couleur color) const
{
	if(this->estActif)
	{
		f.choixCouleurTrace(color);
		f.traceLigne(this->c.coordX(), this->c.coordY(), this->c.coordX()+this->c.cote(), this->c.coordY()+this->c.cote());
		f.traceLigne(this->c.coordX()+this->c.cote(), this->c.coordY(), this->c.coordX(), this->c.coordY()+this->c.cote());
	}
}
