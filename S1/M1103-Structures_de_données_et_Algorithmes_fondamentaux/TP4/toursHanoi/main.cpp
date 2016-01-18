#include <iostream>
#include "pile.h"
#include "sousProgrammes.h"

int main()
{

    // Dictionnaire des �l�ments

    UnePile t1; // pile d'entiers, chaque valeur correspond � la taille d'un disque
    UnePile t2; // pile d'entiers, chaque valeur correspond � la taille d'un disque
    UnePile t3;// // pile d'entiers, chaque valeur correspon � la taille d'un disque
    unsigned int nbDisques;    // nbre de disques
    const unsigned int BORNE_INF = 3;   // nbre minimum autoris� de disques
    const unsigned int BORNE_SUP = 9;   // nbre maximum autoris� de disques
    unsigned nbreCoups = 0;     // nbre de coups effectu�s (facultatif)

    // Initialisation des piles
    initialiser (t1);
    initialiser (t2) ;
    initialiser (t3) ;

    // (clavier), BORNE_SUP, BORNE_INF >> saisie du nbre de disques >> nbDisques
    do
    {
        cout << "Entrer le nbre de disques de la tour de Hanoi (entre " << BORNE_INF << " et " << BORNE_SUP << ") : ";
        cin >> nbDisques;
    }
    while (!((nbDisques >=BORNE_INF) && (nbDisques <= BORNE_SUP)));


    // N, t1 >> empiler les disques sur la tour de d�part
    for (unsigned int i = nbDisques; i >= 1; i--)
    {
        empiler (t1, i);
    }

    // Affichage contenus des 3 piles avat le d�but des d�plaements
    cout << "t1 = { " ;
    afficherTour (t1);
    cout << " }    t2 = { " ;
    afficherTour (t2) ;
    cout << " }    t3 = { " ;
    afficherTour (t3) ;
    cout << " } " << endl;

    cout << "---------------------------------------------------" << endl << endl;

    // t1, t2, t3 >> D�placer >> t1, t2, t3
    while (true)
    {
        if (estVide(t1) && estVide(t2))
            break;

        // d�placer petit disque, dan sle sens des aiguilles d'une montre
        deplacerPetit (t1, t2, t3);
        nbreCoups = nbreCoups +1;
        //cout << nbreCoups << ".a :  " ;
        cout << "t1 = { " ;
        afficherTour (t1);
        cout << " }    t2 = { " ;
        afficherTour (t2) ;
        cout << " }    t3 = { " ;
        afficherTour (t3) ;
        cout << " } " << endl;

        if (estVide(t1) && estVide(t2))
            break;

        // d�placer l'autre disque
        deplacerAutre (t1, t2, t3);
        //cout << nbreCoups << ".b :  " ;
        cout << "t1 = { " ;
        afficherTour (t1);
        cout << " }    t2 = { " ;
        afficherTour (t2) ;
        cout << " }    t3 = { " ;
        afficherTour (t3) ;
        cout << " } " << endl << endl;
    }


    // Affichage contenus des 3 piles apr�s les d�placements
    cout << endl << "---------------------------------------------------" << endl;;
    cout << "t1 = { " ;
    afficherTour (t1);
    cout << " }    t2 = { " ;
    afficherTour (t2) ;
    cout << " }    t3 = { " ;
    afficherTour (t3) ;
    cout << " } " << endl;


    return 0;
}
