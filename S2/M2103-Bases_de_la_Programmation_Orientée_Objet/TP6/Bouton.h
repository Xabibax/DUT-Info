#ifndef Bouton_h
#define Bouton_h

#include "Cercle.h"
#include "Couleur.h"
#include "Fenetre.h"

class Bouton;

class Bouton : public Cercle {

 public:

    Bouton();

    Bouton(const Bouton &);

    Bouton(bool cercle, bool etat);

    void definir(int , int , int , int  = 0, int  = 0, int  = 0, bool  = false);

    void definir(int , int , int , Couleur  = Couleur(0,0,65535), bool  = false);

    void activer();

    void desactiver();

    bool actif() const ;

    void afficher(Fenetre &);

    void effacer(Fenetre &);


 protected:
    bool estActif;
    void dessiner(Fenetre&, Couleur);
};

#endif // Bouton_h
