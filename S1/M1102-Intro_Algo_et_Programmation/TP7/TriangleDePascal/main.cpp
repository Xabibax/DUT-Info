/*
 Programme : TriangleDePascal
 But : Calculer et afficher un triangle de Pascal en fonction du degr� saisi par l'utilisateur.
 Date de cr�ation : 29/10/15
 Date de derni�re modification : 10/11/15
 Auteur : Valentin GRAGLIA
 Derni�re compilation : Linux
*/

#include <iostream>

using namespace std;

// D�claration des sous-programmes
void determinerTriangle(unsigned short int nbCases);
// But : D�terminer et afficher les valeurs d'un triangle de Pascal

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

    // Appel de la proc�dure determinerTriangle
    determinerTriangle(tailleTab);

    return 0;
}

// D�finition des sous-programmes
void determinerTriangle(unsigned short int nbCases)
{
    unsigned short int ligne; // Le nombre de ligne qui sera associ� � nbCases
    unsigned short int colonne; // Le nombre de colonne qui sera associ� � nbCases

    unsigned int trianglePascal[nbCases][nbCases]; // Cr�ation du triangle de pascal

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

    // nbCases >> AfficherDegre >> (�cran)
    cout << "Triangle de Pascal de degre " << nbCases << " : ";
    cout << endl;

    // trianglePascal, ligne, colonne, nbCases >> DeterminerAffichage >> (�cran)
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
