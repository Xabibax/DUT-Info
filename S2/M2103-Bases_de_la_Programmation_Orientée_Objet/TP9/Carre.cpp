#include "Carre.h"

Carre::Carre(const Carre& source) :
    x(source.x),
    y(source.y),
    longueur(source.longueur),
    color(source.color){
}

Carre::Carre() :
    x(10),
    y(10),
    longueur(20),
    color(0, 0, 0){
}

Carre::Carre(int px, int py, int plongueur, Couleur pcolor) :
    x(px),
    y(py),
    longueur(plongueur),
    color(pcolor){
}

void Carre::placer(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Carre::coordX() const
{
    return this->x;
}

int Carre::coordY() const
{
    return this->y;
}

void Carre::dimensionner(int l)
{
    this->longueur = l;
}

int Carre::cote() const
{
    return this->longueur;
}

void Carre::definirCouleur(Couleur color)
{
    this->color.changeCouleur(color.rouge(),color.vert(),color.bleu());
}

void Carre::definirCouleur(int r, int v, int b)
{
    this->color.changeCouleur(r, v, b);
}

Couleur Carre::couleur() const
{
    return this->color;
}

void Carre::afficher(Fenetre& f) const
{
    this->dessiner(f, this->color);
}

void Carre::effacer(Fenetre& f) const
{
	this->dessiner(f, f.couleurFond());
}

void Carre::dessiner(Fenetre& f, Couleur c) const
{
	f.choixCouleurTrace(c);
	f.traceLigne(this->x, this->y, this->x + this->longueur, this->y);
	f.traceLigne(this->x, this->y, this->x, this->y + this->longueur);
	f.traceLigne(this->x + this->longueur, this->y, this->x + this->longueur, this->y + this->longueur + 1);
	f.traceLigne(this->x, this->y + this->longueur, this->x + this->longueur, this->y + this->longueur);
}

bool Carre::touche(int x, int y) const
{
    return ((x>=this->x) && (x<=(this->x + this->longueur)) && (y>=this->y) && (y<=(this->y + this->longueur)));
}

string Carre::quiSuisJe() const
{
    return "Carre";
}
