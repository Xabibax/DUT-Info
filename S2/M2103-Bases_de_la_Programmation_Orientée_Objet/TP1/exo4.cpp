#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv)  //argc variable locale qui recoit le nombre d'arguments, **argv : liste arguments
{

    gtk_init(&argc, &argv);

    //VARIABLES

    Fenetre f;
    Souris s;
    int b, x, y; //bonton pressé G->1 M->2 D->1 / abscisse point / ordonnées point
    unsigned short int tabX[50]; //tableau qui contient les abscice des points
    unsigned short int tabY[50]; //ordonnées
    unsigned short int i=0; //indice de positionnement dans les tableaux

    //TRAITEMENTS

    f.apparait("Exercice Bonus",1000,1000); //fenêtre 1000x1000

    s.associerA(f); //associer souris et fenêtre

    while (!s.testeBoutons(x,y,b)); //attendre un clic pour démarrer les traitements

    while(!(b==3))  //tant qu'on ne fait pas clic droit on continu
    {
        if(b==1) //si on fait clic gauche -> nouveau point (et trait si plus de deux points)
        {
            f.choixCouleurTrace(0,0,0); //noir

            tabX[i]=x;
            tabY[i]=y;

            if((0<i) and (i<50)) //pour tracer un trait il faut deux points (i<0) et ne peut en placer que 50 (i<50 avec le décalage du tab qui commence à 0)
                f.traceLigne(tabX[i-1],tabY[i-1],tabX[i],tabY[i],1); //on trace un trait noir entre les deux derniers points
            else if(i==0) //on met le if pour éviter de faire des points quand on a dépassé i=49
                f.traceArc(tabX[i],tabY[i],1,1,0,360,1); //pour matérialiser le premier point on dessine un cercle de diametre 1

            if (i < 50) //une fois tous les traits dessinés on arrête de se déplacer dans le tab, en attendant un clic M ou D
            i+=1; //on incrémente i
        }
        else if(b==2) //si on fait clic milieu -> supprimer point (et trait si plus de deux points)
        {
            f.choixCouleurTrace(65535,65535,65535); //blanc

            if (i > 0) //quand i vaut 0 on est au début du tableau de mémoire des coordonées -> on ne décrémente plus
            i-=1; //on décrémente i

            if((0<i) and (i<50)) //même chose que pour le trait noir
                f.traceLigne(tabX[i-1],tabY[i-1],tabX[i],tabY[i],1); //on dessine en blanc par dessus l'ancien trait noir
            else if(i==0) //on ne dessine plus de point blanc quand il n'y a plus de points noirs
                f.traceArc(tabX[i],tabY[i],1,1,0,360,1); //pour supprimer le premier point on dessine un cercle de diametre 1 en blanc
        }

        s.testeBoutons(x,y,b); //on attend un autre clic
    }

    f.disparait(); //une fois terminé on efface la page

    return 0;
}
