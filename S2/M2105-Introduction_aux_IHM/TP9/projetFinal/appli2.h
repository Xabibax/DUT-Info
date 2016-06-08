#ifndef APPLI2_H
#define APPLI2_H

#include <wx/wx.h>

// Définition de la classe "Appli2"
class Appli2 : public wxApp
{
public:
    // appel au démarrage de l’application
    virtual bool OnInit();
};

DECLARE_APP(Appli2)

#endif // APPLI2_H
