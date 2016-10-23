#ifndef FICHIERSTEXTE_H
#define FICHIERSTEXTE_H
#include <iostream>
#include <fstream>
using namespace std;


enum UnModeOuverture {lecture, creation, extension};
struct UnFichierTexte
{
    string nom;                    // Nom système du fichier
    UnModeOuverture modeOuverture; // Précise le mode d'ouverture : lecture, creation, ...
    bool modeOuvertureDefini;      // Indique si le mode d'ouverture du fichier est défini ou pas
    fstream donnees;               // les données du fichier
} ;

void associer ( UnFichierTexte& f,
                string nom);
/* relie le NOM LOGIQUE du fichier (ou "fichier logique") à son NOM SYSTEME
  -- (ou "fichier physique")
  -- : ne peut occasionner aucune erreur
*/

void ouvrir ( UnFichierTexte& f,
              UnModeOuverture mode);
/*rend le fichier disponible pour les Entrées/Sorties autorisées
  -- : peut occasionner erreurDeStatut si le fichier est déjà ouvert,
  --                    erreurDeNomOuUsage : le fichier n'a pu être ouvert,
  --                          * DeNom, si le nom est illégal ou le fichier inexistant,
  --                          * DUsage, si les protections du fichiers rendent l'opération illégale
*/

void fermer ( UnFichierTexte& f);
/*rend le mode du fichier indéfini, et donc le fichier indisponible pour toutes
  -- les Entrées/Sorties
  -- : peut occasionner erreurDeStatut si le fichier n'est pas ouvert
  -- :                  erreurInconnue si la fermeture n'a pu se faire (fichier corrompu...)
*/

void lireLigne ( UnFichierTexte& f,
                 string& chaine,
                 bool& finFichier);
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

void lireCar ( UnFichierTexte& f,
               char& item,
               bool& finFichier);
/*pour les modes lecture (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant :
  --		son contenu est affecté au paramètre item
  --		le paramètre finFichier est retourné à Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouvée):
  --		le paramètre item n'est pas modifié
  --		le paramètre finFichier est retourné à Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la lecture,
  --                    erreurInconnue si la lecture s'est mal déroulée (fichier corrompu...)
*/

void lireMot ( UnFichierTexte& f,
               string& item,
               bool& finFichier);
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

void lireMot ( UnFichierTexte& f,
               int& item,
               bool& finFichier);
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

void lireMot ( UnFichierTexte& f,
               float& item,
               bool& finFichier);
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

void lireMot ( UnFichierTexte& f,
               bool& item,
               bool& finFichier);
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

void ecrire ( UnFichierTexte& f,
              string item);
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/

void ecrire ( UnFichierTexte& f,
              char item);
/*pour les modes creation et extension, le contenu du paramètre chaine
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/

void ecrire ( UnFichierTexte& f,
              int item);
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/

void ecrire ( UnFichierTexte& f,
              float item);
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/

void ecrire ( UnFichierTexte& f,
              bool item);
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/

void ecrireLigne ( UnFichierTexte& f,
                   string item);
/*pour les modes creation et extension, le contenu du paramètre item
  -- est enregistré en fin de fichier, suivi d'un caractère FIN_DE_LIGNE
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'écriture,
  --                    erreurInconnue si l'écriture s'est mal déroulée (plus d'espace disque, fichier corrompu...)
*/

bool estOuvert (UnFichierTexte& f);
/* retourne VRAI si le fichier est ouvert, FAUX sinon */

string nomSysteme (UnFichierTexte& f);
/* retourne le nom du fichier sur le disque */

void renommer (UnFichierTexte& f, string nouveauNom);
/* Change le nom du fichier f.nom par nouveauNom, où f est le nom logique d'un fichier texte.
   Opération effectuée directement sur le fichier, sans utilisation de flot C++.
   Si f.nom et nouveauNom précisent différentes localisations (répertoires),
   le système déplace le fichier vers le nouvel emplacement.
   Si nouveauNom fait référence à un fichier existant, la fonction peut échouer ou écraser
   le fichier existant, cela dépend du système d'exploitation.
   Le fichier f doit être *fermé* pour que l'opération réussisse.
  -- : peut occasionner ereurInconnue si l'opération échoue
*/

void supprimer (UnFichierTexte& f)  ;
/* Supprime le fichier de nom système associé au fichier logique f.
   Opération effectuée directement sur le fichier, sans utilisation de flot C++.
   Le fichier doit être *fermé* pour que l'opération réussisse.
  -- : peut occasionner ereurInconnue si l'opération échoue
*/

/**Exceptions
  erreurDeStatut, erreurDeMode, erreurDeNomOuUsage, erreurInconnue;
  erreurDUsage (pour primitive réécrire non implémentée)
**/

#endif //FICHIERSTEXTE_H
