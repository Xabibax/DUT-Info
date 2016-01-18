#include <iostream>
#include "pile.h"
#include "sousProgrammes.h"

using namespace std;
int main()
{
const unsigned int BORNE_INF = 'a' - 'a';   // indice INF du tableau contenant les valeurs des variables utilisées
const unsigned int BORNE_SUP = 'z' - 'a';   // indice SUP du tableau contenant les valeurs des variables utilisées

    // pour mémoriser les valeurs des variables contenues dans l'expression

const unsigned int lgTabVal = BORNE_SUP - BORNE_INF + 1; //on ne considère que les varibles minuscules

int tabVal[lgTabVal] ; // valeurs des 26 variables potentielles pouvant être contenues dans l'expression entière
   // pour gérer les expressions régulières

   string exPost; // l'expression entière CORRECTE en notation postfixée
   string exPar ;  // l'expression correcte entièrement parenthésée

   // initialisation de toutes les variables à 0
   initVariables(tabVal, lgTabVal);

   // (clavier) >> saisie des valeurs des variables composant les expressions >> tabVal, lgTabVal
  // saisieVariables (tabVal, lgTabVal);

  /* for (;;)
      {

        // tabVal, lgTabVal >> afficher variables >> (écran
        afficheVariables(tabVal, lgTabVal);

        //(clavier) >> saisie expression postFixee >> exPost
        cout << endl << "Saisir une expression postfixee CORRECTE puis <entree> \npour lancer l'evaluation.\n";
        cout << "Saisir ! puis <entrer> pour arreter le programme : " ;
        cin >> exPost;

        if (exPost ==  "!")
        break;

         // calcul de l'expression
         cout << "valeur ( " << exPost << " ) = " << evaluationExPostfixee (tabVal, exPost) << endl << endl;
      }

   return 0;
}
*/

    while(true)
    {
         cout << "Entrer une expression infixee entierement parenthesee CORRECTE (! pour arreter) :  " ;
         cin >> exPar;

         if (exPar ==  "!")
            break;

         exPost = exPostVersParenthesee (exPar);
         cout << exPost;
    }
   return 0;
}
