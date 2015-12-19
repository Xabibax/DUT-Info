#include <iostream>
#include "pile.h"
#include "sousProgrammes.h"

using namespace std;
int main()
{
    const unsigned int BORNE_INF = 'a' - 'a';   // indice INF du tableau contenant les valeurs des variables utilis�es
    const unsigned int BORNE_SUP = 'z' - 'a';   // indice SUP du tableau contenant les valeurs des variables utilis�es

    // pour m�moriser les valeurs des variables contenues dans l'expression

    const unsigned int lgTabVal = BORNE_SUP - BORNE_INF + 1; //on ne consid�re que les varibles minuscules

    int tabVal[lgTabVal] ; // valeurs des 26 variables potentielles pouvant �tre contenues dans l'expression enti�re
    // pour g�rer les expressions r�guli�res

    string exprPost; // l'expression enti�re CORRECTE en notation postfix�e
    string exPar ;  // l'expression correcte enti�rement parenth�s�e

    // initialisation de toutes les variables � 0
    initVariables(tabVal, lgTabVal);

    // (clavier) >> saisie des valeurs des variables composant les expressions >> tabVal, lgTabVal
    saisieVariables (tabVal, lgTabVal);

    for (;;)
    {

        // tabVal, lgTabVal >> afficher variables >> (�cran
        afficheVariables(tabVal, lgTabVal);

        //(clavier) >> saisie expression postFixee >> exprPost
        cout << endl << "Saisir une expression postfixee CORRECTE puis <entree> \npour lancer l'evaluation.\n";
        cout << "Saisir ! puis <entrer> pour arreter le programme : " ;
        cin >> exprPost;

        if (exprPost ==  "!")
            break;

        // calcul de l'expression
        cout << "valeur ( " << exprPost << " ) = " << exprEntPostFixee(tabVal, exprPost) << endl << endl;
    }

    /*// NON DEMAND�
    cout << "Entrer une expression infixee entierement parenthesee CORRECTE :  " ;
    cin >> exPar;

    exprPost = exParentheseVersPostF(exPar);
    cout << exprPost;*/



    return 0;
}
