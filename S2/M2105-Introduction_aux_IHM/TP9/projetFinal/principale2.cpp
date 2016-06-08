#include "principale2.h"

BEGIN_EVENT_TABLE(Principale2, wxFrame)
    EVT_BUTTON(wxID_BTABANDONNER_CLICK, Principale2::btAbandonnerClick)
    EVT_BUTTON(wxID_IMGCARTE01_CLICK, Principale2::clicImage01)
    EVT_BUTTON(wxID_IMGCARTE02_CLICK, Principale2::clicImage02)
    EVT_BUTTON(wxID_IMGCARTE03_CLICK, Principale2::clicImage03)
    EVT_BUTTON(wxID_IMGCARTE04_CLICK, Principale2::clicImage04)
    EVT_BUTTON(wxID_IMGCARTE05_CLICK, Principale2::clicImage05)
    EVT_BUTTON(wxID_IMGCARTE06_CLICK, Principale2::clicImage06)
    EVT_BUTTON(wxID_IMGCARTE07_CLICK, Principale2::clicImage07)
    EVT_BUTTON(wxID_IMGCARTE08_CLICK, Principale2::clicImage08)
    EVT_BUTTON(wxID_IMGCARTE09_CLICK, Principale2::clicImage09)
    EVT_BUTTON(wxID_IMGCARTE10_CLICK, Principale2::clicImage10)
    EVT_BUTTON(wxID_IMGCARTE11_CLICK, Principale2::clicImage11)
    EVT_BUTTON(wxID_IMGCARTE12_CLICK, Principale2::clicImage12)
    EVT_BUTTON(wxID_IMGCARTE13_CLICK, Principale2::clicImage13)
    EVT_BUTTON(wxID_IMGCARTE14_CLICK, Principale2::clicImage14)
    EVT_BUTTON(wxID_IMGCARTE15_CLICK, Principale2::clicImage15)
    EVT_BUTTON(wxID_IMGCARTE16_CLICK, Principale2::clicImage16)
    EVT_BUTTON(wxID_IMGCARTE17_CLICK, Principale2::clicImage17)
    EVT_BUTTON(wxID_IMGCARTE18_CLICK, Principale2::clicImage18)
    EVT_BUTTON(wxID_IMGCARTE19_CLICK, Principale2::clicImage19)
    EVT_BUTTON(wxID_IMGCARTE20_CLICK, Principale2::clicImage20)
    EVT_TIMER(wxID_TIMER, Principale2::OnTimer)
END_EVENT_TABLE()

