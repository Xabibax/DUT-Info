#ifndef MODULESCOMMUNSTRI_H
#define MODULESCOMMUNSTRI_H

void afficheTableauEntiers (const int tab[], unsigned int nbTab);
// But : affiche � l'�cran le contenu d'un tableau tab de nbTab �l�ments

void echanger (int& a, int& b);
// �change le contenu des 2 param�tres entiers a et b

void triUnElement(int tab[], unsigned int nbCasesNonTrie);
// tri le tableau tab de taille nbCasesNonTrie

void triParBulle(int tab[], unsigned int nbCasesNonTrie);
// tri le tableau tab de taille nbCasesNonTrie

void triSelectUnElement(int tab[], unsigned int nbCasesNonTrie);
// but: la procedure triSelectUnElement tri 1 element par selection dans un tableau tab de taille nbCasesNonTrie

unsigned int positionDuMax (int tab[], unsigned int nbCasesNonTrie);
// but : positionDuMax indique la position de la plus grande valeur du tableau tab de taille nbCasesNonTrie

void triSelect(int tab[], unsigned int nbCasesNonTrie);
// but: la procedure triSelectUnElement tri tout element par selection dans un tableau tab de taille nbCasesNonTrie

#endif // MODULESCOMMUNSTRI_H
