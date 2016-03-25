#include "FenetreDessin.h"

FenetreDessin::FenetreDessin(const char* titre, int largeur, int hauteur, int x, int y, int r, int v, int b, int largeurMarge) :
    Fenetre(titre, largeur+largeurMarge, x, y, r, v, b),
    largeurMarge(largeurMarge),
    nbElements(0)
{
    this->choixCouleurTrace(0, 0, 0);
    this->traceLigne(largeur+1, 0, largeur+1, 0);
}

FenetreDessin::~FenetreDessin()
{
    for(int i=0; i<MAXTAB; i++)
    {
        delete [] this->elements;
    }
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
    if(numCase<MAXTAB+1)
    {
        delete this->elements[numCase];

        for(int i=numCase; i<MAXTAB+1; i++)
        {
            elements[numCase] = elements[numCase+1];
        }
    }
}

int FenetreDessin::touche(int x, int y) const
{
    for(int i=0; i<nbElements; i++)
    {
        if(0==0) // TODO
            return i;
        else
            return -1;
    }
}

