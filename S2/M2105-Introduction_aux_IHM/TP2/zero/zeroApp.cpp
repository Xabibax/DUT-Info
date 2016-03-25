/***************************************************************
 * Name:      zeroApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-03-25
 * Copyright:  ()
 * License:
 **************************************************************/

#include "zeroApp.h"

//(*AppHeaders
#include "zeroMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(zeroApp);

bool zeroApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	zeroFrame* Frame = new zeroFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
