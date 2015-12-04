/*
 Programme : RepresentationEtManipulationDeCartesAJouer
 But : Déterminer et afficher la carte la plus forte parmi deux cartes prédéfinies.
 Date de création : 15/10/15
 Date de dernière modification : 28/10/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    enum Valeur {deux = 2, trois, quatre, cinq, six, sept, huit, neuf, dix, valet, dame, roi, as};
    // l'énumération Valeur contenant toutes les valeurs possibles

    enum Couleur {coeur, pique, trefle, carreau};
    // l'énumération Couleur contenant toutes les couleurs possibles

    struct Carte
    {
        Valeur valeur; // La valeur de la carte prédéfinie
        Couleur couleur; // La couleur de la carte prédéfinie
    };

    Carte carte1; // La premiere carte prédéfinie
    Carte carte2; // La seconde carte prédéfinie
    Carte cartePlusForte; // La carte la plus forte déterminée parmi carte1 et carte2

    carte1.valeur = cinq; // La variable contenant la valeur de carte1
    carte1.couleur = carreau; // La variable contenant la couleur de carte1
    carte2.valeur = dame; // La variable contenant la valeur de carte2
    carte2.couleur = pique; // La variable contenant la couleur de carte2

    string valeurGagnant; // Variable utilisée pour afficher en toute lettre la valeur de la carte la plus forte
    string couleurGagnante; // Variable utilisée pour afficher en toute lettre la couleur de la carte la plus forte


    // TRAITEMENT

    // carte1, carte2 > DeterminerCarteLaPlusForte > cartePlusForte
    if (carte1.valeur < carte2.valeur)
    {
        cartePlusForte = carte2;
    }
    else
    {
        cartePlusForte = carte1;
    }

    // cartePlusForte > DeterminerAffichage > valeurGagnante, couleurGagnante
    switch (cartePlusForte.valeur)
    {
    case 2:
        valeurGagnante = "Deux";
        break;
    case 3:
        valeurGagnante = "Trois";
        break;
    case 4:
        valeurGagnante = "Quatre";
        break;
    case 5:
        valeurGagnante = "Cinq";
        break;
    case 6:
        valeurGagnante = "Six";
        break;
    case 7:
        valeurGagnante = "Sept";
        break;
    case 8:
        valeurGagnante = "Huit";
        break;
    case 9:
        valeurGagnante = "Neuf";
        break;
    case 10:
        valeurGagnante = "Dix";
        break;
    case 11:
        valeurGagnante = "Valet";
        break;
    case 12:
        valeurGagnante = "Dame";
        break;
    case 13:
        valeurGagnante = "Roi";
        break;
    case 14:
        valeurGagnante = "As";
        break;
    }

    switch (cartePlusForte.couleur)
    {
    case 0:
        couleurGagnante = "Coeur";
        break;
    case 1:
        couleurGagnante = "Pique";
        break;
    case 2:
        couleurGagnante = "Trefle";
        break;
    case 3:
        couleurGagnante = "Carreau";
        break;
    }

    // valeurGagnante, couleurGagnante > AfficherCartePlusForte > (écran)
    cout << "Carte la plus forte : " << valeurGagnante << " de " << couleurGagnante << endl;

    return 0;
}
