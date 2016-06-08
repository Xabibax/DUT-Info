#ifndef PRINCIPALE2_H
#define PRINCIPALE2_H

// Header central de wxWidgets incluant les widgets les plus utilisés
/* par exemple :
#include "wx/event.h"
#include "wx/app.h"

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
#include <wx/sizer.h>
#include <wx/timer.h>

enum
{
    wxID_BTABANDONNER_CLICK = wxID_HIGHEST + 1,
    wxID_IMGCARTE01_CLICK = wxID_HIGHEST + 2,
    wxID_IMGCARTE02_CLICK = wxID_HIGHEST + 3,
    wxID_IMGCARTE03_CLICK = wxID_HIGHEST + 4,
    wxID_IMGCARTE04_CLICK = wxID_HIGHEST + 5,
    wxID_IMGCARTE05_CLICK = wxID_HIGHEST + 6,
    wxID_IMGCARTE06_CLICK = wxID_HIGHEST + 7,
    wxID_IMGCARTE07_CLICK = wxID_HIGHEST + 8,
    wxID_IMGCARTE08_CLICK = wxID_HIGHEST + 9,
    wxID_IMGCARTE09_CLICK = wxID_HIGHEST + 10,
    wxID_IMGCARTE10_CLICK = wxID_HIGHEST + 11,
    wxID_IMGCARTE11_CLICK = wxID_HIGHEST + 12,
    wxID_IMGCARTE12_CLICK = wxID_HIGHEST + 13,
    wxID_IMGCARTE13_CLICK = wxID_HIGHEST + 14,
    wxID_IMGCARTE14_CLICK = wxID_HIGHEST + 15,
    wxID_IMGCARTE15_CLICK = wxID_HIGHEST + 16,
    wxID_IMGCARTE16_CLICK = wxID_HIGHEST + 17,
    wxID_IMGCARTE17_CLICK = wxID_HIGHEST + 18,
    wxID_IMGCARTE18_CLICK = wxID_HIGHEST + 29,
    wxID_IMGCARTE19_CLICK = wxID_HIGHEST + 20,
    wxID_IMGCARTE20_CLICK = wxID_HIGHEST + 21,
    wxID_TIMER = wxID_HIGHEST + 22
};

class Principale2 : public wxFrame
{
private:
    unsigned short int score = 0;
    unsigned short int cartesRetournees = 0;

    bool partieDemarre = false;

    int etatPaire1 = 0;
    int etatPaire2 = 0;
    int etatPaire3 = 0;
    int etatPaire4 = 0;
    int etatPaire5 = 0;
    int etatPaire6 = 0;
    int etatPaire7 = 0;
    int etatPaire8 = 0;
    int etatPaire9 = 0;
    int etatPaire10 = 0;

    int etatCarte1 = 0;
    int etatCarte2 = 0;
    int etatCarte3 = 0;
    int etatCarte4 = 0;
    int etatCarte5 = 0;
    int etatCarte6 = 0;
    int etatCarte7 = 0;
    int etatCarte8 = 0;
    int etatCarte9 = 0;
    int etatCarte10 = 0;
    int etatCarte11 = 0;
    int etatCarte12 = 0;
    int etatCarte13 = 0;
    int etatCarte14 = 0;
    int etatCarte15 = 0;
    int etatCarte16 = 0;
    int etatCarte17 = 0;
    int etatCarte18 = 0;
    int etatCarte19 = 0;
    int etatCarte20 = 0;

    bool disabledPaire1 = false;
    bool disabledPaire2 = false;
    bool disabledPaire3 = false;
    bool disabledPaire4 = false;
    bool disabledPaire5 = false;
    bool disabledPaire6 = false;
    bool disabledPaire7 = false;
    bool disabledPaire8 = false;
    bool disabledPaire9 = false;
    bool disabledPaire10 = false;

    wxBitmap bitm;
    wxBitmap bitmA;
    wxBitmap bitmB;
    wxBitmap bitmC;
    wxBitmap bitmD;
    wxBitmap bitmE;
    wxBitmap bitmF;
    wxBitmap bitmG;
    wxBitmap bitmH;
    wxBitmap bitmI;
    wxBitmap bitmJ;

    wxBitmapButton* image1 ;
    wxBitmapButton* image2 ;
    wxBitmapButton* image3 ;
    wxBitmapButton* image4 ;
    wxBitmapButton* image5 ;
    wxBitmapButton* image6 ;
    wxBitmapButton* image7 ;
    wxBitmapButton* image8 ;
    wxBitmapButton* image9 ;
    wxBitmapButton* image10 ;
    wxBitmapButton* image11 ;
    wxBitmapButton* image12 ;
    wxBitmapButton* image13 ;
    wxBitmapButton* image14 ;
    wxBitmapButton* image15 ;
    wxBitmapButton* image16 ;
    wxBitmapButton* image17 ;
    wxBitmapButton* image18 ;
    wxBitmapButton* image19 ;
    wxBitmapButton* image20 ;

    wxButton* btAbandonner;

    wxStaticText* txtInfo;
    wxStaticText* txtScore1;
    wxStaticText* txtScore2;
    wxStaticText* txtChrono;

    wxTimer Timer1;

public:
    Principale2(const wxString& title);
    virtual ~Principale2();

    void clicImage01(wxCommandEvent& evt);
    void clicImage02(wxCommandEvent& evt);
    void clicImage03(wxCommandEvent& evt);
    void clicImage04(wxCommandEvent& evt);
    void clicImage05(wxCommandEvent& evt);
    void clicImage06(wxCommandEvent& evt);
    void clicImage07(wxCommandEvent& evt);
    void clicImage08(wxCommandEvent& evt);
    void clicImage09(wxCommandEvent& evt);
    void clicImage10(wxCommandEvent& evt);
    void clicImage11(wxCommandEvent& evt);
    void clicImage12(wxCommandEvent& evt);
    void clicImage13(wxCommandEvent& evt);
    void clicImage14(wxCommandEvent& evt);
    void clicImage15(wxCommandEvent& evt);
    void clicImage16(wxCommandEvent& evt);
    void clicImage17(wxCommandEvent& evt);
    void clicImage18(wxCommandEvent& evt);
    void clicImage19(wxCommandEvent& evt);
    void clicImage20(wxCommandEvent& evt);

    void actualiserInfo();
    void btJouerClick(wxCommandEvent& evt);
    void btAbandonnerClick(wxCommandEvent& evt);
    void OnTimer(wxTimerEvent& evt);
    void resetJeu();
    void etatPaire();

    DECLARE_EVENT_TABLE()
};

#endif // PRINCIPALE2_H
