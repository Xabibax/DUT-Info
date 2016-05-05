#include "principale2.h"

Principale2::Principale2(const wxString& title) : wxFrame (NULL,
                                                   wxID_ANY, // identifiant de l'objet qui sera créé, par défaut : wxID_ANY,
                                                   title)  // titre de la fenêtre
{
    x = new wxStaticText(this, wxID_ANY, wxT("x ="), wxPoint(10,10));
    y = new wxStaticText(this, wxID_ANY, wxT("y ="), wxPoint(10,50));
    res = new wxStaticText(this, wxID_ANY, wxT("x + y ="), wxPoint(10,100));
    xCl = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 10));
    yCl = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 50));
    bouton = new wxButton(this, wxID_ANY, wxT("Addition !"), wxPoint(200,100));
}

Principale2::~Principale2()
{

}
