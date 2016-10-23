#ifndef Couleur_h
#define Couleur_h

class Couleur;
class Cercle;

class Couleur {

 public:

    Couleur(int  = 0, int  = 0, int  = 0);

    Couleur(const Couleur &);

    void changeCouleur(int , int , int );

    int rouge() const ;

    int vert() const ;

    int bleu() const ;

    Couleur();

 public:


    /**
     * @element-type Cercle
     */
    Cercle *myCercle;
};

#endif // Couleur_h
