#include "appli0.h"
#include "principale0.h"

// Permet � wxWidgets de cr��er l'instance d'application
IMPLEMENT_APP(Appli0)

// Impl�mentation de la m�thode OnInit()
   bool Appli0::OnInit()
   {
       // Cr�ation de la fen�tre principale de l'application
       Principale0 *maFen = new Principale0(wxT("Principale 0"));

       // Rendre la fen�tre visible
       maFen -> Show(true);

       // D�marre la boucle des messages
       return true;
    }
