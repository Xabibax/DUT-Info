#ifndef BOUTON_AVEC_TEXTE_H
#define BOUTON_AVEC_TEXTE_H

#include "Couleur.h"
#include "Fenetre.h"
#include "Cercle.h"
#include "Bouton.h"

class BoutonAvecTexte : public Bouton{

protected:
	char *texte;
	void afficherTexte(Fenetre& , Couleur) const;
	void affecterTexte(const char*);

public:
    BoutonAvecTexte(Bouton = Bouton(), const char * = "Sans texte");
    BoutonAvecTexte(const BoutonAvecTexte&);
    ~BoutonAvecTexte();
    void definirTexte(const char*);
    void afficher(Fenetre&) const;
	void effacer(Fenetre&) const;
};

#endif // BOUTON_AVEC_TEXTE_H
