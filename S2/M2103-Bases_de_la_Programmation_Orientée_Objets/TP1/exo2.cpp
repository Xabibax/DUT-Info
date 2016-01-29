#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    int b, x, y;
    int param=100;

    f.apparait("Exo 2", 200, 200);
    s.associerA(f);

    f.choixCouleurTrace(0,0,65535);

    for(int coord=50; coord<=90; coord+=10)
    {
        f.traceArc(coord, coord, param, param);
        param-=20;
    }

    f.delai(5000);

    f.disparait();

    return 0;
}
