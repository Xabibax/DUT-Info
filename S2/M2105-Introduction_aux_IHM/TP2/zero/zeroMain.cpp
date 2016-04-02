<<<<<<< HEAD
/***************************************************************
 * Name:      zeroMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-03-25
 * Copyright:  ()
 * License:
 **************************************************************/

#include "zeroMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(zeroFrame)
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

//(*IdInit(zeroFrame)
const long zeroFrame::idMenuQuit = wxNewId();
const long zeroFrame::idMenuAbout = wxNewId();
const long zeroFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zeroFrame,wxFrame)
    //(*EventTable(zeroFrame)
    //*)
END_EVENT_TABLE()

zeroFrame::zeroFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(zeroFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("B\'Twin"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zeroFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zeroFrame::OnAbout);
    //*)
}

zeroFrame::~zeroFrame()
{
    //(*Destroy(zeroFrame)
    //*)
}

void zeroFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void zeroFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
=======
/***************************************************************
 * Name:      zeroMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-03-25
 * Copyright:  ()
 * License:
 **************************************************************/

#include "zeroMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(zeroFrame)
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

//(*IdInit(zeroFrame)
const long zeroFrame::idMenuQuit = wxNewId();
const long zeroFrame::idMenuAbout = wxNewId();
const long zeroFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zeroFrame,wxFrame)
    //(*EventTable(zeroFrame)
    //*)
END_EVENT_TABLE()

zeroFrame::zeroFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(zeroFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("B\'Twin"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zeroFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zeroFrame::OnAbout);
    //*)
}

zeroFrame::~zeroFrame()
{
    //(*Destroy(zeroFrame)
    //*)
}

void zeroFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void zeroFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
>>>>>>> 106584f02f83aaec8a8a62bb79ee6636755791a1
