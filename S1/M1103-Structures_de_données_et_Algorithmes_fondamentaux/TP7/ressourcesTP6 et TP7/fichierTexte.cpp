#include "fichiertexte.h"


void associer ( UnFichierTexte& f,
                string nom)
/* relie le NOM LOGIQUE du fichier (ou "fichier logique") à son NOM SYSTEME
  -- (ou "fichier physique")
  -- : ne peut occasionner aucune erreur
*/
{
    f.nom = nom;
    f.modeOuvertureDefini = false;
}

void ouvrir ( UnFichierTexte& f,
              UnModeOuverture mode)
/*rend le fichier disponible pour les Entrées/Sorties autorisées
  -- : peut occasionner erreurDeStatut si le fichier est déjà ouvert,
  --                    erreurDeNomOuUsage : le fichier n'a pu être ouvert,
  --                          * DeNom, si le nom est illégal ou le fichier inexistant,
  --                          * DUsage, si les protections du fichiers rendent l'opération illégale
*/
{
    if (f.modeOuvertureDefini == true)
    {
        cerr << "erreurDeStatut" << endl;
        throw string("erreurDeStatut");
    }
    else
    {
        switch (mode)
        {
        case lecture :
            f.donnees.open (f.nom.c_str(), ios::in);
            break;
        case creation :
            f.donnees.open (f.nom.c_str(), ios::out | ios::trunc);
            break;
        case extension :
            f.donnees.open (f.nom.c_str(), ios::out |ios::app);
            break;
            //case modification ! NON FAIT
        default :
            break;
        }
    }
    if (f.donnees.is_open() == false)
    {
        cerr << "erreurDeNomOuUsage" << endl ;
        throw string ("erreurDeNomOuUsage");
    }
    else
    {
        f.modeOuverture = mode;
        f.modeOuvertureDefini = true;
    }
}

void fermer (UnFichierTexte& f)
/*rend le mode du fichier indéfini, et donc le fichier indisponible pour toutes
  -- les Entrées/Sorties
  -- : peut occasionner erreurDeStatut si le fichier n'est pas ouvert
  -- :                  erreurInconnue si la fermeture n'a pu se faire
*/
{
    if (f.modeOuvertureDefini == false)
    {
        cerr << "erreurDeStatut" << endl ;
        throw string ("erreurDeStatut");
    }
    else
    {
        f.donnees.close();
        if (f.donnees.is_open() == true)
        {
            cerr << "erreurInconnue" << endl ;
            throw string ("erreurInconnue");
        }
        else
        {
            f.modeOuvertureDefini = false;
            //f->.ficheEnCours = false;
        }
    }
}

void lireLigne ( UnFichierTexte& f,
                 string& chaine,
                 bool& finFichier)
