#include "principale2.h"

BEGIN_EVENT_TABLE(Principale2, wxFrame)
    EVT_CLOSE(Principale2::demandeFermeture)
    EVT_BUTTON(300, Principale2::bouttonAdditionClick)
    EVT_BUTTON(400, Principale2::bouttonEffacerClick)
END_EVENT_TABLE()

Principale2::Principale2(const wxString& title) : wxFrame (NULL,
                                                           wxID_ANY, // identifiant de l'objet qui sera créé, par défaut : wxID_ANY,
                                                           title)  // titre de la fenêtre
{
    txtX = new wxStaticText(this, wxID_ANY, wxT("x ="), wxPoint(10,10));
    txtY = new wxStaticText(this, wxID_ANY, wxT("y ="), wxPoint(10,50));
    txtXPlusY = new wxStaticText(this, wxID_ANY, wxT("x + y ="), wxPoint(10,100));
    txtResultat = new wxStaticText(this, wxID_ANY, wxT(""), wxPoint(50, 100));
    lblX = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 10));
    lblY = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(50, 50));
    btAddition= new wxButton(this, 300, wxT("Addition !"), wxPoint(200,100));
    btEffacer = new wxButton(this, 400, wxT("Effacer !"), wxPoint(300,100));
}

Principale2::~Principale2()
{}

void Principale2::demandeFermeture(wxCloseEvent& evt)
{
    if (wxMessageBox(wxT("Voulez-vous quitter ?"), wxT("Confirmer"), wxYES_NO, this) == wxYES)
        this->Destroy();
}

void Principale2::bouttonAdditionClick(wxCloseEvent &evt)
{
    double x,y,somme;
    bool vraiX,vraiY;
    wxString StX,StY,StS;

    StX = lblX->GetValue(); // On stocke dans StX la valeur que l'utilisateur a rentré dans la zone de saisie qui est de type wxString
    vraiX=StX.ToDouble(&x); // On verifie avec un booléen si notre valeur est bien de type double. Si c'est le cas il renvoie vrai et stocke la valeur dans la variable x;
    StY = lblY->GetValue(); // On stocke dans StY la valeur que l'utilisateur a rentré dans la zone de saisie qui est de type wxString
    vraiY=StY.ToDouble(&y); // On verifie avec un booléen si notre valeur est bien de type double. Si c'est le cas il renvoie vrai et stocke la valeur dans la variable y;

    // On doit verifier avec une condition si les deux valeurs stockées dans x et y sont bien de type double. Si c'est le cas on peut alors faire l'addition
    if (vraiX && vraiY)
    {
        somme = x + y; // Permet d'effectuer le calcul des deux valeurs
        StS.Printf(wxT("%lf"), somme); // La méthode Printf permet de convertir la valeur de type double stockée dans la variable somme et ainsi de l'afficher dans la zone de résultat(Resultat)
        txtResultats->SetLabel(StS); // On met la valeur StS de type wxString dans Resultat
    }
    else
    {
        txtResultats->SetLabel(wxT(" ")); // Si une des deux valeurs n'est pas valide on ne mettra rien dans la chaine de caractère, il n'y aura donc pas de resultat
        wxMessageBox(wxT("Un des deux operandes ne contient pas de valeur ou la saisie est invalide"),wxT("Calcul impossible"));
    }
}

void Principale2::bouttonEffacerClick(wxCloseEvent &evt)
{
    lblX->SetLabel(wxT(" ")); // Cela permet d'effacer tout ce que l'utilisateur aurait pu entrer comme valeur dans xCl (zone correspondant à la valeur du x)
    lblY->SetLabel(wxT(" ")); // Cela permet d'effacer tout ce que l'utilisateur aurait pu entrer comme valeur dans yCl (zone correspondant à la valeur du y)
    txtResultats->SetLabel(wxT(" ")); // Permet d'effacer les résultats encore inscrits dans la zone Resultat.
}
