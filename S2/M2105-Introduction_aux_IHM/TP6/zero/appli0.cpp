#include "appli0.h"
#include "principale0.h"

// Permet à wxWidgets de crééer l'instance d'application
IMPLEMENT_APP(Appli0)

// Implémentation de la méthode OnInit()
   bool Appli0::OnInit()
   {
       // Création de la fenêtre principale de l'application
       Principale0 *maFen = new Principale0(wxT("Principale 0"));

       // Rendre la fenêtre visible
       maFen -> Show(true);

       // Démarre la boucle des messages
       return true;
    }
