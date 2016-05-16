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
    txtResultat = new wxStaticText(this, ID_TXTRESULTAT_PRINCIPALE2, wxT(""), wxPoint(50, 100));
    lblX = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 10));
    lblY = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 50));
    btAddition= new wxButton(this, ID_BOUTTONADDITIONCLICK_PRINCIPALE2, wxT("Addition !"), wxPoint(200,100));
    btEffacer = new wxButton(this, ID_BOUTTONEFFACERCLICK_PRINCIPALE2, wxT("Effacer !"), wxPoint(300,100));
}

Principale2::~Principale2()
{

}

void Principale2::demandeFermeture(wxCloseEvent& evt)
{
    if (wxMessageBox(wxT("Voulez-vous quitter ?"), wxT("Confirmer"), wxYES_NO, this) == wxYES)
        this->Destroy();
}

void Principale2::bouttonAdditionClick(wxCloseEvent &evt)
{
    // TODO: programmer la somme
}

void Principale2::bouttonEffacerClick(wxCloseEvent &evt)
{
    // TODO: programmer cls
}
