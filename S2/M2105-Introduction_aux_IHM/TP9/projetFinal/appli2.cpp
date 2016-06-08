#include "appli2.h"
#include "principale2.h"

// Permet à wxWidgets de crééer l'instance d'application
IMPLEMENT_APP(Appli2)

// Implémentation de la méthode OnInit()
bool Appli2::OnInit()
{
    // Création de la fenêtre principale de l'application
    Principale2 *maFen = new Principale2(wxT("Jeu de Memory"));

    maFen -> Show(true);

    return true;
}
