#include <iostream>

using namespace std;

int main()
{
    unsigned short int nbSeparateur = 37;
    char separateur[nbSeparateur] = {'&', '~', '#', '"', ' ', '{', '(', '[', '-', '|', '`', '_', '@', ')', ']', '°', '+', '=', '}', '$', '£', '¤', '*', 'µ', '%', '§', '!', ':', '/', ';', '.', ',', '?', '<', '>', '*', '/'};

    unsigned short int tailleTexte = 44;
    char texte[tailleTexte] = {'_', 'B', 'o', 'n', 'j', 'o', 'u', 'r', '-', 'e', 't', '-', 'b', 'i', 'e', 'n', 'v', 'e', 'n', 'u', 'e', '_', 'J', 'e', '-', 'm', '+', 'a', 'p', 'p', 'e', 'l', 'l', 'e', '-', 'V', 'a', 'l', 'e', 'n', 't', 'i', 'n', '_'};
    bool separateur[tailleTexte] = false;


    return 0;
}
