#include "FenetreDessin.h"

FenetreDessin::FenetreDessin(const char* titre, int largeur, int hauteur, int x, int y, int r, int v, int b, int largeurMarge) :
    Fenetre(titre, largeur+largeurMarge, hauteur, x, y, r, v, b),
    largeurMarge(largeurMarge),
    nbElements(0)
{
    this->choixCouleurTrace(0, 0, 0);
    this->traceLigne(largeur+1, 0, largeur+1, hauteur);
}

FenetreDessin::~FenetreDessin()
{
    delete [] this->elements;
}

bool FenetreDessin::estDansLaFenetre(int x, int y) const
{
    if(x>0 && x<=this->largeur() && y>0 && y<=hauteur())
        return true;
    else
        return false;
}

void FenetreDessin::ajouter(ElementGraphique* eg)
{
    if(this->nbElements<MAXTAB)
    {
        this->elements[this->nbElements] = eg;
        this->nbElements++;
        eg->afficher(*this);
    }
    else
        delete eg;
}

void FenetreDessin::enlever(int numCase)
{
    if(numCase>=0 && numCase<MAXTAB)
    {
        this->elements[numCase]->effacer(*this);
        delete this->elements[numCase];

        for(int i=numCase; i<this->nbElements-1; i++)
        {
            this->elements[numCase] = this->elements[numCase+1];
        }
        nbElements--;
    }
}

int FenetreDessin::touche(int x, int y) const
{
    for(int i=this->nbElements-1; i>=0; i--)
    {
        if(this->elements[i]->touche(x, y))
            return i;
    }
    return -1;
}

void FenetreDessin::effacer()
{
    this->choixCouleurTrace(65535, 65535, 65535);
    this->remplitRectangle(this->coordEnX(), this->coordEnY(), this->largeur(), this->hauteur());
}

int FenetreDessin::largeur() const
{
    return (this->Fenetre::largeur() - this->largeurMarge);
}

int FenetreDessin::largeurBoiteOutils() const
{
    return this->largeurMarge;
}

void FenetreDessin::disparait()
{
    delete [] this->elements;
    Fenetre::disparait();
}

void FenetreDessin::actualiser()
{
    this->effacer();
    for(int i=0; i<this->nbElements; i++)
        this->elements[i]->afficher(*this);
}

void FenetreDessin::definirCouleur(int pos, Couleur coul)
{
    if((pos>=0) && (pos<this->nbElements))
    {
        this->elements[pos]->definirCouleur(coul);
        this->actualiser();
    }
}

ElementGraphique* FenetreDessin::element(int pos)
{
    if((pos>=0) && (pos<this->nbElements))
        return this->elements[pos];
    return NULL;
}
