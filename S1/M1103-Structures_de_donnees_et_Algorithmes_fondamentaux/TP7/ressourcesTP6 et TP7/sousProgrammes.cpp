#include <iostream>
#include "sousProgrammes.h"
#include "fichierTexte.h"

using namespace std;

void calculMoyenneSimple (string nomSysFic)
{
    cout << "calculMoyenneSimple" << endl;
}

void calculMoyenneOuArret (string nomSysfic)
{
    UnFichierTexte fichier; // nom logique donner au fichier pour etre utiliser dans le sous-programe
    bool erreurOuverture=false; // booleen qui indique si il y a eu une erreur d'ouverture
    bool erreurLecture=false; // booléen qui indique si il y a eu une erreur de lecture
    unsigned int nbNombre=0; // compte le nombre de relevers
    float somme=0; // somme des relevers
    float moyenne;
    float relever; // relecer qui sont dans les fichiers
    bool fdf; // booléen de fin de fichier

    // Preparation des fichiers
    // associer nom
    associer(fichier,nomSysfic);

    //ouvrir fichier
    try
    {
        ouvrir(fichier, lecture);

    }
    catch (string& s)
    {
        erreurOuverture=true;

        cout << endl << "au revoir ....";
    }
    // Traitement a effectuer
    if (!erreurOuverture)
    {
        while (true)
        {
            try
            {
                lireMot(fichier, relever, fdf);
                if (fdf)
                {
                    break;
                }
            }


            catch (string& s)
            {
                erreurLecture=true;
                break;
                cout << endl << "au revoir ....";

            }
            nbNombre++;
            somme=somme+relever;
        }

        if(nbNombre==0)
        {
            cout << "Le fichier est vide";
        }
        else if(!erreurLecture)
        {
            moyenne=somme/nbNombre;
        }

        try
        {
            fermer(fichier);
        }
        catch (string& s)
        {
            if (s=="erreurDeStatut")
            {
                cout << "Le fichier n'est pas ouvert";
            }
            else
            {
                cout << "La fermeture n'a pas pu se faire";
            }
        }
        cout << endl<< "La moyenne de ce mois est : "<< moyenne << "mm de pluie";
    }


}


void calculMoyenneOuFichierLog (string nomSysfic)
{
    cout << "calculMoyenneOuFichierLog" << endl;
}
