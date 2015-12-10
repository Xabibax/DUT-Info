#include "file.h"
#include<iostream>

using namespace std;

void initialiser (UneFile& f)
{
    while (!f.empty()) // empty() renvoie true si f est vide,false sinon
        f.pop(); // Supprimer le dernier élément ajouté
}

unsigned int taille (const UneFile& f)
{
    return f.size();
}

bool estVide (const UneFile& f)
{
    return f.empty();
}

UnElement premier (const UneFile& f)
{
    if(!f.empty())
        return f.front(); // front() permet d'accéder au premier élément
    else
    {
        cerr << "fileVide" << endl;
        // on utilise dans le cas des erreurs le flux standard d'erreur nommé cerr
        throw string("fileVide");
    }
}

void enfiler (UneFile& f, UnElement e)
{
    f.push(e); // Ajouter l'élément e à la file f
}

void defiler (UneFile& f)
{
    if(!f.empty())
        f.pop(); // Supprimer le dernier élément ajouté
    else
    {
        cerr << "fileVide" << endl;
        throw string("fileVide");
        // throw signale l'erreur en lançant un objet
    }
}

void defiler (UneFile& f, UnElement& e)
{
    if(!f.empty())
    {
        e = f.front();
        f.pop();
    }
    else
    {
        cerr << "fileVide" << endl;
        throw string("fileVide");
    }
}
