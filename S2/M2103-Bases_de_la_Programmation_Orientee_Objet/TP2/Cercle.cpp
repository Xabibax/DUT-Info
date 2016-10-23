#include "Cercle.h"

void Cercle::placer(int cx, int cy)
{
    this->x = cx;
    this->y = cy;
}

void Cercle::dimensionner(int r)
{
    this->r = r;
}

void Cercle::definirCouleur(int r, int v, int b)
{
    this->color.changeCouleur(r, v, b);
}

void Cercle::definirCouleur(Couleur c)
{
    this->color.changeCouleur(c.rouge(), c.vert(), c.bleu());
}

int Cercle::coordX() const
{
    return this->x;
}

int Cercle::coordY() const
{
    return this->y;
}

int Cercle::rayon() const
{
    return this->r;
}

Couleur Cercle::couleur() const
{
    return this->color;
}

void Cercle::afficher(Fenetre& f) const
{
    f.choixCouleurTrace(this->color);
    f.traceArc(this->x - this->r,
               this->y - this->r,
               2*this->r,
               2*this->r);
}

void Cercle::effacer(Fenetre& f) const
{
    f.couleurFond();
    f.traceArc(this->x - this->r,
               this->y - this->r,
               2*this->r,
               2*this->r);
}

bool Cercle::touche(int x, int y) const
{
	return ((x>=this->x - this->r) && (x<=(this->x + this->r)) && (y>=this->y - this->r) && (y<=(this->y + this->r)));
}
