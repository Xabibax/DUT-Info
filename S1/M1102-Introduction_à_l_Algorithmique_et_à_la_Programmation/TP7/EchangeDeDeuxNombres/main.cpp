/*
 Programme : EchangeDeDeuxNombres
 But : Echanger deux nombres saisis par l'utilisateur � l'aide des proc�dures.
 Date de cr�ation : 29/10/15
 Date de derni�re modification : 08/11/15
 Auteur : Valentin GRAGLIA
 Derni�re compilation : Linux
*/

#include <iostream>

using namespace std;

// D�claration des sous-programmes
void echangerValeurs(double& nb1, double& nb2, double nb3);
// But : �changer deux valeurs

int main()
{
    // VARIABLES
    double nombre1; // Le premier nombre saisi par l'utilisateur
    double nombre2; // Le second nombre saisi par l'utilisateur
    double nombre3; // La variable interm�diaire pour �changer nombre1 et nombre2


    // TRAITEMENT

    // (clavier) >> Saisirnb1 >> nombre1
    cout << "Saisir le premier nombre : ";
    cin >> nombre1;

    // (clavier) >> Saisirnb2 >> nombre2
    cout << "Saisir le second nombre : ";
    cin >> nombre2;

    // Appel de la proc�dure echangerValeurs
    echangerValeurs(nombre1, nombre2, nombre3);

    // nombre1 >> AfficherNombre1 >> (�cran)
    cout << endl << "Premier nombre : " << nb1 << endl;

    // nombre2 >> AfficherNombre2 >> (�cran)
    cout << "Second nombre : " << nb2 << endl;

    return 0;
}

// D�finition des sous-programmes
void echangerValeurs(double& nb1, double& nb2, double nb3)
{
    // nombre2 >> CalculerNombre3 >> nombre3
    nb3 = nb2;

    // nombre1 >> CalculerNombre2 >> nombre2
    nb2 = nb1;

    // nombre3 >> CalculerNombre1 >> nombre1
    nb1 = nb3;
}
