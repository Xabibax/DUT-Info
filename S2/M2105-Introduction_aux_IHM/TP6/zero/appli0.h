#ifndef APPLI0_H
#define APPLI0_H

#include <wx/wx.h>

// Définition de la classe "Appli0"
class Appli0 : public wxApp
{
   public:
   // appel au démarrage de l’application
   virtual bool OnInit();
};

DECLARE_APP(Appli0)
#endif // APPLI0_H
