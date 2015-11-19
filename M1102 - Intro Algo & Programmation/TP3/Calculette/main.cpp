/*
 Programme : Calculette
 But :  Determine l'opération à appliquer en fonction de val1, val2 et oper saisies par l'utilisateur.
 Date de création : 24/09/15
 Date de dernière modification : 27/10/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    double val1; // Le premier membre de l'opération saisi par l'utilisateur
    double val2; // Le second membre de l'opération saisi par l'utilisateur
    char oper; // L'opération saisie par l'utilisateur
    double resultat; // Le resultat calculée de val1 oper val2
    bool erreur = false; // La variable utilisée si oper n'est pas valide


    // TRAITEMENT

    // (clavier) > SaisirNombre1 > val1
    cout << "Saisissez un premier nombre : ";
    cin >> val1;

    // (clavier) > SaisirNombre2 > val2
    cout << "Saisissez un second nombre : ";
    cin >> val2;

    // (clavier) > SaisirOperation > oper
    cout << "Saisissez une operation : ";
    cin >> oper;

    // oper, val1, val2 > CalculerResultat > resultat, erreur
    switch (oper)
    {
        case '+':
            resultat = val1 + val2;
            break;
        case '-':
            resultat = val1 - val2;
            break;
        case '*':
            resultat = val1 * val2;
            break;
        case '/':
            resultat = val1 / val2;
            break;
        default:
            erreur = true;
            break;
    }

    // erreur, val1, val2, oper > AfficherResultat > (écran)
    if (erreur)
    {
        cout << "Erreur: l'operation saisie est invalide." << endl;
    }
    else
    {
        cout << val1 << oper << val2 << " = " << resultat << endl;
    }

    return 0;
}
