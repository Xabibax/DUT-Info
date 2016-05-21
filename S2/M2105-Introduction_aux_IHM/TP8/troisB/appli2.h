#ifndef APPLI2_H
#define APPLI2_H

#include <wx/wx.h>

class Appli2 : public wxApp
{
   public:
       virtual bool OnInit(); // appel au démarrage de l’application
};

DECLARE_APP(Appli2)

#endif // APPLI2_H
