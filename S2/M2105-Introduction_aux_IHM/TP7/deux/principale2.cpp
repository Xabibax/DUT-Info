#include "principale2.h"

BEGIN_EVENT_TABLE(Principale2, wxFrame)
    EVT_CLOSE(Principale2::demandeFermeture)
END_EVENT_TABLE()

Principale2::Principale2(const wxString& title) : wxFrame (NULL,
                                                           wxID_ANY, // identifiant de l'objet qui sera créé, par défaut : wxID_ANY,
                                                           title)  // titre de la fenêtre
{
    txtX = new wxStaticText(this, wxID_ANY, wxT("x ="), wxPoint(10,10));
    txtY = new wxStaticText(this, wxID_ANY, wxT("y ="), wxPoint(10,50));
    txtXPlusY = new wxStaticText(this, wxID_ANY, wxT("x + y ="), wxPoint(10,100));
    lblX = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 10));
    lblY = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 50));
    btAdditionner = new wxButton(this, wxID_ANY, wxT("Addition !"), wxPoint(200,100));
    btEffacer = new wxButton(this, wxID_ANY, wxT("Effacer !"), wxPoint(300,100));
}

Principale2::~Principale2()
{

}

void Principale2::demandeFermeture(wxCloseEvent& evt)
{
	if (wxMessageBox(wxT("Voulez-vous quittAIENT (PlumAIENT, vidAIENT, décapitAIENT) ?"), wxT("ConfirmAIENT"), wxYES_NO, this) == wxYES)
        this->Destroy();
}
