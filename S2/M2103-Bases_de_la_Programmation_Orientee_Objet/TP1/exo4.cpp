#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    int b, x, y;

    unsigned short int tabX[10000]; //abscisses
    unsigned short int tabY[10000]; //ordonnées
    unsigned short int i=0;

    f.apparait("Exercice Bonus", 800, 800, 0, 0, 65535, 0, 0);

    s.associerA(f);

    while (!s.testeBoutons(x,y,b)); //attendre un clic pour démarrer les traitements

    while(!(b==3))
    {
        if(b==1) //si on fait clic gauche -> nouveau point (et trait si plus de deux points)
        {
            f.choixCouleurTrace(0, 0, 0);

            tabX[i]=x;
            tabY[i]=y;

            if((0<i) && (i<10000)) //pour tracer un trait il faut deux points (i<0) et ne peut en placer que 50 (i<50 avec le décalage du tab qui commence à 0)
                f.traceLigne(tabX[i-1],tabY[i-1],tabX[i],tabY[i],1); //on trace un trait noir entre les deux derniers points
            else if(i==0) //on met le if pour éviter de faire des points quand on a dépassé i=49
                f.traceArc(tabX[i],tabY[i],1,1,0,360,1); //pour matérialiser le premier point on dessine un cercle de diametre 1

            if (i < 10000) //une fois tous les traits dessinés on arrête de se déplacer dans le tab, en attendant un clic M ou D
                i+=1; //on incrémente i
        }
        else if(b==2) //si on fait clic milieu -> supprimer point (et trait si plus de deux points)
        {
            f.choixCouleurTrace(f.couleurFond());

            if (i > 0) //quand i vaut 0 on est au début du tableau de mémoire des coordonées -> on ne décrémente plus
                i-=1; //on décrémente i

            if((0<i) && (i<10000)) //même chose que pour le trait noir
                f.traceLigne(tabX[i-1],tabY[i-1],tabX[i],tabY[i],1); //on dessine en blanc par dessus l'ancien trait noir
            else if(i==0) //on ne dessine plus de point blanc quand il n'y a plus de points noirs
                f.traceArc(tabX[i],tabY[i],1,1,0,360,1); //pour supprimer le premier point on dessine un cercle de diametre 1 en blanc
        }

        s.testeBoutons(x,y,b); //on attend un autre clic
    }

    f.disparait();

    return 0;
}