/*pour les modes lecture (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a une ligne suivante (chaine suivie d'un caractère FIN_DE_LIGNE ou FIN_DE_FICHIER) :
  --		son contenu est affecté au paramètre chaine
  --		le paramètre finFichier est retourné à Faux
  -- 	S'il n'y a pas de ligne suivante (uniquement le caractère FIN_DE_FICHIER trouvé):
  --		le paramètre chaine n'est pas modifié
  --		le paramètre finFichier est retourné à Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la lecture,
  --                    erreurInconnue si la lecture s'est mal déroulée (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode lecture : on peut donc y lire
        if (getline(f.donnees, chaine))
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireCar ( UnFichierTexte& f,
               char& item,
               bool& finFichier)
/*pour les modes lecture (et modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant :
  --		son contenu est affecté au paramètre item
  --		le paramètre finFichier est retourné à Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouvée):
  --		le paramètre item n'est pas modifié
  --		le paramètre finFichier est retourné à Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la lecture,
  --                    erreurInconnue si la lecture s'est mal déroulée (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode lecture : on peut donc y lire
        if (f.donnees.get(item))
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireMot ( UnFichierTexte& f,
               string& item,
               bool& finFichier)
/*pour les modes lecture (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caractère séparateur) :
  --		son contenu est affecté au paramètre item
  --		le paramètre finFichier est retourné à Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouvée):
  --		le paramètre item n'est pas modifié
  --		le paramètre finFichier est retourné à Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la lecture,
  --                    erreurInconnue si la lecture s'est mal déroulée (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode lecture : on peut donc y lire
        if (f.donnees >> item)
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireMot ( UnFichierTexte& f,
               int& item,
               bool& finFichier)
/*pour les modes lecture (et modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caractère séparateur) :
  --		son contenu est affecté au paramètre item
  --		le paramètre finFichier est retourné à Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouvé):
  --		le paramètre item n'est pas modifié
  --		le paramètre finFichier est retourné à Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la lecture,
  --                    erreurInconnue si la lecture s'est mal déroulée (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode lecture : on peut donc y lire
        if (f.donnees >> item)
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireMot ( UnFichierTexte& f,
               float& item,
               bool& finFichier)
/*pour les modes lecture (et modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caractère séparateur) :
  --		son contenu est affecté au paramètre item
  --		le paramètre finFichier est retourné à Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouvé):
  --		le paramètre item n'est pas modifié
  --		le paramètre finFichier est retourné à Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la lecture,
  --                    erreurInconnue si la lecture s'est mal déroulée (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode lecture : on peut donc y lire
        if (f.donnees >> item)
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireMot ( UnFichierTexte& f,
               bool& item,
               bool& finFichier)
/*pour les modes lecture (et modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caractère séparateur) :
  --		son contenu est affecté au paramètre item
  --		le paramètre finFichier est retourné à Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouvé):
  --		le paramètre item n'est pas modifié
  --		le paramètre finFichier est retourné à Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la lecture,
  --                    erreurInconnue si la lecture s'est mal déroulée (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode lecture : on peut donc y lire
        if (f.donnees >> item)
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              string item)
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==lecture))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y écrire l'item, en fin de fichier
        f.donnees << item ;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              char item)
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==lecture))  // | (f.modeOuverture==modification)  non encore fait
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y écrire l'item, en fin de fichier
        f.donnees << item ;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              int item)
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==lecture))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y écrire l'item, en fin de fichier
        f.donnees << item ;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              float item)
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==lecture))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y écrire l'item, en fin de fichier
        f.donnees << item;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              bool item)
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==lecture))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y écrire l'item, en fin de fichier
        f.donnees << item;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrireLigne ( UnFichierTexte& f,
                   string item)
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier, suivi d'un caractère FIN_DE_LIGNE
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==lecture))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y écrire la chaine item, en fin de fichier,
        // suivi d'un caractère FIN_DE_LIGNE ('\n')
        f.donnees  << item << "\n" ;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

bool estOuvert (UnFichierTexte& f)
/*retourne VRAI si le fichier est ouvert, FAUX sinon */
{
    return (f.modeOuvertureDefini == true);
}

string nomSysteme (UnFichierTexte& f)
/* retourne le nom du fichier sur le disque */
{
    return f.nom;
}

void renommer (UnFichierTexte& f, string nouveauNom)
/* Valeur retournée par rename :
   . 0 si l'opération se déroule correctement,
   . valeur différente de 0 dans le cas contraire
  -- : peut occasionner ereurInconnue si l'opération échoue
*/
{
    if (rename (f.nom.c_str(), nouveauNom.c_str()) == 0)
    {
        f.nom = nouveauNom;
    }
    else
    {
        cerr << "erreurInconnue" << endl;
        throw string("erreurInconnue");
    }
}

void supprimer (UnFichierTexte& f)
/* Valeur retournée par remove :
   . 0 si l'opération se déroule correctement,
   . valeur différente de 0 dans le cas contraire
  -- : peut occasionner ereurInconnue si l'opération échoue
*/
{
    if (remove (f.nom.c_str()) != 0)
    {
        cerr << "erreurInconnue" << endl;
        throw string("erreurInconnue");
    }
}


/**Exceptions
  erreurDeStatut, erreurDeMode, erreurDeNomOuUsage, erreurInconnue;
  erreurDUsage (pour primitive réécrire non implémentée)
**/


