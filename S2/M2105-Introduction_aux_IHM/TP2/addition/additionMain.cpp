<<<<<<< HEAD
/***************************************************************
 * Name:      additionMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-03-25
 * Copyright:  ()
 * License:
 **************************************************************/

#include "additionMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(additionFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(additionFrame)
const long additionFrame::ID_STATICTEXT1 = wxNewId();
const long additionFrame::ID_STATICTEXT2 = wxNewId();
const long additionFrame::ID_TEXTCTRL1 = wxNewId();
const long additionFrame::ID_TEXTCTRL2 = wxNewId();
const long additionFrame::ID_BUTTON1 = wxNewId();
const long additionFrame::ID_STATICTEXT3 = wxNewId();
const long additionFrame::ID_STATICTEXT4 = wxNewId();
const long additionFrame::ID_STATICTEXT5 = wxNewId();
const long additionFrame::idMenuQuit = wxNewId();
const long additionFrame::idMenuAbout = wxNewId();
const long additionFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(additionFrame,wxFrame)
    //(*EventTable(additionFrame)
    //*)
END_EVENT_TABLE()

additionFrame::additionFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(additionFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("Addition d\'entiers"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(300,150));
    LBL_X = new wxStaticText(this, ID_STATICTEXT1, _("X ="), wxPoint(10,10), wxSize(48,32), 0, _T("ID_STATICTEXT1"));
    LBL_Y = new wxStaticText(this, ID_STATICTEXT2, _("Y ="), wxPoint(10,50), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TXT_X = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(50,10), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TXT_Y = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(50,50), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BT_ADDITION = new wxButton(this, ID_BUTTON1, _("Addition !"), wxPoint(180,30), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    LBL_SOMME = new wxStaticText(this, ID_STATICTEXT3, _("X+Y ="), wxPoint(10,100), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, wxEmptyString, wxPoint(56,120), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    LBL_RESULTAT = new wxStaticText(this, ID_STATICTEXT5, wxEmptyString, wxPoint(48,96), wxSize(136,40), 0, _T("ID_STATICTEXT5"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&additionFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&additionFrame::OnAbout);
    //*)
}

additionFrame::~additionFrame()
{
    //(*Destroy(additionFrame)
    //*)
}

void additionFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void additionFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
=======
/***************************************************************
 * Name:      additionMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-03-25
 * Copyright:  ()
 * License:
 **************************************************************/

#include "additionMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(additionFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(additionFrame)
const long additionFrame::ID_STATICTEXT1 = wxNewId();
const long additionFrame::ID_STATICTEXT2 = wxNewId();
const long additionFrame::ID_TEXTCTRL1 = wxNewId();
const long additionFrame::ID_TEXTCTRL2 = wxNewId();
const long additionFrame::ID_BUTTON1 = wxNewId();
const long additionFrame::ID_STATICTEXT3 = wxNewId();
const long additionFrame::ID_STATICTEXT4 = wxNewId();
const long additionFrame::ID_STATICTEXT5 = wxNewId();
const long additionFrame::idMenuQuit = wxNewId();
const long additionFrame::idMenuAbout = wxNewId();
const long additionFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(additionFrame,wxFrame)
    //(*EventTable(additionFrame)
    //*)
END_EVENT_TABLE()

additionFrame::additionFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(additionFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("Addition d\'entiers"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(300,150));
    LBL_X = new wxStaticText(this, ID_STATICTEXT1, _("X ="), wxPoint(10,10), wxSize(48,32), 0, _T("ID_STATICTEXT1"));
    LBL_Y = new wxStaticText(this, ID_STATICTEXT2, _("Y ="), wxPoint(10,50), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TXT_X = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(50,10), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TXT_Y = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(50,50), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BT_ADDITION = new wxButton(this, ID_BUTTON1, _("Addition !"), wxPoint(180,30), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    LBL_SOMME = new wxStaticText(this, ID_STATICTEXT3, _("X+Y ="), wxPoint(10,100), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, wxEmptyString, wxPoint(56,120), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    LBL_RESULTAT = new wxStaticText(this, ID_STATICTEXT5, wxEmptyString, wxPoint(48,96), wxSize(136,40), 0, _T("ID_STATICTEXT5"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&additionFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&additionFrame::OnAbout);
    //*)
}

additionFrame::~additionFrame()
{
    //(*Destroy(additionFrame)
    //*)
}

void additionFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void additionFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
>>>>>>> 106584f02f83aaec8a8a62bb79ee6636755791a1
