#include "principale2.h"

Principale2::Principale2(const wxString& title) : wxFrame (NULL,
                                                           wxID_ANY, // identifiant de l'objet qui sera créé, par défaut : wxID_ANY,
                                                           title)  // titre de la fenêtre
{
    txtX = new wxStaticText(this, wxID_ANY, wxT("x ="), wxPoint(10,10));
    txtY = new wxStaticText(this, wxID_ANY, wxT("y ="), wxPoint(10,50));
    txtXPlusY = new wxStaticText(this, wxID_ANY, wxT("x + y ="), wxPoint(10,100));
    lblX = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 10));
    lblY = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 50));
    additionner = new wxButton(this, wxID_ANY, wxT("Addition !"), wxPoint(200,100));
}

Principale2::~Principale2()
{

}
