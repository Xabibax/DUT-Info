/*
 Programme : ValidationDuSemestre
 But :  Détermine et affiche la validation éventuel du semestre en fonction des moyennes
        Informatique et Complémentaire saisies par l'utlisateur ainsi que de la moyenne Générale calculée.
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
    double moyenneInformatique; // La moyenne Informatique saisie par l'utilisateur
    double moyenneComplementaire; // La moyenne Complémentaire saisie par l'utilisateur
    double moyenneGenerale; // La moyenne Générale calculée
    bool validationSemestre = false; // La variable contenant la validation du semestre ou non


    // TRAITEMENT

    // (clavier) > SaisirMoyenneComplementaire > moyenneComplementaire
    cout << "Saisissez votre moyenne complementaire : ";
    cin >> moyenneComplementaire;

    // (clavier) > SaisirMoyenneInformatique > moyenneInformatique
    cout << "Saisissez votre moyenne en Info : ";
    cin >> moyenneInformatique;

    // moyenneComplementaire, moyenneInformatique > calculerMoyenneGenerale > moyenneGenerale
    moyenneGenerale = (moyenneComplementaire + moyenneInformatique) / 2;
    cout << "Moyenne generale : " << moyenneGenerale << "/20" << endl << endl;

    // moyenneComplementaire, moyenneInformatique, moyenneGenerale > DeterminerValidationSemestre > validationSemestre
    // = validationSemestre = (moyenneComplementaire >= 8 && moyenneInformatique >= 8 && moyenneGenerale >=10);
    if (moyenneComplementaire < 8 or moyenneInformatique < 8)
    {
        validationSemestre = false;
    }
    else
    {
        if (moyenneGenerale < 10)
        {
            validationSemestre = false;
        }
        else
        {
            validationSemestre = true;
        }
    }

    // validationSemestre > AfficherValidation > (écran)
    if (validationSemestre)
    {
        cout << "Semestre valide !" << endl;
    }
    else
    {
        cout << "Semestre non valide !" << endl;
    }

    return 0;
}
