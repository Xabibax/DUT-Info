/*
  Programme : LeJeuDuLievreEtDeLaTortue
  But : Ce programme simule des courses entre un lièvre et une tortue en suivant les règles suivantes :
        A chaque tour, on lance un dé. Si le 6 sort, le lièvre gagne la partie, sinon la tortue avance d'une case.
  La tortue gagne quand elle a avancé de six cases.
  Date de création : 04/11/15
  Date de dernière modification : 08/11/15
  Auteur : Valentin GRAGLIA
  Dernière compilation : Linux
*/
#include <iostream>
#include <cstdlib> // pour la fonction rand
#include <time.h> // pour réinitialiser rand via time
// = #include <ctime>

using namespace std;

// Déclaration des sous-programmes
int random (int min, int max); // renvoie un entier aleatoire dans l'intervalle [min,max[
int course (unsigned long int& nombreVictTortue, unsigned long int& nombreVictLievre); // simule la course

int main (void)
{
    // VARIABLES
    unsigned long int nbCoursesASimuler; // Le nombre de courses à simuler.
    unsigned long int nbVictoiresTortue = 0; // Nombre total de victoires de la tortue
    unsigned long int nbVictoiresLievre = 0; // Nombre total de victoires du lièvre


    // TRAITEMENT

    // Initialisation de la fonction rand()
    srand(time(NULL)); // Nécessaire pour générer correctement les nombres aléatoires

    // (clavier) >> SaisirNbCoursesASimuler >> nbCoursesASimuler
    cout << "Entrer le nombre de courses a simuler : ";
    cin >> nbCoursesASimuler;

    // nbVictoiresTortue, nbVictoiresLievre, nbCoursesASimuler >> DeterminerGagnant >> nbVictoiresTortue, nbVictoiresLievre
    for (int i=1; i<=nbCoursesASimuler; i++)
    {
        course (nbVictoiresTortue, nbVictoiresLievre);
    }

    // nbCourseASimuler, nbVictoiresTortue, nbVictoiresLievre >> AfficherResultat >> (écran)
    cout << endl << "Sur " << nbCoursesASimuler << " courses les resultats sont les suivants :" << endl;
    cout << "Nombre de victoires de la tortue : " << nbVictoiresTortue << endl;
    cout << "Nombre de victoires du lievre : " << nbVictoiresLievre << endl;

    return 0;
}

// Définition des sous-programmes
int random(int min, int max)
{
    return rand() % (max-min) + min; // Déterminer un nombre aléatoire entre 1 et 6
}

int course (unsigned long int& nombreVictTortue, unsigned long int& nombreVictLievre)
{
    // VARIABLES
    unsigned short int posTortue = 0; // Initialisation de la position de la tortue
    unsigned short int posLievre = 0; // Initialisation de la position du lièvre
    unsigned short int valDe; // La valeur du dé calculée aléatoirement


    // TRAITEMENT

    // valDe, posTortue, posLievre >> CalculerPosition >> valDe, posTortue, posLievre
    do
    {
        valDe = random(1, 7);

        if(valDe < 6)
        {
            posTortue++;
        }
        else
        {
            posLievre = 6;
        }
    }
    while(!((posLievre == 6) || (posTortue == 6)));

    // posLievre, posTortue, nombreVictLievre, nombreVictTortue >> CalculerNombreVictoire >> nombreVictLievre, nombreVictTortue
    if (posLievre == 6)
    {
        nombreVictLievre = nombreVictLievre + 1;
    }
    else
    {
        if (posTortue == 6)
        {
            nombreVictTortue = nombreVictTortue + 1;
        }
    }

    return 0;
}
