#include "Bouton.h"

Bouton::Bouton(const Bouton& source) :
    c(source.c),
    estActif(source.estActif){
}

Bouton::Bouton() :
    c(),
    estActif(false){
}

Bouton::Bouton(int x, int y, int r, Couleur color, char estActif) :
    c(x, y, r, color),
	estActif(estActif=='C'){
}

Bouton::Bouton(Cercle pc, char pestActif) :
    c(pc),
    estActif(pestActif == 'C'){
}

void Bouton::definir(int x, int y, int t, int r, int v, int b)
{
    this->c.placer(x, y);
    this->c.dimensionner(t);
    this->c.definirCouleur(r, v, b);
}

void Bouton::definir(int x, int y, int t, Couleur color)
{
    this->c.placer(x, y);
    this->c.dimensionner(t);
    this->c.definirCouleur(color);
}

Cercle Bouton::circle() const
{
    return this->c;
}

void Bouton::definirEtat(char lettre)
{
    this->estActif = (lettre=='C') ? true : false;
}

char Bouton::etat() const
{
    return (this->estActif) ? 'C' : 'N';
}

Couleur Bouton::couleur() const
{
    return this->c.couleur();
}

void Bouton::afficher(Fenetre& f) const
{
    this->c.afficher(f);
	this->dessiner(f, this->c.couleur());
}

void Bouton::effacer(Fenetre& f) const
{
    this->c.effacer(f);
	this->dessiner(f, f.couleurFond());
}

void Bouton::dessiner(Fenetre f, Couleur color) const
{
	if(this->estActif)
	{
		f.choixCouleurTrace(color);
		f.remplitEllipse(this->c.coordX() - this->c.rayon()/2,
                         this->c.coordY() - this->c.rayon()/2,
                         this->c.rayon(),
                         this->c.rayon());
	}
}
