/*
  Programme : LeJeuDuLievreEtDeLaTortue
  But : Ce programme simule des courses entre un li�vre et une tortue en suivant les r�gles suivantes :
        A chaque tour, on lance un d�. Si le 6 sort, le li�vre gagne la partie, sinon la tortue avance d'une case.
  La tortue gagne quand elle a avanc� de six cases.
  Date de cr�ation : 04/11/15
  Date de derni�re modification : 08/11/15
  Auteur : Valentin GRAGLIA
  Derni�re compilation : Linux
*/
#include <iostream>
#include <cstdlib> // pour la fonction rand
#include <time.h> // pour r�initialiser rand via time
// = #include <ctime>

using namespace std;

// D�claration des sous-programmes
int random (int min, int max); // renvoie un entier aleatoire dans l'intervalle [min,max[
int course (unsigned long int& nombreVictTortue, unsigned long int& nombreVictLievre); // simule la course

int main (void)
{
    // VARIABLES
    unsigned long int nbCoursesASimuler; // Le nombre de courses � simuler.
    unsigned long int nbVictoiresTortue = 0; // Nombre total de victoires de la tortue
    unsigned long int nbVictoiresLievre = 0; // Nombre total de victoires du li�vre


    // TRAITEMENT

    // Initialisation de la fonction rand()
    srand(time(NULL)); // N�cessaire pour g�n�rer correctement les nombres al�atoires

    // (clavier) >> SaisirNbCoursesASimuler >> nbCoursesASimuler
    cout << "Entrer le nombre de courses a simuler : ";
    cin >> nbCoursesASimuler;

    // nbVictoiresTortue, nbVictoiresLievre, nbCoursesASimuler >> DeterminerGagnant >> nbVictoiresTortue, nbVictoiresLievre
    for (int i=1; i<=nbCoursesASimuler; i++)
    {
        course (nbVictoiresTortue, nbVictoiresLievre);
    }

    // nbCourseASimuler, nbVictoiresTortue, nbVictoiresLievre >> AfficherResultat >> (�cran)
    cout << endl << "Sur " << nbCoursesASimuler << " courses les resultats sont les suivants :" << endl;
    cout << "Nombre de victoires de la tortue : " << nbVictoiresTortue << endl;
    cout << "Nombre de victoires du lievre : " << nbVictoiresLievre << endl;

    return 0;
}

// D�finition des sous-programmes
int random(int min, int max)
{
    return rand() % (max-min) + min; // D�terminer un nombre al�atoire entre 1 et 6
}

int course (unsigned long int& nombreVictTortue, unsigned long int& nombreVictLievre)
{
    // VARIABLES
    unsigned short int posTortue = 0; // Initialisation de la position de la tortue
    unsigned short int posLievre = 0; // Initialisation de la position du li�vre
    unsigned short int valDe; // La valeur du d� calcul�e al�atoirement


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
