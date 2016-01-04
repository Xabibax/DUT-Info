#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

unsigned int indice (char c) ;
// retourne le nbre entier = code ascii(c) - 'a'

int valeur (int t[], char c);
// retourne la valeur de la variable dont le nom au contenu de c

void initVariables (int t[], unsigned int lgT);
// initialise � 0 toutes les variables

void saisieVariables (int t[], unsigned int lgT);
// saisie au clavier des valeurs des variables enti�res constituant les expressions analys�es

void afficheVariables (int t[], unsigned int lgT);
// affiche � l'�cran le contenu des variables enti�res constituant les expressions analys�es

int exprEntPostFixee(int t[], string expr);
// retourne la valeur de l'expression correcte en notation postfix�e contenue dans la chaine de caract�res expr

bool estContenuDans(const char TAB_COMPARATEURS[], const int TAILLE, char caractere);
// determine si un caractere est contenu dans un tableau de caracteres TAB_COMPARATEURS de TAILLE cases


string exParentheseVersPostF(string s);
//  retourne la chaine contenant l'expression en notation postfix�e correspondant � l'expression
//  compl�tement parenth�s�e CORRECTE fournie en param�tre


#endif
