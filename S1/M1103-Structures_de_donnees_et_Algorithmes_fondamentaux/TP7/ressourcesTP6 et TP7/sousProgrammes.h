#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H
#include <iostream>
using namespace std;

void calculMoyenneSimple (string nomSysFic);
/*
Soit un fichier texte de nombres entiers, �ventuellement vide mais non corrompu, dont le nom syst�me est fourni par le param�tre nomFic.
Affichage � l'�cran de la moyenne des hauteurs pluviom�triques contenues dans le fichier.
*/

void calculMoyenneOuArret (string nomSysfic);
/*
Soit un fichier texte de nombres entiers, �ventuellement vide et possiblement corrompu, dont le nom syst�me est fourni par le param�tre nomFic.
Le programme affiche � l'�cran, lorsque le fichier est correct, la moyenne des hauteurs pluviom�triques contenues dans le fichier donn�.
Lorsque le fichier est corrompu, le calcul s'arr�te et le programme affiche un message d'erreur.
*/


void calculMoyenneOuFichierLog (string nomSysfic);
/*
Soit un fichier texte de nombres entiers, �ventuellement vide et possiblement corrompu, dont le nom syst�me est fourni par le param�tre nomFicDonnee.
Le programme affiche � l'�cran, lorsque le fichier est correct, la moyenne des hauteurs pluviom�triques contenues dans le fichier .
Un fichier texte ��rapport� d'ex�cution �, de nom syst�me nomFicResultat est �galement cr��, avec des informations sur le d�roulement du programme (n�ant ou liste des erreurs rencontr�es).
*/

#endif
