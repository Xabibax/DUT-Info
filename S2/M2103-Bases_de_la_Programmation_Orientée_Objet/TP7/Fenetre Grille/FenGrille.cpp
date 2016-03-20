#include "FenGrille.h"

FenGrille::FenGrille(int colonne, int ligne) :
	Fenetre(),
	dimColonne(colonne),
	dimLigne(ligne) {
}

FenGrille::FenGrille(const char* nomFenetre, int largeurFen, int hauteurFen,
			int colonne, int ligne, int positionX, int positionY,
			int red, int green, int blue) :
	dimColonne(colonne),
	dimLigne(ligne)
{
	this->dessinerGrille();
}

FenGrille::FenGrille(const FenGrille& source) :
	Fenetre(source),
	dimColonne(source.dimColonne),
	dimLigne(source.dimLigne) {
}

void FenGrille::apparait(const char* nomFenetre, int largeurFen, int hauteurFen, int positionX, int positionY, int red, int green, int blue)
{
	this->Fenetre::apparait(nomFenetre, largeurFen, hauteurFen, positionX, positionY, red, green, blue);
	this->dessinerGrille();
}

void FenGrille::effacer()
{
	this->Fenetre::effacer();
	this->dessinerGrille();
}

void FenGrille::afficherCase(CaseACocher caseAff)
{
	CaseACocher* obj = new CaseAvecTexte();
	obj->afficher(*this);
}

void FenGrille::dessinerGrille()
{
	this->choixCouleurTrace(45000,45000,45000);

	for (int i = dimColonne ; i < this->largeur() ; i += dimColonne)
        	this->traceLigne(i, 0, i, this->hauteur());

	for (int i = dimLigne ; i < this->hauteur() ; i += dimLigne)
        	this->traceLigne(0, i, this->largeur(), i);
}
