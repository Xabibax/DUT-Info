/***************************************************************
 * Name:      zeroMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2016-03-25
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef ZEROMAIN_H
#define ZEROMAIN_H

//(*Headers(zeroFrame)
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class zeroFrame: public wxFrame
{
    public:

        zeroFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~zeroFrame();

    private:

        //(*Handlers(zeroFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(zeroFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(zeroFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZEROMAIN_H
