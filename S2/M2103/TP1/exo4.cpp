#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    int b, x, y;

    f.apparait("Exo 3", 200, 200);
    s.associerA(f);

    f.choixCouleurTrace(0,65535,65535);

    f.afficheImage("firefox-logo-200x200.png");

    while(!s.testeBoutons(x, y, b)){}

    while(b!=3)
    {
        if(b==1)
        {

        }

        while(!s.testeBoutons(x, y, b))
        {

        }
    }

    f.disparait();

    return 0;
}
