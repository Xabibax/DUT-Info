#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H
#include <iostream>
using namespace std;

void calculMoyenneSimple (string nomSysFic);
/*
Soit un fichier texte de nombres entiers, éventuellement vide mais non corrompu, dont le nom système est fourni par le paramètre nomFic.
Affichage à l'écran de la moyenne des hauteurs pluviométriques contenues dans le fichier.
*/

void calculMoyenneOuArret (string nomSysfic);
/*
Soit un fichier texte de nombres entiers, éventuellement vide et possiblement corrompu, dont le nom système est fourni par le paramètre nomFic.
Le programme affiche à l'écran, lorsque le fichier est correct, la moyenne des hauteurs pluviométriques contenues dans le fichier donné.
Lorsque le fichier est corrompu, le calcul s'arrête et le programme affiche un message d'erreur.
*/


void calculMoyenneOuFichierLog (string nomSysfic);
/*
Soit un fichier texte de nombres entiers, éventuellement vide et possiblement corrompu, dont le nom système est fourni par le paramètre nomFicDonnee.
Le programme affiche à l'écran, lorsque le fichier est correct, la moyenne des hauteurs pluviométriques contenues dans le fichier .
Un fichier texte « rapport  d'exécution », de nom système nomFicResultat est également créé, avec des informations sur le déroulement du programme (néant ou liste des erreurs rencontrées).
*/

#endif
