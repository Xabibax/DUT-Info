#ifndef Fenetre_h
#define Fenetre_h

#include "Couleur.h"
#include "Image.h"

class Fenetre;

class Fenetre {

 public:

    Fenetre();

    Fenetre(const char *, int , int , int  = 0, int  = 0, int  = 65535, int  = 65535, int  = 65535);

    Fenetre(const Fenetre &);

    void apparait(const char * = "Sans nom", int  = 400, int  = 400, int  = 0, int  = 0, int  = 65535, int  = 655535, int  = 65535);

    void disparait();

    void deplacerEn(int , int );

    int hauteur() const ;

    int largeur() const ;

    int coordEnX() const ;

    int coordEnY() const ;

    Couleur couleurFond() const ;

    void choixCouleurTrace(int , int , int );

    void choixCouleurTrace(Couleur );

    void traceLigne(int , int , int , int , int  = 1);

    void traceArc(int , int , int , int , int  = 0, int  = 360, int  = 1);

    void remplitReclangle(int , int , int , int );

    void remplitEllipse(int , int , int , int );

    void ecrit(int , int , const char *);

    void ecrit(int , int , int );

    void afficheImage(const char *, int  = 0, int  = 0);

    void afficheImage(Image , int  = 0, int  = 0);

    void effacer();

    void delai(int );


 protected:

    Couleur coulFond;
};

#endif // Fenetre_h
