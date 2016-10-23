#ifndef Cercle_h
#define Cercle_h

#include "Couleur.h"
#include "Fenetre.h"


class Cercle {

 public:

    void placer(int , int );

    void dimensionner(int );

    void definirCouleur(int , int , int );

    void definirCouleur(Couleur );

    int coordX() const ;

    int coordY() const ;

    int rayon() const ;

    Couleur couleur() const ;

    void afficher(Fenetre &) const ;

    void effacer(Fenetre &) const ;

    bool touche(int , int ) const ;


 protected:
    int x;
    int y;
    int rayon;
    void dessiner(Fenetre&, Couleur);

 public:

    /**
     * @element-type Couleur
     */
    Couleur myCouleur;
};

#endif // Cercle_h