Principale2::Principale2(const wxString& title) : wxFrame (NULL,
                                                           wxID_ANY,
                                                           title,
                                                           wxDefaultPosition,
                                                           wxDefaultSize,
                                                           wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxMAXIMIZE_BOX))  // bloquer le redimensionnement
{
    btAbandonner = new wxButton (this, wxID_BTABANDONNER_CLICK, wxT("Abandonner"));

    txtInfo = new wxStaticText(this, wxID_ANY, wxT("Cliquez sur une carte"));
    txtScore1 = new wxStaticText(this, wxID_ANY, wxT("Nombre de paires trouvees (sur 10) :"));
    txtScore2 = new wxStaticText(this, wxID_ANY, wxT("0"));

    Timer1.SetOwner(this, wxID_TIMER);
    Timer1.Start(1000, false);
    txtChrono = new wxStaticText(this, wxID_TIMER, wxT("60"));

    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer* plateauJeu = new wxFlexGridSizer(5,4);
    wxBoxSizer* gestionJeu = new wxBoxSizer(wxVERTICAL);

    gestionJeu->Add(btAbandonner, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 10);
    gestionJeu->Add(txtScore1, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 10);
    gestionJeu->Add(txtScore2, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 10);
    gestionJeu->Add(txtInfo, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 10);
    gestionJeu->Add(txtChrono, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 10);

    // Création des handlers pour charger les images
    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    wxPNGHandler *handlerA = new wxPNGHandler;
    wxImage::AddHandler(handlerA);
    wxPNGHandler *handlerB = new wxPNGHandler;
    wxImage::AddHandler(handlerB);
    wxPNGHandler *handlerC = new wxPNGHandler;
    wxImage::AddHandler(handlerC);
    wxPNGHandler *handlerD = new wxPNGHandler;
    wxImage::AddHandler(handlerD);
    wxPNGHandler *handlerE = new wxPNGHandler;
    wxImage::AddHandler(handlerE);
    wxPNGHandler *handlerF = new wxPNGHandler;
    wxImage::AddHandler(handlerF);
    wxPNGHandler *handlerG = new wxPNGHandler;
    wxImage::AddHandler(handlerG);
    wxPNGHandler *handlerH = new wxPNGHandler;
    wxImage::AddHandler(handlerH);
    wxPNGHandler *handlerI = new wxPNGHandler;
    wxImage::AddHandler(handlerI);
    wxPNGHandler * handlerJ = new wxPNGHandler;
    wxImage::AddHandler(handlerJ);

    // Chargement des images
    wxImage img1(wxT("carte.png")); // carte
    if (img1.Ok())
        bitm = wxBitmap(img1);
    wxImage imgA(wxT("access.png")); // access
    if (imgA.Ok())
        bitmA = wxBitmap(imgA);
    wxImage imgB(wxT("excel.png")); // excel
    if (imgB.Ok())
        bitmB = wxBitmap(imgB);
    wxImage imgC(wxT("note.png")); // note
    if (imgC.Ok())
        bitmC = wxBitmap(imgC);
    wxImage imgD(wxT("office.png")); // office
    if (imgD.Ok())
        bitmD = wxBitmap(imgD);
    wxImage imgE(wxT("onedrive.png")); // onedrive
    if (imgE.Ok())
        bitmE = wxBitmap(imgE);
    wxImage imgF(wxT("outlook.png")); // outlook
    if (imgF.Ok())
        bitmF = wxBitmap(imgF);
    wxImage imgG(wxT("powerpoint.png")); // powerpoint
    if (imgG.Ok())
        bitmG = wxBitmap(imgG);
    wxImage imgH(wxT("project.png")); // project
    if (imgH.Ok())
        bitmH = wxBitmap(imgH);
    wxImage imgI(wxT("pub.png")); // pub
    if (imgI.Ok())
        bitmI = wxBitmap(imgI);
    wxImage imgJ(wxT("word.png")); // word
    if (imgJ.Ok())
        bitmJ = wxBitmap(imgJ);

/** TODO: random function **/
    // Association des images aux cartes
    image1 = new wxBitmapButton(this, wxID_IMGCARTE01_CLICK, bitmA, wxDefaultPosition, wxSize(100, 200));
    image2 = new wxBitmapButton(this, wxID_IMGCARTE02_CLICK, bitmC, wxDefaultPosition, wxSize(100, 200));
    image3 = new wxBitmapButton(this, wxID_IMGCARTE03_CLICK, bitmB, wxDefaultPosition, wxSize(100, 200));
    image4 = new wxBitmapButton(this, wxID_IMGCARTE04_CLICK, bitmE, wxDefaultPosition, wxSize(100, 200));
    image5 = new wxBitmapButton(this, wxID_IMGCARTE05_CLICK, bitmF, wxDefaultPosition, wxSize(100, 200));
    image6 = new wxBitmapButton(this, wxID_IMGCARTE06_CLICK, bitmA, wxDefaultPosition, wxSize(100, 200));
    image7 = new wxBitmapButton(this, wxID_IMGCARTE07_CLICK, bitmH, wxDefaultPosition, wxSize(100, 200));
    image8 = new wxBitmapButton(this, wxID_IMGCARTE08_CLICK, bitmI, wxDefaultPosition, wxSize(100, 200));
    image9 = new wxBitmapButton(this, wxID_IMGCARTE09_CLICK, bitmI, wxDefaultPosition, wxSize(100, 200));
    image10 = new wxBitmapButton(this, wxID_IMGCARTE10_CLICK, bitmJ, wxDefaultPosition, wxSize(100, 200));
    image11 = new wxBitmapButton(this, wxID_IMGCARTE11_CLICK, bitmB, wxDefaultPosition, wxSize(100, 200));
    image12 = new wxBitmapButton(this, wxID_IMGCARTE12_CLICK, bitmE, wxDefaultPosition, wxSize(100, 200));
    image13 = new wxBitmapButton(this, wxID_IMGCARTE13_CLICK, bitmF, wxDefaultPosition, wxSize(100, 200));
    image14 = new wxBitmapButton(this, wxID_IMGCARTE14_CLICK, bitmD, wxDefaultPosition, wxSize(100, 200));
    image15 = new wxBitmapButton(this, wxID_IMGCARTE15_CLICK, bitmG, wxDefaultPosition, wxSize(100, 200));
    image16 = new wxBitmapButton(this, wxID_IMGCARTE16_CLICK, bitmJ, wxDefaultPosition, wxSize(100, 200));
    image17 = new wxBitmapButton(this, wxID_IMGCARTE17_CLICK, bitmC, wxDefaultPosition, wxSize(100, 200));
    image18 = new wxBitmapButton(this, wxID_IMGCARTE18_CLICK, bitmD, wxDefaultPosition, wxSize(100, 200));
    image19 = new wxBitmapButton(this, wxID_IMGCARTE19_CLICK, bitmH, wxDefaultPosition, wxSize(100, 200));
    image20 = new wxBitmapButton(this, wxID_IMGCARTE20_CLICK, bitmG, wxDefaultPosition, wxSize(100, 200));
/** END TODO **/

    // Réinitialiser le plateau de cartes
    resetJeu();

    // Positionner les cartes sur le plateau
    plateauJeu->Add(image1, 0, wxALL, 2);
    plateauJeu->Add(image2, 0, wxALL, 2);
    plateauJeu->Add(image3, 0, wxALL, 2);
    plateauJeu->Add(image4, 0, wxALL, 2);
    plateauJeu->Add(image5, 0, wxALL, 2);
    plateauJeu->Add(image6, 0, wxALL, 2);
    plateauJeu->Add(image7, 0, wxALL, 2);
    plateauJeu->Add(image8, 0, wxALL, 2);
    plateauJeu->Add(image9, 0, wxALL, 2);
    plateauJeu->Add(image10, 0, wxALL, 2);
    plateauJeu->Add(image11, 0, wxALL, 2);
    plateauJeu->Add(image12, 0, wxALL, 2);
    plateauJeu->Add(image13, 0, wxALL, 2);
    plateauJeu->Add(image14, 0, wxALL, 2);
    plateauJeu->Add(image15, 0, wxALL, 2);
    plateauJeu->Add(image16, 0, wxALL, 2);
    plateauJeu->Add(image17, 0, wxALL, 2);
    plateauJeu->Add(image18, 0, wxALL, 2);
    plateauJeu->Add(image19, 0, wxALL, 2);
    plateauJeu->Add(image20, 0, wxALL, 2);

    // Paramètre des différents sizers pour l'affichage
    topSizer->Add(plateauJeu, 0, wxALL, 5);
    topSizer->Add(gestionJeu, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 150);

    SetSizer(topSizer);
    topSizer->Fit(this);
    topSizer->SetSizeHints(this);
}

