#ifndef APPLI0_H
#define APPLI0_H

#include <wx/wx.h>

// D�finition de la classe "Appli0"
class Appli0 : public wxApp
{
   public:
   // appel au d�marrage de l�application
   virtual bool OnInit();
};

DECLARE_APP(Appli0)
#endif // APPLI0_H
