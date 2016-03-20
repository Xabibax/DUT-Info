#ifndef _FENETRE
#define _FENETRE
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "Couleur.h"
#include "Image.h"

class Fenetre {

private :
// *************** Propri�t�s de la classe Fenetre **********************
    GtkWidget *fenetre, *contenant, *zoneDeDessin; /* fenetre et interface associ� */
    GdkPixmap *dessin; /* bitmap en m�moire utilis� pour rafra�chir la fen�tre */
    GdkColor stylo; /* couleur de trac� */
    GdkColor fond; /* couleur de fond utilis�e pour initialiser le bitmap */
    GdkFont* fonte; /* fonte courante */
    int largeurFenetre,hauteurFenetre; // dimensions de la fen�tre
    int sourisX, sourisY; /* coordonn�es de souris */
    int boutonAppuye; /* bouton de souris */
    gboolean existe; /* positionn� si la fenetre est visible � l'�cran => dessins autoris�s */

    /**********************   M�thodes de gestion des �v�nements **********************
    Chaque m�thode existe en deux exemplaires : un statique et un dynamique.
    Le principe utilis� est le suivant :
    La m�thode statique est associ�e � l'�v�nement par g_signal_connect qui n'accepte que des
    m�thodes statiques. Cette m�thode re�oit en dernier param�tre un pointeur sur l'objet
    qui effectue le g_signal_connect. A l'aide de ce pointeur elle peut appeler la m�thode 
    non statique de cet objet. Ainsi la m�thode statique sert de relais pour appeler 
    la m�thode classique de la classe Fenetre    */
    
    // Ev�nement de configuration li� � la zone graphique sert � cr�er le bitmap associ�
    static gboolean relais_configure_event( GtkWidget *, GdkEventConfigure *, Fenetre*);
    gboolean configure_event( GtkWidget *, GdkEventConfigure *);
    
    // Ev�nement d'exposition li� � la zone graphique sert � afficher le bitmap associ� � l'�cran
    static gboolean relais_expose_event( GtkWidget *, GdkEventExpose *, Fenetre*);
    gboolean expose_event( GtkWidget *, GdkEventExpose *);
    
    // Ev�nement de fermeture li� � la fen�tre sert � contr�ler la fermeture par l'utilisateur
    static gboolean relais_detruire_event(GtkWidget *, GdkEventConfigure *, Fenetre*);
    gboolean detruire_event(GtkWidget *, GdkEventConfigure *);
    
    // Ev�nement de destruction li� � la fen�tre sert � fermer la fen�tre.
    // Cet �v�nement est caus� par la m�thode disparait()
    static gboolean relais_supprime_event(GtkWidget *, GdkEventConfigure *, Fenetre* );
    gboolean supprime_event(GtkWidget *, GdkEventConfigure *);
    
    // Ev�nement de d�placement de la souris li� � la zone graphique 
    // sert � m�moriser les coordonn�es de la souris
    static gboolean relais_bouge_event(GtkWidget *, GdkEventMotion *, Fenetre*);
    gboolean bouge_event(GtkWidget *, GdkEventMotion *);
    
    // Ev�nement de clic souris li� � la zone graphique 
    // sert � m�moriser les coordonn�es et le bouton actif de la souris
    static gboolean relais_bouton_event(GtkWidget *, GdkEventButton *, Fenetre*);
    gboolean bouton_event(GtkWidget *, GdkEventButton *);
    
    // Cette m�thode permet d'�viter l'appel � gtk_main() qui bloque tout.
    // Elle est appel�e par chaque m�thode de la classe Fenetre.
    // Elle se charge de la prise en compte des �v�nements par la fen�tre
    // qui n'est donc plus faite normalement par gtk_main().
    void traiteEvenements() const;  

    // M�thode utilis�e en interne pour d�finir l'�paisseur des trac�s dans le fen�tre
    void choixEpaisseurTrace(int);
    
public :
    // *************** Constructeurs de la classe Fenetre **********************
    // Constructeur permettant la d�claration sans param�tres (pour les d�butants)
    Fenetre();
    // Constructeur avec titre, taille (largeur, hauteur), 
    //    position (coordonn�es du coin sup�rieur gauche),couleur du fond (composantes RVB)
    Fenetre(const char *, int, int, int=0, int=0, int=65535, int=65535, int=65535);

