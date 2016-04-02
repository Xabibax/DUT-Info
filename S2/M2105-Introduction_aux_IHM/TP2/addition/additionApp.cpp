<<<<<<< HEAD
/***************************************************************
 * Name:      additionApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-03-25
 * Copyright:  ()
 * License:
 **************************************************************/

#include "additionApp.h"

//(*AppHeaders
#include "additionMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(additionApp);

bool additionApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	additionFrame* Frame = new additionFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
=======
/***************************************************************
 * Name:      additionApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-03-25
 * Copyright:  ()
 * License:
 **************************************************************/

#include "additionApp.h"

//(*AppHeaders
#include "additionMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(additionApp);

bool additionApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	additionFrame* Frame = new additionFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
>>>>>>> 106584f02f83aaec8a8a62bb79ee6636755791a1
