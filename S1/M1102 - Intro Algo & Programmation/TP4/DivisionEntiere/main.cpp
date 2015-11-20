/*
 Programme : DivisionEntiere
 But : Calculer et afficher le quotient et le reste d'une division en fonction du dividende et du diviseur saisis par l'utilisateur.
 Date de création : 07/10/15
 Date de dernière modification : 28/10/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    unsigned short int dividende; // Le dividende saisi par l'utilisateur
    unsigned short int diviseur; // Le diviseur saisi par l'utilisateur
    unsigned int quotient = 0; // Le quotient calculé de la division
    unsigned int reste = 0; // Le reste calculé de la division


    // TRAITEMENT

    // (clavier) > SaisirDividende > dividende
    cout << "Saisissez le dividende : ";
    cin >> dividende;

    // (clavier) > SaisirDiviseur > diviseur
    cout << "Saisissez le diviseur : ";
    cin >> diviseur;

    // dividende > InitialiserReste > reste
    reste = dividende;

    // reste, diviseur > CalculerReste > reste
    // quotient, diviseur > CalculerQuotient > quotient
    while(!(reste <= diviseur))
    {
        reste = reste - diviseur;
        quotient = quotient + 1;
    }

    // quotient > AfficherQuotient > (écran)
    cout << "Quotient : " << quotient << endl;

    // reste > AfficherReste > (écran)
    cout << "Reste : " << reste << endl;

    return 0;
}
