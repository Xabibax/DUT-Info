#include "principale2.h"

BEGIN_EVENT_TABLE(Principale2,wxFrame)
    EVT_CLOSE(Principale2::demandeFermeture)
    EVT_BUTTON(1, Principale2::btAdditionClick)
    EVT_BUTTON(2, Principale2::btEffacerClick)
    EVT_SIZE(Principale2::sizeEvent)
END_EVENT_TABLE()


Principale2::Principale2(const wxString& title) : wxFrame (NULL,
                                                           wxID_ANY, // Identifiant de l'objet qui sera créé, par défaut : wxID_ANY,
                                                           title)  // Titre de la fenêtre
{
    txtX = new wxStaticText(this, wxID_ANY, wxT("x ="), wxPoint(10,10));
    txtY = new wxStaticText(this, wxID_ANY, wxT("y ="), wxPoint(10,50));
    txtAddition = new wxStaticText(this, wxID_ANY, wxT("x + y ="), wxPoint(10,100));
    txtResultat = new wxStaticText(this, wxID_ANY, wxT(" "), wxPoint(50,100));
    lblX = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 10));
    lblY = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 50));
    btAddition = new wxButton(this,1, wxT("Addition !"), wxPoint(10,150));
    btEffacer = new wxButton(this,2, wxT("Effacer !"), wxPoint(100,150));
}

// Demande à l'utilisateur s'il confirme la fermeture de la fenêtre avec la fonction wxMessageBox
void Principale2::demandeFermeture(wxCloseEvent& evt)
{
    if (wxMessageBox(wxT("Voulez-vous quitter ?"), wxT("Confirmer"), wxYES_NO, this) == wxYES)
        this->Destroy();
}

Principale2::~Principale2()
{}

/* Méthode qui permet d'additionner les deux nombres que
   l'utilisateur a entrés dans les zones de texte prévues à cet effet lblX et lblY en renvoyant un booléen vrai si les valeurs sont correctes (nombres)
   ou dans le cas contraire (lettres) affiche un message d'erreur*/
void Principale2::btAdditionClick(wxCommandEvent& evt)
{
    // VARIABLES
    double txtXSave, txtYSave;
    wxString StX,StY,StS;

    // TRAITEMENTS
    StX = lblX->GetValue();
    StY = lblY->GetValue();

    // On vérifie si les valeurs saisies sont des nombres (base = 10)
    if (StX.ToDouble(&txtXSave/*, 10*/) && StY.ToDouble(&txtYSave/*, 10*/))
    {
        StS<<txtXSave+txtYSave;
        txtResultat->SetLabel(StS); // On met la valeur StS de type wxString dans Resultat
    }
    else
    {
        txtResultat->SetLabel(wxT(" ")); // On efface s'il y avait déjà un précédent résultat de calculé.
        wxMessageBox(wxT("Un des deux operandes ne contient pas de valeur ou la saisie est invalide"), wxT("Calcul impossible"));
    }
}

// Cette méthode permet d'effacer toutes valeurs auparavant entrées par l'utilisateur à l'aide du Bouton Effacer!
void Principale2::btEffacerClick(wxCommandEvent& evt)
{
    lblX->SetLabel(wxT(" ")); // ou lblX->Clear()
    lblY->SetLabel(wxT(" "));
    txtResultat->SetLabel(wxT(" "));
}

void Principale2::sizeEvent(wxSizeEvent& evt)
{
	this->Fit();
	evt.Skip();
}
