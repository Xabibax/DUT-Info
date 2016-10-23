#include <iostream>
#include "fichierTexte.h"
#include "sousProgrammes.h"

using namespace std;

int main()
{
    UnFichierTexte ficE;        // fichier de texte à lire
    string nomSystemeFicE ;     // nom système du fichier à lire
    char choix ;

    do
    {
        // afficher menu
        cout << "---  PLUVIOMETRIE  ---" << endl<< endl;
        cout << "C) Choisir un fichier de pluviometrie" << endl;
        cout << "S) moyenne pluviometrique SIMPLE" << endl;
        cout << "A) moyenne pluviometrique avec ARRET des calculs si levees d'exception"<< endl;
        cout << "L) moyenne pluviometrique avec production d'un fichier LOG si levees d'exception"<< endl;
        cout << "Q) Quitter"<< endl;

       // Saisie-cerif reponse >> choix
        do
        {
            cout << endl << "votre choix ? " ;
            cin >> choix;
            cout << " " << endl;
        }
        while (!
                ((toupper(choix) == 'Q')||(toupper(choix) == 'C')||
                 (toupper(choix) == 'S')||(toupper(choix) == 'A')||(toupper(choix) == 'L'))
              );

        // choix >> triater action demandee
        switch (toupper(choix))
        {
        case 'C' :
            // C.- Choisir un fichier de pluviometrie
            //     saisie du nom système du fichier concerné
            cout << "C - Choisir un fichier de pluviometrie" << endl;
            cout << "--------------------------------------" << endl;
            cout << "nom du fichier a utiliser : ";
            cin >> nomSystemeFicE;
            break;
        case 'S' :
            // S.- Calcul et affichage d'une moyenne pluviometrique SIMPLE
            //     cad SANS protection contre d'eventuelles levees d'exception
            //     dues à des donnees non valides dans le fichier = exo 3 feuille TD n°5
            cout << endl << endl << "S) moyenne pluviometrique SANS protection contre d'eventuelles" << endl;
            cout <<                 "   levees d'exception dues a des donnees non conformes" << endl;            cout <<                 "------------------------------------------------" << endl;
            cout <<                 "--------------------------------------------------------------" << endl;
            calculMoyenneSimple(nomSystemeFicE) ;
            break;
        case 'A' :
            // A.- Calcul et affichage d'une moyenne pluviometrique ou bien ARRET
            //     des eventuelles levees d'exception dues à des donnees non valides
            //     dans le fichier = exo 1 feuille TD n°6
            cout << endl << endl << "A) moyenne pluviometrique ou ARRET des calculs" << endl;
            cout <<                 "   si levees d'exception dues a des donnees non conformes" << endl;            cout <<                 "------------------------------------------------" << endl;
            cout <<                 "------------------------------------------------------" << endl;
            calculMoyenneOuArret(nomSystemeFicE) ;
            break;
         case 'L' :
            // L.- Calcul et affichage d'une moyenne pluviometrique ou bien
            //     création d'un fichier LOG où seront consignées les erreurs dues à
            //     d'eventuelles levees d'exception dues à des donnees non valides
            //     dans le fichier = exo 1 feuille TD n°6
            cout << endl << endl << "L) moyenne pluviometrique ou production d'un fichier LOG" << endl;
            cout <<                 "   si levees d'exception dues a des donnees non conformes" << endl;            cout <<                 "------------------------------------------------" << endl;
            cout <<                 "------------------------------------------------------" << endl;
            calculMoyenneOuFichierLog(nomSystemeFicE) ;
            break;
        }

        cout << endl << endl;

    }
    while ( !(toupper(choix) == 'Q'));
    cout << endl << endl << "...au revoir..." << endl;
    return 0;
}
