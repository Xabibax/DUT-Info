/*
 Programme : RepresentationEtManipulationDeDate
 But : Déterminer la date la plus ancienne parmi deux dates prédéfinies.
 Date de création : 15/10/15
 Date de dernière modification : 11/11/15
 Auteur : Valentin GRAGLIA
 Dernière compilation : Linux
*/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLES
    enum Mois {janvier = 1, fevrier, mars, avril, mai, juin, juillet, aout, septembre, octobre, novembre, decembre};
    // l'énumérarion Mois contenant l'ensemble des mois de l'année

    struct Date
    {
        unsigned short int jour; // Le jour de la date prédéfinie
        Mois mois; // La variable mois qui est associée à l'énumérarion Mois
        short int annee; // L'année de la date prédéfinie
    };

    Date date1; // La première date prédéfinie
    Date date2; // La seconde date prédéinie
    Date datePlusAncienne; // La date la plus ancienne déterminée parmi date1 et date2
    bool egal = false; // Variable utilisée si date1 = date2

    date1.jour = 12; // La variable contenant le jour de la date1
    date1.mois = novembre; // La variable contenant le mois de la date1
    date1.annee = 1996; // La variable contenant l'année de la date1

    date2.jour = 23; // La variable contenant le jour de la date2
    date2.mois = juillet; // La variable contenant le mois de la date2
    date2.annee = 1998; // La variable contenant l'année de la date2


    // TRAITEMENT

    // date1, date2 > DéterminerDatePlusAncienne > datePlusAncienne, egal
    if (date1.annee < date2.annee)
    {
        datePlusAncienne = date1;
        // cout << "[DEBUG] date1_a" << endl;
    }
    else
    {
        if (date2.annee < date1.annee)
        {
            datePlusAncienne = date2;
            // cout << "[DEBUG] date2_a" << endl;
        }
        else
        {
            if (date1.mois < date2.mois)
            {
                datePlusAncienne = date1;
                // cout << "[DEBUG] date1_m" << endl;
            }
            else
            {
                if (date2.mois < date1.mois)
                {
                    datePlusAncienne = date2;
                    // cout << "[DEBUG] date2_m" << endl;
                }
                else
                {
                    if (date1.jour < date2.jour)
                    {
                        datePlusAncienne = date1;
                        // cout << "[DEBUG] date1_j" << endl;
                    }
                    else
                    {
                        if (date2.jour < date1.jour)
                        {
                            datePlusAncienne = date2;
                            // cout << "[DEBUG] date2_j" << endl;
                        }
                        else
                        {
                            egal = true;
                        }
                    }
                }
            }
        }
    }

    // egal, datePlusAncienne > DeterminerAffichage > (écran)
    if (egal)
    {
        cout << "Dates egales." << endl;
    }
    else
    {
        cout << "Date la plus ancienne : " << datePlusAncienne.jour << "/" << datePlusAncienne.mois << "/" << datePlusAncienne.annee << endl;
    }

    return 0;
}
