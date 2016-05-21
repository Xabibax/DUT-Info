#include "principale0.h"

Principale0::Principale0(const wxString& title) : wxFrame (NULL,
            wxID_ANY, // identifiant de l'objet qui sera créé, par défaut : wxID_ANY,
            title) { // titre de la fenêtre

    wxBoxSizer *topSizer = new wxBoxSizer( wxVERTICAL );

    topSizer->Add( new wxTextCtrl( this, wxID_ANY, wxT("My text."), wxDefaultPosition, wxSize(100,60),
                                                                    wxTE_MULTILINE), 1, wxEXPAND| wxALL, 10 );

    wxBoxSizer *buttonSizer = new wxBoxSizer( wxHORIZONTAL );
    buttonSizer->Add(new wxButton( this, wxID_OK, wxT("OK")), 0, wxALL, 10 );
    buttonSizer->Add(new wxButton( this, wxID_CANCEL, wxT("Cancel") ),0, wxALL, 10 );

    topSizer->Add( buttonSizer, 0, wxALIGN_CENTER );

    SetSizer( topSizer ); // use the sizer for layout
    topSizer->Fit( this ); // fit the dialog to the contents
    topSizer->SetSizeHints( this ); // set hints to honor min size
    }
// Le destructeur
Principale0::~Principale0() {
    // Destructeur
    }

    //    wxBoxSizer *topSizer = new wxBoxSizer( wxVERTICAL );
