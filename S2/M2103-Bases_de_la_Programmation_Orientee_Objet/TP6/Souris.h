#ifndef Souris_h
#define Souris_h

#include "Fenetre.h"

class Souris;

class Souris {

 public:

    Souris();

    Souris(const Souris &);

    void associerA(Fenetre &);

    void position(int &, int &, int &) const ;

    bool testeBoutons(int &, int &, int &) const ;
};

#endif // Souris_h