    // *********** M�thodes d'affichage, suppression et mise � jour des fenetres ******************
    // Cr�ation de la fen�tre : � n'utiliser qu'avec le constructeur sans param�tres
    void apparait(const char* ="Sans nom", int=400, int=400, int=0, int=0, int=65535, int=65535, int=65535);
    void disparait(); // suppression de la fen�tre
    void miseAJour(); // m�thode inutile avec gtk car tout dessin est imm�diatement visible
    void effacer(); // effacement de toute la fen�tre

    // *********** M�thodes de dimension et position des fenetres **********************
    void deplacerEn (int, int);  // placement de la fen�tre � l'�cran (coordonn�es du coin sup�rieur gauche)
    int coordEnX() const; // r�cup�ration des coordonn�es de la fen�tre � l'�cran
    int coordEnY() const;
    int hauteur() const; // r�cup�ration des dimensions de la fen�tre
    int largeur() const;
    
    // *********** M�thodes concernant les couleurs des fen�tres **********************
    Couleur couleurFond() const;  // r�cup�ration de la couleur de fond de la fen�tre
    void choixCouleurTrace(int, int, int); // choix de la couleur pour les trac�s � venir
    void choixCouleurTrace(Couleur);

    // *********** M�thodes de dessin : lignes, arcs de cercle, 
    //             ellipses pleines et rectangles pleins     **************************
    // les param�tres sont les coordonn�es du point de d�part et d'arriv�e 
    // et l'�paisseur de la ligne.
    void traceLigne(int, int, int, int, int=1);
    // les param�tres sont les coordonn�es du coin sup�rieur gauche et les dimensions 
    // (largeur, hauteur) du rectangle dans lequel s'inscrit l'ellipse 
    // ainsi que les angles de d�but et de fin de trac� de l'arc en 1/64 degr�s 
    // et enfin l'�paisseur de la ligne.
    void traceArc(int, int, int, int, int=0, int=360*64, int=1);
    // les param�tres sont les coordonn�es du coin sup�rieur gauche et les dimensions 
    // (largeur, hauteur) du rectangle dans lequel s'inscrit l'ellipse � remplir.
    void remplitEllipse(int,int,int,int);
    // les param�tres sont les coordonn�es du coin sup�rieur gauche et les dimensions 
    // (largeur, hauteur) du rectangle a remplir.
    void remplitRectangle(int,int,int,int);
    
    // *********** M�thodes concernant les images **********************
    // Les param�tres sont le nom du fichier contenant l'image (jpeg par exemple) 
	//           ou un objet de classe Image
    // Les deux derniers param�tres d�finissent la position de l'image dans la fen�tre
    void afficheImage(const char *, int=0, int=0);
    void afficheImage(Image, int=0, int=0);
    
    // ******** M�thodes d'�criture de textes : cha�nes de caract�res et entiers  ******
    // les deux premiers param�tres d�finissent la position du texte dans la fen�tre
    // Le texte sera totalement au dessus et � droite de ce point
    void ecrit(int, int, const char*);
    void ecrit(int, int, int);
 
    // *********** M�thodes relatives aux �critures de textes ********************
    // choix d'une fonte avec nom , taille , gras(O/N) , italique(O/N)
    void choixFonte(const char *, int=12, bool=false, bool=false); 
    int longueurTexte(const char *) const; // r�cup�ration des tailles en pixels des textes
    int hauteurTexte(const char *) const;

    // *********** M�thodes utilis�es par la classe Souris ****************
    int getSourisX(); // retourne la derni�re position en X de la souris
    int getSourisY(); // retourne la derni�re position en Y de la souris
    int getSourisBouton();// retourne le dernier bouton activ� de la souris
    
    // *********** M�thode permettant d'attendre (d�lai en ms) ***************
    void delai(int) const;  

};
#endif
