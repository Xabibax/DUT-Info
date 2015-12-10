/*
 Programme : RepresentationEtManipulationDeFraction
 But : Calculer et afficher la somme simplifiée de deux fractions saisies par l'utilisateur.
 Date de création : 15/10/15
 Date de dernière modification : 28/10/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    //VARIABLES

    struct Fraction
    {
        unsigned int num; // Le numérateur de la fraction prédéfinie
        unsigned int den; // Le dénominateur de la fraction prédéfinie
    };

    Fraction f1; // La première fraction saisie par l'utilisateur
    Fraction f2; // La seconde fraction saisie par l'utilisateur
    Fraction fSomme; // La fraction calculée de la somme de f1 par f2
    Fraction fReduite; // La fraction calculée réduite de fSomme
    unsigned short int pgcd; // La variable utilisée pour déterminer fReduite


    //TRAITEMENT

    // (clavier) > Saisirf1.num > f1.num
    cout << "Entrer le numerateur de la fraction 1 : ";
    cin >> f1.num;

    // (clavier) > Saisirf1.den > f1.den
    cout << "Entrer le denominateur de la fraction 1 : ";
    cin >> f1.den;

    // (clavier) > Saisirf2.num > f2.num
    cout << endl << "Entrer le numerateur de la fraction 2 : ";
    cin >> f2.num;

    // (clavier) > Saisirf2.den > f2.den
    cout << "Entrer le denominateur de la fraction 2 : ";
    cin >> f2.den;

    // Mettre sur le même dénominateur si nécessaire.
    if (f1.den == f2.den)
    {
        fSomme.den = f1.den;
        fSomme.num = f1.num + f2.num;
    }
    else
    {
        fSomme.den = f1.den * f2.den;
        fSomme.num = f1.num * f2.den + f2.num * f1.den;
    }

    // Initialiser la valeur du pgcd en prenant le plus petit entre 'fSomme.num' et 'fSomme.den'.
    if (fSomme.num > fSomme.den)
    {
        pgcd = fSomme.den;
    }
    else
    {
        pgcd = fSomme.num;
    }

    // Réduire la fraction.
    while (!((fSomme.den % pgcd == 0) && (fSomme.num % pgcd == 0)))
    {
        pgcd = pgcd - 1;
    }

    // fSomme.num, fSomme.den, pgsc > CalculerfReduite > fReduite.num, fReduite.den
    fReduite.num = fSomme.num / pgcd;
    fReduite.den = fSomme.den / pgcd;

    // fReduite.num, fReduite.den > AfficherfReduite > (écran)
    cout << endl << endl << "f1 + f2 = " << fReduite.num << "/" << fReduite.den << endl;

    return 0;
}
