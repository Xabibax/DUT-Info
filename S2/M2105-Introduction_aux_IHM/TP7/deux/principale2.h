#ifndef PRINCIPALE2_H
#define PRINCIPALE2_H

// Header central de wxWidgets incluant les widgets les plus utilisés
/* par exemple :
#include "wx/event.h"
#include "wx/app.h"
#include "wx/utils.h"
#include "wx/stream.h"
#include "wx/memory.h"
#include "wx/math.h"
#include "wx/stopwatch.h"
#include "wx/module.h"

#if wxUSE_GUI
#include "wx/window.h"
#include "wx/containr.h"
#include "wx/panel.h"
#include "wx/toplevel.h"
#include "wx/frame.h"
#include "wx/gdicmn.h"
#include "wx/gdiobj.h"
#include "wx/region.h"
#include "wx/bitmap.h"
#include "wx/image.h"
#include "wx/colour.h"
#include "wx/font.h"
#include "wx/dc.h"
#include "wx/dcclient.h"
#include "wx/dcmemory.h"
#include "wx/dcprint.h"
#include "wx/dcscreen.h"
#include "wx/button.h"
#include "wx/menuitem.h"
#include "wx/menu.h"
#include "wx/pen.h"
#include "wx/brush.h"
#include "wx/palette.h"
#include "wx/icon.h"
#include "wx/cursor.h"
#include "wx/dialog.h"
#include "wx/timer.h"
#include "wx/settings.h"
#include "wx/msgdlg.h"
#include "wx/cmndata.h"
#include "wx/dataobj.h"

#include "wx/control.h"
#include "wx/checkbox.h"
#include "wx/checklst.h"
#include "wx/scrolbar.h"
#include "wx/stattext.h"
#include "wx/statbox.h"
#include "wx/listbox.h"
#include "wx/radiobox.h"
#include "wx/radiobut.h"
#include "wx/textctrl.h"
#include "wx/slider.h"
#include "wx/scrolwin.h"
#include "wx/toolbar.h"
#include "wx/combobox.h"
#include "wx/layout.h"
#include "wx/sizer.h"
#include "wx/mdi.h"
#include "wx/statusbr.h"
....
*/
#include <wx/wx.h>

// Définition de la classe Principale2
class Principale2 : public wxFrame
{
    public:
    // Le constructeur
    Principale2(const wxString& title);

    private:
    bool monBool;
    wxButton *bouton1;
    wxButton *bouton2;
    wxTextCtrl *yCl;
    wxTextCtrl *xCl;
    wxStaticText *x;
    wxStaticText *y;
    wxStaticText *Addition;
    wxStaticText *Resultat;

    // Le destructeur
    virtual ~Principale2();

    // Méthode d'évènements
    void demandeFermeture(wxCloseEvent & evt);   // Gérer la demande de fermeture avec une fenêtre qui vous laisse le choix oui ou non
    void demandeAddition(wxCommandEvent & evt);  // Permet de faire l'addition des valeurs que l'utilisateur a rentrée dans les deux zones de saisie et de l'afficher dans la zone prévue à cet effet
    void demandeEffacer(wxCommandEvent & evt);   // Permet d'effacer les valeurs entrées par l'utilisateur en cliquant sur le bouton Effacer !


    // Déclaration de la table d'évènements
    private:

        DECLARE_EVENT_TABLE()


};
#endif // PRINCIPALE0_H