Principale2::~Principale2()
{}

void Principale2::OnTimer(wxTimerEvent& evt)
{
	if(partieDemarre)
	{
		if(score < 10) // si le score n'est pas égal à 10 (partie en cours)
	    {
	        int chrono = 60;

	        if (chrono > 0) // le chrono n'est pas terminé
	        {
	            /*chrono++;
	            wxString stChrono = (wxString::Format(wxT("%i"), 1));
	            txtChrono->SetLabel(stChrono);
                txtChrono->Show();*/
                for(chrono; chrono=0; chrono--)
                {
                    wxString stChrono = (wxString::Format(wxT("%i"), 1));
                    txtChrono->SetLabel(stChrono);
                    txtChrono->Show();
                }
	        }
	        else // fin du chrono (partie perdue)
	        {
	            image1->Hide();
	            image2->Hide();
	            image3->Hide();
	            image4->Hide();
	            image5->Hide();
	            image6->Hide();
	            image7->Hide();
	            image8->Hide();
	            image9->Hide();
	            image10->Hide();
	            image11->Hide();
	            image12->Hide();
	            image13->Hide();
	            image14->Hide();
	            image15->Hide();
	            image16->Hide();
	            image17->Hide();
	            image18->Hide();
	            image19->Hide();
	            image20->Hide();

	            txtInfo->SetLabel(wxT("Temps ecoule !"));
	        }
	    }
	}
}

