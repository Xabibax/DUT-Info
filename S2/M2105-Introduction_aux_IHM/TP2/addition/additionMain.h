/***************************************************************
 * Name:      additionMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2016-03-25
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef ADDITIONMAIN_H
#define ADDITIONMAIN_H

//(*Headers(additionFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class additionFrame: public wxFrame
{
    public:

        additionFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~additionFrame();

    private:

        //(*Handlers(additionFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(additionFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(additionFrame)
        wxStaticText* LBL_SOMME;
        wxButton* BT_ADDITION;
        wxStaticText* LBL_Y;
        wxStaticText* LBL_X;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TXT_X;
        wxStaticText* LBL_RESULTAT;
        wxStaticText* StaticText4;
        wxTextCtrl* TXT_Y;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ADDITIONMAIN_H
