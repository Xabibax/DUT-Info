#include <iostream>
#include <iomanip>      // pour l'attribut setw() permettant l'affichage sur une largeur fixe
#include "pile.h"
#include "sousProgrammes.h"

using namespace std;

unsigned int indice (char c)
{
    return (c - 'a');
}

int valeur (int t[], char c)
{
    return (t[indice(c)]);
}

int evaluationExPostfixee  (int t[], string expression)
{
    // Variables
    int x;// 1er operande
    int y;// 2eme operande
    int resultat;// Resultat de l'operation entre les deux operandes
    int i;// Variable de la position courante
    UnePile pile;// Pile pour le stockage temporaire des operandes et des resultats


    //Traitements
    // Initialisation >> pile
    initialiser(pile);

    // pile,x,y,resultat,t[],expression >> evaluerCaractereCourant >> pile
    for ( i = 0 ; i < expression.size() ; i++ )
    {
        if (expression[i] >= 'a' and expression[i] <= 'z')
        {
            empiler(pile,valeur(t, expression[i]));
        }
        else
            // pile,x,y,resultat >> calculerExpression >> pile
        {
            depiler(pile,y);

            depiler(pile,x);

            switch (expression[i])
            {
            case '+':
                resultat = x + y;
                break;
            case '-':
                resultat = x - y;
                break;
            case '/':
                resultat = x / y;
                break;
            case '*':
                resultat = x * y;
                break;
            }

            empiler(pile, resultat);
        }

    }

    return sommet(pile);

    return 0;
}

void saisieVariables (int t[], unsigned int lgT)
{
    char variable;   // nom de la variable à affecter
    int valeur;      // valeur à affecter à variable

    // (clavier) >> initialisation des variables >> tabVal
    cout << "\nINITIALISATION DES VARIABLES ENTIERES QUI COMPOSERONT LES EXPRESSIONS A CALCULER \n";
    cout << "\nPour chaque variable, saisir : \n \nnomEnMinuscules  espace  sa valeur ENTIERE, puis <entree>" << endl;
    cout << "Terminer par ! puis <entree> " << endl << endl;
    cout << "Exemple : a 12<entree> k 10<entree> d -1<entree> b 3<entree> !<entree>" << endl;
    while (true)
    {
        cin >> variable ;
        if (variable == '!')
        {
            break;
        }
        cin >> valeur;
        t[indice(variable)] = valeur;
    } ;
    cout << endl;
}

void afficheVariables (int t[], unsigned int lgT)
{
    for (unsigned int i = 0 ; i < lgT; i++ )
    {
        cout << (char) (i+'a') << ":" << setw(3) << t[i] << "     ";
        if (((i+1)%5) ==0)
        {
            cout << endl;
        }
    };
    cout << endl;
}

void initVariables (int t[], unsigned int lgT)
{
    for (unsigned int i = 0 ; i < lgT; i++  )
    {
        t[i] = 0;
    };
}


string exPostVersParenthesee (string s)
{
    // Variables
    string expression;// Expression post fixée à retourner apres transformation de s
    unsigned int i;// Variable de la position courante
    UnePile pile;// Pile pour le stockage temporaire des operateurs
    UnElement c;// Valeur intermediaire

    // Traitements
    // Initialisation >> pile
    initialiser(pile);

    // pile,c >> transformerS >> expression
    for ( i = 0; i < s.size() ; i++ )
    {
        if ( s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/' )
        {
            empiler(pile, s[i]);
        }
        else if ( s[i] == ')')
        {
            depiler (pile, c);
            expression = expression + char(c);
        }
        else if ( s[i] != '(' )
        {
            expression = expression + s[i];
        }
    }
    return expression;
}


