#ifndef BoutonTexte_h
#define BoutonTexte_h

#include "Bouton.h"

class BoutonTexte;

class BoutonTexte : public Bouton {

 public:

    BoutonTexte();

    BoutonTexte(Bouton , const char *);

    BoutonTexte(const BoutonTexte &);

    ~BoutonTexte();

    void afficher() const ;

    void effacer() const ;

    void definirTexte(const char *);


 protected:
    char *texte;
    void affecterTexte(const char *);
    void afficherTexte(Fenetre&, Couleur) const;
};

#endif // BoutonTexte_h
