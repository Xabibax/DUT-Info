#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

unsigned int indice (char c) ;
// retourne le nbre entier = code ascii(c) - 'a'

int valeur (int t[], char c);
// retourne la valeur de la variable dont le nom au contenu de c

void initVariables (int t[], unsigned int lgT);
// initialise à 0 toutes les variables

void saisieVariables (int t[], unsigned int lgT);
// saisie au clavier des valeurs des variables entières constituant les expressions analysées

void afficheVariables (int t[], unsigned int lgT);
// affiche à l'écran le contenu des variables entières constituant les expressions analysées

int evaluationExPostfixee  (int t[], string expression);
// retourne la valeur de l'expression correcte en notation postfixée contenue dans la chaine de caractères s


string exPostVersParenthesee (string s);
//  retourne la chaine contenant l'expression en notation postfixée correspondant à l'expression
//  complètement parenthésée CORRECTE fournie en paramètre


#endif

