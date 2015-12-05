#include <iostream>

using namespace std;

void remplacerChaine(char phrase[], unsigned short int tailleTab, char caractere1, char caractere2);

int main()
{
    unsigned short int nbCases;

    cout << "Saisissez la taille du tableau : ";
    cin >> nbCases;

    char mot[nbCases];

    for (int i=0; i<nbCases; i++)
    {
        cout << "Saisissez mot[" << i << "] : ";
        cin >> mot[i];
    }

    char lettre1, lettre2;

    cout << endl << "Saisissez la lettre a remplacer : ";
    cin >> lettre1;

    cout << "Saisissez la lettre de remplacement : ";
    cin >> lettre2;

    remplacerChaine(mot, nbCases, lettre1, lettre2);

    cout << endl;

    for (int i=0; i<nbCases; i++)
    {
        cout << "mot[" << i << "] = " << mot[i] << endl;
    }

    return 0;
}

void remplacerChaine(char phrase[], unsigned short int tailleTab, char caractere1, char caractere2)
{
    for (int i=0; i<tailleTab; i++)
    {
        if (phrase[i] == caractere1)
        {
            phrase[i] = caractere2;
        }
    }
}
