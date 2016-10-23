#include "CaseACocher.h"

CaseACocher::CaseACocher(const CaseACocher& source) :
    Carre(source),
    estActif(source.estActif){
}

CaseACocher::CaseACocher() :
    Carre(),
    estActif(false){
}

CaseACocher::CaseACocher(int x, int y, int longueur, Couleur color, char estActif) :
    Carre(x, y, longueur, color),
	estActif(estActif=='C'){
}

CaseACocher::CaseACocher(Carre pc, char pestActif) :
    Carre(pc),
    estActif(pestActif == 'C'){
}

void CaseACocher::definirCadre(int x, int y, int longueur, Couleur couleur)
{
    this->placer(x, y);
    this->dimensionner(longueur);
    this->definirCouleur(couleur);
}

Carre CaseACocher::cadre() const
{
    return *this;
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
    this->Carre::afficher(f);
	this->dessiner(f, this->Carre::couleur());
}

void CaseACocher::effacer(Fenetre& f) const
{
    this->Carre::effacer(f);
	this->dessiner(f, f.couleurFond());
}

void CaseACocher::dessiner(Fenetre& f, Couleur color) const
{
	if(this->estActif)
	{
		f.choixCouleurTrace(color);
		f.traceLigne(this->Carre::coordX(), this->Carre::coordY(), this->Carre::coordX()+this->Carre::cote(), this->Carre::coordY()+this->Carre::cote());
		f.traceLigne(this->Carre::coordX()+this->Carre::cote(), this->Carre::coordY(), this->Carre::coordX(), this->Carre::coordY()+this->Carre::cote());
	}
}
