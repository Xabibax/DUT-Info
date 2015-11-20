#include <iostream>
#include "chiffrement.h"
#include "dechiffrement.h"

using namespace std;

int main()
{
    unsigned short int tailleMot;

    cout << "Saisissez le nombre de caracteres : ";
    cin >> tailleMot;

    char motInitial[tailleMot];

    for (int i=0; i<tailleMot; i++)
    {
        cout << "Saisissez le caractere n° " << i+1 << " : ";
        cin >> motInitial[i];
    }

    char selection;

    do
    {
        cout << "Souhaitez-vous chiffrer ou bien dechiffre (c/d) ? ";
        cin >> selection;
    }
    while(!(selection == 'C' || selection == 'c' || selection == 'D' || selection == 'd'));

    int cle;

    do
    {
        cout << "Saisissez la cle de chiffrement : ";
        cin >> cle;
    }
    while (!(cle < 26 || cle > 26));

    if (selection == 'C' || selection == 'c')
    {
        chiffrement(motInitial, tailleMot, cle);
    }
    else
    {
        dechiffrement(motInitial, tailleMot, cle);
    }

    for (int i=0; i<tailleMot; i++)
    {
        cout << motInitial[i];
    }

    return 0;
}