// Actualiser les infos textuelles
void Principale2::actualiserInfo()
{
	// Actualiser l'affichage du score
    wxString StScore;
    StScore<<score;
    txtScore2->SetLabel(StScore);

    // Permet de débloquer le 3e clic pour valider le gain de la partie
    if(score==10)
    {
    	image1->Hide();
    	image2->Hide();
    	image3->Hide();
    	image4->Hide();
    	image5->Hide();
    	image6->Hide();
    	image7->Hide();
    	image8->Hide();
    	image9->Hide();
    	image10->Hide();
    	image11->Hide();
    	image12->Hide();
    	image13->Hide();
    	image14->Hide();
    	image15->Hide();
    	image16->Hide();
    	image17->Hide();
    	image18->Hide();
    	image19->Hide();
    	image20->Hide();

       // txtInfo->SetLabel(wxT("Bravo !"));
        btAbandonner->SetLabel(wxT("Rejouer"));
    }

	// Actualier les messages d'informations
    if(cartesRetournees == 0)
        txtInfo->SetLabel(wxT("Cliquez sur une premiere carte"));
    else
    {
        if(cartesRetournees == 1)
            txtInfo->SetLabel(wxT("Cliquez sur une seconde carte"));
        else
        {
            if(cartesRetournees == 2)
            {
                if(score == 10)
                {
                    txtInfo->SetLabel(wxT("           GAGNE !"));
                    partieDemarre = false;
                }
                else
                {
                    txtInfo->SetLabel(wxT("Cliquez sur une autre carte pour continuer"));
                }
            }
            else
            {
                if(cartesRetournees == 3)
                {
                    if(disabledPaire1)
                    {
                        image1->Hide();
                        image6->Hide();
                    }
                    if(disabledPaire2)
                    {
                        image3->Hide();
                        image11->Hide();
                    }
                    if(disabledPaire3)
                    {
                        image2->Hide();
                        image17->Hide();
                    }
                    if(disabledPaire4)
                    {
                        image14->Hide();
                        image18->Hide();
                    }
                    if(disabledPaire5)
                    {
                        image4->Hide();
                        image12->Hide();
                    }
                    if(disabledPaire6)
                    {
                        image5->Hide();
                        image13->Hide();
                    }
                    if(disabledPaire7)
                    {
                        image15->Hide();
                        image20->Hide();
                    }
                    if(disabledPaire8)
                    {
                        image7->Hide();
                        image19->Hide();
                    }
                    if(disabledPaire9)
                    {
                        image8->Hide();
                        image9->Hide();
                    }
                    if(disabledPaire10)
                    {
                        image10->Hide();
                        image16->Hide();
                    }
                }
            }
        }
    }
}

// Retourner les cartes
void Principale2::clicImage01(wxCommandEvent& evt)
{
    if(partieDemarre == false)
    {
        partieDemarre = true;
    }

    etatPaire1++; // Une carte de la paire a été retourné
    etatCarte1++;

    if(etatCarte1==1) // Si = 1, alors 1er click
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image1->SetBitmapLabel(bitmA);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image1->SetBitmapLabel(bitmA);

                etatCarte1--;
                etatPaire1--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte1--;
                    etatPaire1--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte1--;
        etatPaire1--;
    }
}

void Principale2::clicImage02(wxCommandEvent& evt)
{
	if(partieDemarre == false)
    {
        partieDemarre = true;
    }

    etatPaire3++; // Une carte de la paire a été retourné
    etatCarte2++;

    if(etatCarte2==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image2->SetBitmapLabel(bitmC);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image2->SetBitmapLabel(bitmC);

                etatCarte2--;
                etatPaire3--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte2--;
                    etatPaire3--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte2--;
        etatPaire3--;
    }
}

void Principale2::clicImage03(wxCommandEvent& evt)
{
    etatPaire2++; // Une carte de la paire a été retourné
    etatCarte3++;

    if(etatCarte3==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image3->SetBitmapLabel(bitmB);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image3->SetBitmapLabel(bitmB);

                etatCarte3--;
                etatPaire2--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte3--;
                    etatPaire2--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte3--;
        etatPaire2--;
    }
}

