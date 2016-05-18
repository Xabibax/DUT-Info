#include "principale2.h"
// Peuplement de la table d'événements
BEGIN_EVENT_TABLE(Principale2,wxFrame)

    EVT_CLOSE(Principale2 :: demandeFermeture)
    EVT_BUTTON(300,Principale2 :: demandeAddition)
    EVT_BUTTON(400,Principale2 :: demandeEffacer)

END_EVENT_TABLE()


Principale2::Principale2(const wxString& title) : wxFrame (NULL,
            wxNewId(), // Identifiant de l'objet qui sera créé, par défaut : wxNewId(),
            title)  // Titre de la fenêtre
{
    x = new wxStaticText(this, wxNewId(), wxT("x ="), wxPoint(10,10));
    y = new wxStaticText(this, wxNewId(), wxT("y ="), wxPoint(10,50));
    Addition = new wxStaticText(this, wxNewId(), wxT("x + y ="), wxPoint(10,100));
    Resultat = new wxStaticText(this, wxNewId(), wxT(" "), wxPoint(50,100));
    xCl = new wxTextCtrl(this, wxNewId(), wxT(""), wxPoint(50, 10));
    yCl = new wxTextCtrl(this, wxNewId(), wxT(""), wxPoint(50, 50));
    bouton1 = new wxButton(this,300, wxT("Addition !"), wxPoint(200,100));
    bouton2 = new wxButton(this,400, wxT("Effacer !"), wxPoint(300,100));
}

// Demande à l'utilisateur s'il confirme la fermeture de la fenêtre avec la fonction wxMessageBox
void Principale2 :: demandeFermeture(wxCloseEvent & evt)
{
    int reponse = wxMessageBox(wxT("Voulez-vous quitter le programme ?"),
                               wxT("Confirmation de la fermeture"),
                               wxYES_NO);
    if (reponse == wxYES)
    {
        this->Destroy();
    }
}

// Le destructeur
Principale2 :: ~Principale2()
{

}

// Méthode qui permet d'additionner les deux nombres que
// l'utilisateur a entrés dans les zones de texte prévues à cet effet xCl et yCl en renvoyant un booléen vrai si les valeurs sont correctes
// ou dans le cas contraire affiche un message d'erreur

void Principale2 :: demandeAddition(wxCommandEvent & evt)
{
    // VARIABLES
    double x,y,somme;
    bool vraiX,vraiY;
    wxString StX,StY,StS;

    // TRAITEMENTS
    StX = xCl->GetValue(); // On stocke dans StX la valeur que l'utilisateur a rentré dans la zone de saisie qui est de type wxString
    vraiX=StX.ToDouble(&x); // On verifie avec un booléen si notre valeur est bien de type double. Si c'est le cas il renvoie vrai et stocke la valeur dans la variable x;
    StY = yCl->GetValue(); // On stocke dans StY la valeur que l'utilisateur a rentré dans la zone de saisie qui est de type wxString
    vraiY=StY.ToDouble(&y); // On verifie avec un booléen si notre valeur est bien de type double. Si c'est le cas il renvoie vrai et stocke la valeur dans la variable y;

    // On doit verifier avec une condition si les deux valeurs stockées dans x et y sont bien de type double. Si c'est le cas on peut alors faire l'addition
    if (vraiX && vraiY)
    {
        somme = x + y; // Permet d'effectuer le calcul des deux valeurs
        StS.Printf(wxT("%lf"), somme); // La méthode Printf permet de convertir la valeur de type double stockée dans la variable somme et ainsi de l'afficher dans la zone de résultat(Resultat)
        Resultat->SetLabel(StS); // On met la valeur StS de type wxString dans Resultat

    }
    else
    {
        Resultat->SetLabel(wxT(" ")); // Si une des deux valeurs n'est pas valide on ne mettra rien dans la chaine de caractère, il n'y aura donc pas de resultat
        wxMessageBox(wxT("Un des deux operandes ne contient pas de valeur ou la saisie est invalide"),wxT("Calcul impossible"));

    }
}

// Cette méthode permet d'effacer toutes valeurs auparavant entrées par l'utilisateur à l'aide du Bouton Effacer!
void Principale2 :: demandeEffacer(wxCommandEvent & evt)
{
    xCl->SetLabel(wxT(" ")); // Cela permet d'effacer tout ce que l'utilisateur aurait pu entrer comme valeur dans xCl (zone correspondant à la valeur du x)
    yCl->SetLabel(wxT(" ")); // Cela permet d'effacer tout ce que l'utilisateur aurait pu entrer comme valeur dans yCl (zone correspondant à la valeur du y)
    Resultat->SetLabel(wxT(" ")); // Permet d'effacer les résultats encore inscrits dans la zone Resultat.

}

