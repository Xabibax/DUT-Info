#include "appli2.h"
#include "principale2.h"

// Permet � wxWidgets de cr��er l'instance d'application
IMPLEMENT_APP(Appli2)

// Impl�mentation de la m�thode OnInit()
bool Appli2::OnInit()
{
    // Cr�ation de la fen�tre principale de l'application
    Principale2 *maFen = new Principale2(wxT("Principale 2 : Addition"));

    // Rendre la fen�tre visible
    maFen -> Show(true);

    return true;
}