void Principale2::clicImage04(wxCommandEvent& evt)
{
    etatPaire5++; // Une carte de la paire a été retourné
    etatCarte4++;

    if(etatCarte4==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image4->SetBitmapLabel(bitmE);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image4->SetBitmapLabel(bitmE);

                etatCarte4--;
                etatPaire5--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte4--;
                    etatPaire5--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte4--;
        etatPaire5--;
    }
}

void Principale2::clicImage05(wxCommandEvent& evt)
{
    etatPaire6++; // Une carte de la paire a été retourné
    etatCarte5++;

    if(etatCarte5==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image5->SetBitmapLabel(bitmF);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image5->SetBitmapLabel(bitmF);

                etatCarte5--;
                etatPaire6--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte5--;
                    etatPaire6--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte5--;
        etatPaire6--;
    }
}

void Principale2::clicImage06(wxCommandEvent& evt)
{
    etatPaire1++; // Une carte de la paire a été retourné
    etatCarte6++;

    if(etatCarte6==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image6->SetBitmapLabel(bitmA);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image6->SetBitmapLabel(bitmA);

                etatCarte6--;
                etatPaire1--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte6--;
                    etatPaire1--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte6--;
        etatPaire1--;
    }
}

void Principale2::clicImage07(wxCommandEvent& evt)
{
    etatPaire8++; // Une carte de la paire a été retourné
    etatCarte7++;

    if(etatCarte7==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image7->SetBitmapLabel(bitmH);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image7->SetBitmapLabel(bitmH);

                etatCarte7--;
                etatPaire8--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte7--;
                    etatPaire8--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte7--;
        etatPaire8--;
    }
}

void Principale2::clicImage08(wxCommandEvent& evt)
{
    etatPaire9++; // Une carte de la paire a été retourné
    etatCarte8++;

    if(etatCarte8==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image8->SetBitmapLabel(bitmI);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image8->SetBitmapLabel(bitmI);

                etatCarte8--;
                etatPaire9--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte8--;
                    etatPaire9--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte8--;
        etatPaire9--;
    }
}

void Principale2::clicImage09(wxCommandEvent& evt)
{
    etatPaire9++; // Une carte de la paire a été retourné
    etatCarte9++;

    if(etatCarte9==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image9->SetBitmapLabel(bitmI);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image9->SetBitmapLabel(bitmI);

                etatCarte9--;
                etatPaire9--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte9--;
                    etatPaire9--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte9--;
        etatPaire9--;
    }
}

void Principale2::clicImage10(wxCommandEvent& evt)
{
    etatPaire10++; // Une carte de la paire a été retourné
    etatCarte10++;

    if(etatCarte10==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image10->SetBitmapLabel(bitmJ);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image10->SetBitmapLabel(bitmJ);

                etatCarte10--;
                etatPaire10--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte10--;
                    etatPaire10--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte10--;
        etatPaire10--;
    }
}

void Principale2::clicImage11(wxCommandEvent& evt)
{
    etatPaire2++; // Une carte de la paire a été retourné
    etatCarte11++;

    if(etatCarte11==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image11->SetBitmapLabel(bitmB);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image11->SetBitmapLabel(bitmB);

                etatCarte11--;
                etatPaire2--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte11--;
                    etatPaire2--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte11--;
        etatPaire2--;
    }
}

void Principale2::clicImage12(wxCommandEvent& evt)
{
    etatPaire5++; // Une carte de la paire a été retourné
    etatCarte12++;

    if(etatCarte12==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image12->SetBitmapLabel(bitmE);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image12->SetBitmapLabel(bitmE);

                etatCarte12--;
                etatPaire5--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte12--;
                    etatPaire5--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte12--;
        etatPaire5--;
    }
}

void Principale2::clicImage13(wxCommandEvent& evt)
{
    etatPaire6++; // Une carte de la paire a été retourné
    etatCarte13++;

    if(etatCarte13==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image13->SetBitmapLabel(bitmF);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image13->SetBitmapLabel(bitmF);

                etatCarte13--;
                etatPaire6--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte13--;
                    etatPaire6--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte13--;
        etatPaire6--;
    }
}

