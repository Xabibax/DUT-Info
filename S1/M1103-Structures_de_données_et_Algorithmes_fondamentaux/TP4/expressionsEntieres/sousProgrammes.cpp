#include <iostream>
#include <iomanip>      // pour l'attribut setw() permettant l'affichage sur une largeur fixe
#include "pile.h"
#include "sousProgrammes.h"

using namespace std;

const unsigned int NB_OP = 4;
char listeOp[NB_OP] = {'/', '-', '*', '+'}; // tableau contenant touqs les opérateurs

unsigned int indice (char c)
{
    return (c - 'a');
}

int valeur (int t[], char c)
{
    return (t[indice(c)]);
}

int exprEntPostFixee(int t[], string expr)
{
    UnePile p; // la pile pour le calcul
    initialiser(p);

    int a, b, stock; // variables de stockage

    for ( unsigned int i=0 ; i < expr.size() ; i++)
    {
        if (estContenuDans(listeOp, NB_OP, expr[i]))
        {
            depiler(p, a);
            depiler(p, b);
            switch (expr[i])
            {
            case'/':
                stock = b/a;
                break;
            case'-':
                stock = -a+b;
                break;
            case'*':
                stock = a*b;
                break;
            case'+':
                stock = a+b;
                break;
            default:
                break;
            }
            empiler(p, stock);

        }
        else
            empiler(p, valeur(t, expr[i]));
    }

    return sommet(p);
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
    }
}

bool estContenuDans(const char TAB_COMPARATEURS[], const int TAILLE, char caractere)
{
    bool resultat = false; // le resultat retourné par la fonction

    for (unsigned int i = 0 ; i < TAILLE ; i++)
    {
        if (caractere == TAB_COMPARATEURS[i])
            resultat = true;
    }
    return resultat;
}


string exParentheseVersPostF(string s)
{
    UnePile stockage; //pile de stockage pour les opérandes
    string exPostF = new string(); //l'espression post fixée retournée
    unsigned int parcours = 0; // la variable de parcours de exPostF

    for (unsigned int i=0 ; i<s.size() ; i++)
    {
        if (!estContenuDans(listeOp, NB_OP, s[i]) && s[i]!='(' && s[i]!=')')
        {
            exPostF[parcours] = s[i];
            parcours++;
        }

        else if (estContenuDans(listeOp, NB_OP, s[i]))
            empiler(stockage, s[i]);
        else if (s[i]==')')
        {
            depiler(stockage, (UnElement&) exPostF[parcours]);
            parcours++;
        }

    }
    return exPostF;
}
