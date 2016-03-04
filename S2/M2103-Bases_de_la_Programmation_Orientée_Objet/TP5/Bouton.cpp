#include "Bouton.h"

Bouton::Bouton(const Bouton& source) :
    Cercle(source),
    estActif(source.estActif){
}

Bouton::Bouton() :
    Cercle(),
    estActif(false){
}

Bouton::Bouton(int x, int y, int r, Couleur color, char estActif) :
    Cercle(x, y, r, color),
	estActif(estActif=='C'){
}

Bouton::Bouton(Cercle pc, char pestActif) :
    Cercle(pc),
    estActif(pestActif == 'C'){
}

void Bouton::definir(int x, int y, int t, int r, int v, int b)
{
    this->placer(x, y);
    this->dimensionner(t);
    this->definirCouleur(r, v, b);
}

void Bouton::definir(int x, int y, int t, Couleur color)
{
	this->definir(x, y, t, color.rouge(), color.vert(), color.bleu());
}

Cercle Bouton::circle() const
{
    return *this;
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
    return this->couleur();
}

void Bouton::afficher(Fenetre& f) const
{
    this->Cercle::afficher(f);
	this->dessiner(f, this->Cercle::couleur());
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
