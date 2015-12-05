/*
  Programme : PariteDUnNombre
  But : Déterminer et afficher si un nombre saisi par l'utilisateur est pair ou pas
  Date de création : 04/11/15
  Date de dernière modification : 05/11/15
  Auteur : Valentin GRAGLIA
  Dernière compilation : Linux
*/
#include <iostream>

using namespace std;

// Déclaration des sous-programmes
string nombrePair(int nombre);
// But : Déterminer si nombre est pair ou pas

int main()
{
    // VARIABLE
    int nombreASaisir;


    // TRAITEMENT

    // (clavier) >> SaisirNombre >> nombreASaisir
    cout << "Saisissez un nombre : ";
    cin >> nombreASaisir;

    // nombreASaisir >> AfficherParite >> (écran)
    cout << nombreASaisir << " est un " << nombrePair(nombreASaisir) << endl;

    return 0;
}

// Définition des sous-programmes
string nombrePair(int nombre)
{
    return (nombre % 2 == 0) ? "nombre pair" : "nombre impair";
}
