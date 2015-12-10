/*
 Programme : TriangleDePascal
 But : Calculer et afficher un triangle de Pascal en fonction du degré saisi par l'utilisateur.
 Date de création : 29/10/15
 Date de dernière modification : 10/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

// Déclaration des sous-programmes
void determinerTriangle(unsigned short int nbCases);
// But : Déterminer et afficher les valeurs d'un triangle de Pascal

int main()
{
    // VARIABLE
    unsigned short int tailleTab; // La taille du tableau


    // TRAITEMENT

    // (clavier) >> SaisirTailleTab >> tailleTab
    do
    {
        cout << "Saisissez le degre du triangle (max.12) : ";
        cin >> tailleTab;
    }
    while (!(tailleTab>0 && tailleTab<12));

    // Appel de la procédure determinerTriangle
    determinerTriangle(tailleTab);

    return 0;
}

// Définition des sous-programmes
void determinerTriangle(unsigned short int nbCases)
{
    unsigned short int ligne; // Le nombre de ligne qui sera associé à nbCases
    unsigned short int colonne; // Le nombre de colonne qui sera associé à nbCases

    unsigned int trianglePascal[nbCases][nbCases]; // Création du triangle de pascal

    // trianglePascal, nbCases >> CalculerTriangle >> trianglePascal
    for (ligne=0; ligne<=nbCases-1; ligne++)
    {
        trianglePascal[ligne][ligne]=1;
        trianglePascal[ligne][0]=1;

        for (colonne=1; colonne<ligne; colonne++)
        {
            trianglePascal[ligne][colonne] = trianglePascal[ligne-1][colonne] + trianglePascal[ligne-1][colonne-1];
        }
    }

    // nbCases >> AfficherDegre >> (écran)
    cout << "Triangle de Pascal de degre " << nbCases << " : ";
    cout << endl;

    // trianglePascal, ligne, colonne, nbCases >> DeterminerAffichage >> (écran)
    for (ligne=0; ligne<=nbCases-1; ligne++)
    {
        if (ligne<=9)
        {
            cout << " N= " << ligne;
        }
        else
        {
            cout << " N=" << ligne;
        }

        for (colonne=0; colonne<=ligne; colonne++)
        {
            if (trianglePascal[ligne][colonne] < 10)
            {
                cout << "    " << trianglePascal[ligne][colonne];
            }
            else
            {
                if ((trianglePascal[ligne][colonne] >= 10) && (trianglePascal[ligne][colonne] < 100))
                {
                    cout << "   " << trianglePascal[ligne][colonne];
                }
                else
                {
                    if ((trianglePascal[ligne][colonne] >= 100) && (trianglePascal[ligne][colonne] < 1000))
                    {
                        cout << "  " << trianglePascal[ligne][colonne];
                    }
                    else
                    {
                        cout << " " << trianglePascal[ligne][colonne];
                    }
                }
            }
        }

        cout << endl;
    }
}
