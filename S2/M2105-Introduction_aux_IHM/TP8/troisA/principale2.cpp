#include "principale2.h"

BEGIN_EVENT_TABLE(Principale2, wxFrame)
    EVT_CLOSE(Principale2::demandeFermeture)
    EVT_BUTTON(wxID_BTADDITION_CLICK, Principale2::btAdditionClick)
    EVT_BUTTON(wxID_BTEFFACER_CLICK, Principale2::btEffacerClick)
END_EVENT_TABLE()

Principale2::Principale2(const wxString& title) : wxFrame (NULL,
                                                           wxID_ANY, // Identifiant de l'objet qui sera cr��, par d�faut : wxID_ANY,
                                                           title,
                                                           wxDefaultPosition,
                                                           wxDefaultSize,
                                                           wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxMAXIMIZE_BOX)) // fen�tre non redimensionnable
{
    // Cr�ation des diff�rents contr�les
    txtX = new wxStaticText(this, wxID_ANY, wxT("x ="));
    txtY = new wxStaticText(this, wxID_ANY, wxT("y ="));
    txtAddition = new wxStaticText(this, wxID_ANY, wxT("x + y ="));
    txtResultat = new wxStaticText(this, wxID_ANY, wxT(""));
    lblX = new wxTextCtrl(this, wxID_ANY, wxT(""));
    lblY = new wxTextCtrl(this, wxID_ANY, wxT(""));
    btAddition = new wxButton(this, wxID_BTADDITION_CLICK, wxT("Addition !"));
    btEffacer = new wxButton(this, wxID_BTEFFACER_CLICK, wxT("Effacer !"));

    // Cr�ation des diff�rents sizers
    wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	wxFlexGridSizer* sizerSaisie = new wxFlexGridSizer(2, 2, 0, 0);
	sizerSaisie->AddGrowableCol(1);
	sizerSaisie->AddGrowableRow(2);

	//Ajout au sizer, align� � droite/gauche, centr� verticalement et avec une bordure de 5 partout
	sizerSaisie->Add(txtX, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
	sizerSaisie->Add(lblX, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5);
	sizerSaisie->Add(txtY, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
	sizerSaisie->Add(lblY, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5);

	sizerSaisie->Add(txtAddition, 0, wxALL, 5);
	sizerSaisie->Add(txtResultat, 0, wxALL, 5);

    buttonSizer->Add(btAddition, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 10);
    buttonSizer->Add(btEffacer, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 10);

	topSizer->Add(sizerSaisie, 0, 20);
    topSizer->Add(buttonSizer, 0, 10);

    /// Param�trage du topSizer �PR�S les autres sizers !
    SetSizer(topSizer); // use topSizer for layout
    topSizer->Fit(this); // fit the dialog to the contents
    topSizer->SetSizeHints(this); // set hints to honor min size
}

// Demande � l'utilisateur s'il confirme la fermeture de la fen�tre avec la fonction wxMessageBox
void Principale2::demandeFermeture(wxCloseEvent& evt)
{
    if (wxMessageBox(wxT("Voulez-vous quitter ?"), wxT("Confirmer"), wxYES_NO, this) == wxYES)
        this->Destroy();
}

Principale2::~Principale2()
{}

/* M�thode qui permet d'additionner les deux nombres que
   l'utilisateur a entr�s dans les zones de texte pr�vues � cet effet lblX et lblY en renvoyant un bool�en vrai si les valeurs sont correctes (nombres)
   ou dans le cas contraire (lettres) affiche un message d'erreur
*/
void Principale2::btAdditionClick(wxCommandEvent& evt)
{
    // VARIABLES
    long txtXSave, txtYSave;
    wxString StX,StY,StS;

    // TRAITEMENTS
    StX = lblX->GetValue();
    StY = lblY->GetValue();

    // On v�rifie si les valeurs saisies sont des nombres (base = 10)
    if (StX.ToLong(&txtXSave, 10) && StY.ToLong(&txtYSave, 10))
    {
        StS<<txtXSave+txtYSave;
        txtResultat->SetLabel(StS); // On met la valeur StS de type wxString dans Resultat
    }
    else
    {
        txtResultat->SetLabel(wxT(" ")); // On efface s'il y avait d�j� un pr�c�dent r�sultat de calcul�.
        wxMessageBox(wxT("Un des deux operandes ne contient pas de valeur ou la saisie est invalide"), wxT("Calcul impossible"));
    }
}

void Principale2::btEffacerClick(wxCommandEvent& evt)
{
    lblX->SetLabel(wxT(" ")); // ou lblX->Clear()
    lblY->SetLabel(wxT(" "));
    txtResultat->SetLabel(wxT(" "));
}