void Principale2::clicImage14(wxCommandEvent& evt)
{
    etatPaire4++; // Une carte de la paire a été retourné
    etatCarte14++;

    if(etatCarte14==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image14->SetBitmapLabel(bitmD);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image14->SetBitmapLabel(bitmD);

                etatCarte14--;
                etatPaire4--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte14--;
                    etatPaire4--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte14--;
        etatPaire4--;
    }
}

void Principale2::clicImage15(wxCommandEvent& evt)
{
    etatPaire7++; // Une carte de la paire a été retourné
    etatCarte15++;

    if(etatCarte15==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image15->SetBitmapLabel(bitmG);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image15->SetBitmapLabel(bitmG);

                etatCarte15--;
                etatPaire7--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte15--;
                    etatPaire7--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte15--;
        etatPaire7--;
    }
}

void Principale2::clicImage16(wxCommandEvent& evt)
{
    etatPaire10++; // Une carte de la paire a été retourné
    etatCarte16++;

    if(etatCarte16==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image16->SetBitmapLabel(bitmJ);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image16->SetBitmapLabel(bitmJ);

                etatCarte16--;
                etatPaire10--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte16--;
                    etatPaire10--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte16--;
        etatPaire10--;
    }
}

void Principale2::clicImage17(wxCommandEvent& evt)
{
    etatPaire3++; // Une carte de la paire a été retourné
    etatCarte17++;

    if(etatCarte17==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image17->SetBitmapLabel(bitmC);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image17->SetBitmapLabel(bitmC);

                etatCarte17--;
                etatPaire3--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte17--;
                    etatPaire3--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte17--;
        etatPaire3--;
    }
}

void Principale2::clicImage18(wxCommandEvent& evt)
{
    etatPaire4++; // Une carte de la paire a été retourné
    etatCarte18++;

    if(etatCarte18==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image18->SetBitmapLabel(bitmD);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image18->SetBitmapLabel(bitmD);

                etatCarte18--;
                etatPaire4--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte18--;
                    etatPaire4--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte18--;
        etatPaire4--;
    }
}

void Principale2::clicImage19(wxCommandEvent& evt)
{
    etatPaire8++; // Une carte de la paire a été retourné
    etatCarte19++;

    if(etatCarte19==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image19->SetBitmapLabel(bitmH);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image19->SetBitmapLabel(bitmH);

                etatCarte19--;
                etatPaire8--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte19--;
                    etatPaire8--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte19--;
        etatPaire8--;
    }
}

void Principale2::clicImage20(wxCommandEvent& evt)
{
    etatPaire7++; // Une carte de la paire a été retourné
    etatCarte20++;

    if(etatCarte20==1) // Si = 1, alors 1er click sur cette carte
    {
        if(cartesRetournees == 0)
        {
            etatPaire();
            cartesRetournees++;
            actualiserInfo();
            image20->SetBitmapLabel(bitmG);
        }
        else
        {
            if(cartesRetournees == 1)
            {
                etatPaire();
                cartesRetournees++;
                actualiserInfo();
                image20->SetBitmapLabel(bitmG);

                etatCarte20--;
                etatPaire7--;
            }
            else
            {
                if(cartesRetournees == 2)
                {
                    etatCarte20--;
                    etatPaire7--;
                    etatPaire();

                    cartesRetournees++;
                    actualiserInfo();
                    resetJeu();
                }
                else
                {
                    if(cartesRetournees == 3)
                    {
                        actualiserInfo();
                        cartesRetournees=0;
                    }
                }
            }
        }
    }
    else
    {
        etatCarte20--;
        etatPaire7--;
    }
}

