/*
 Programme : NumeroDeGroupeDeTD
 But :  Détermine et affiche le numéro de groupe de TD en fonction du numéro de groupe de TP saisi par l'utilisateur.
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
    unsigned short int numeroGroupeTP; // Le numero du groupe de TP saisie par l'utilisateur
    unsigned short int numeroGroupeTD; // Le numero du groupe de TD calculé par le programme


    // TRAITEMENT

    // (clavier) > SaisirNumeroGroupeTP > numeroGroupeTP
    cout << "Saisissez votre numero de TP : ";
    cin >> numeroGroupeTP;

    // numeroGroupeTP > DeterminerNumeroGroupeTD > numeroGroupeTD
    if (numeroGroupeTP <= 0 || numeroGroupeTP > 6)
    {
        cout << "Erreur: le numero de TP saisi est invalide" << endl;
    }
    else
    {
        switch (numeroGroupeTP)
        {
            case 1:
                numeroGroupeTD = 1;
                break;
            case 2:
                numeroGroupeTD = 1;
                break;
            case 3:
                numeroGroupeTD = 2;
                break;
            case 4:
                numeroGroupeTD = 2;
                break;
            case 5:
                numeroGroupeTD = 3;
                break;
            case 6:
                numeroGroupeTD = 3;
                break;
        }

        // numeroGroupeTD > AfficherNumeroGroupeTD > (ecran)
        cout << "Vous etes dans le TD " << numeroGroupeTD << endl;
    }

    return 0;
}