void Principale2::resetJeu()
{
    btAbandonner->SetLabel(wxT("Abandonner"));

    // Réinitialiser les images
    image1->SetBitmapLabel(bitm);
    image2->SetBitmapLabel(bitm);
    image3->SetBitmapLabel(bitm);
    image4->SetBitmapLabel(bitm);
    image5->SetBitmapLabel(bitm);
    image6->SetBitmapLabel(bitm);
    image7->SetBitmapLabel(bitm);
    image8->SetBitmapLabel(bitm);
    image9->SetBitmapLabel(bitm);
    image10->SetBitmapLabel(bitm);
    image11->SetBitmapLabel(bitm);
    image12->SetBitmapLabel(bitm);
    image13->SetBitmapLabel(bitm);
    image14->SetBitmapLabel(bitm);
    image15->SetBitmapLabel(bitm);
    image16->SetBitmapLabel(bitm);
    image17->SetBitmapLabel(bitm);
    image18->SetBitmapLabel(bitm);
    image19->SetBitmapLabel(bitm);
    image20->SetBitmapLabel(bitm);

    // Réinitialiser l'état des paires
    etatPaire1 = 0;
    etatPaire2 = 0;
    etatPaire3 = 0;
    etatPaire4 = 0;
    etatPaire5 = 0;
    etatPaire6 = 0;
    etatPaire7 = 0;
    etatPaire8 = 0;
    etatPaire9 = 0;
    etatPaire10 = 0;

    // Réinitialiser les etats des cartes
    etatCarte1 = 0;
    etatCarte2 = 0;
    etatCarte3 = 0;
    etatCarte4 = 0;
    etatCarte5 = 0;
    etatCarte6 = 0;
    etatCarte7 = 0;
    etatCarte8 = 0;
    etatCarte9 = 0;
    etatCarte10 = 0;
    etatCarte11 = 0;
    etatCarte12 = 0;
    etatCarte13 = 0;
    etatCarte14 = 0;
    etatCarte15 = 0;
    etatCarte16 = 0;
    etatCarte17 = 0;
    etatCarte18 = 0;
    etatCarte19 = 0;
    etatCarte20 = 0;

    // Réinitialiser les infos
    txtInfo->SetLabel(wxT("Cliquez sur une carte"));

    // Repiocher
    cartesRetournees = 0;
}

void Principale2::btAbandonnerClick(wxCommandEvent& evt)
{
    // Réinitialiser le score
    score = 0;

    // Réinitialiser les images
    resetJeu();

    // Afficher toutes les cartes
    image1->Show();
    image2->Show();
    image3->Show();
    image4->Show();
    image5->Show();
    image6->Show();
    image7->Show();
    image8->Show();
    image9->Show();
    image10->Show();
    image11->Show();
    image12->Show();
    image13->Show();
    image14->Show();
    image15->Show();
    image16->Show();
    image17->Show();
    image18->Show();
    image19->Show();
    image20->Show();

    // Réinitialiser les etats des cartes
    etatCarte1 = 0;
    etatCarte2 = 0;
    etatCarte3 = 0;
    etatCarte4 = 0;
    etatCarte5 = 0;
    etatCarte6 = 0;
    etatCarte7 = 0;
    etatCarte8 = 0;
    etatCarte9 = 0;
    etatCarte10 = 0;
    etatCarte11 = 0;
    etatCarte12 = 0;
    etatCarte13 = 0;
    etatCarte14 = 0;
    etatCarte15 = 0;
    etatCarte16 = 0;
    etatCarte17 = 0;
    etatCarte18 = 0;
    etatCarte19 = 0;
    etatCarte20 = 0;

    // Réinitialiser l'état des paires
    disabledPaire1 = false;
    disabledPaire2 = false;
    disabledPaire3 = false;
    disabledPaire4 = false;
    disabledPaire5 = false;
    disabledPaire6 = false;
    disabledPaire7 = false;
    disabledPaire8 = false;
    disabledPaire9 = false;
    disabledPaire10 = false;

    cartesRetournees = 3;

    actualiserInfo();
    cartesRetournees = 0;
}

void Principale2::etatPaire()
{
    if(etatPaire1==2)
    {
        score++;
        disabledPaire1 = true;
    }

    if(etatPaire2==2)
    {
        score++;
        disabledPaire2 = true;
    }

    if(etatPaire3==2)
    {
        score++;
        disabledPaire3 = true;
    }

    if(etatPaire4==2)
    {
        score++;
        disabledPaire4 = true;
    }

    if(etatPaire5==2)
    {
        score++;
        disabledPaire5 = true;
    }

    if(etatPaire6==2)
    {
        score++;
        disabledPaire6 = true;
    }

    if(etatPaire7==2)
    {
        score++;
        disabledPaire7 = true;
    }

    if(etatPaire8==2)
    {
        score++;
        disabledPaire8 = true;
    }

    if(etatPaire9==2)
    {
        score++;
        disabledPaire9 = true;
    }

    if(etatPaire10==2)
    {
        score++;
        disabledPaire10 = true;
    }
}
