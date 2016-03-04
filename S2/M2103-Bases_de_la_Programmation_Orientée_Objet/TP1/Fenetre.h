#ifndef _FENETRE
#define _FENETRE
#include "/home/valentin/gtk+-3.16.7/gtk/gtk.h"
#include "/home/valentin/gtk+-3.16.7/gdk/gdk.h"
#include "Couleur.h"
#include "Image.h"

class Fenetre {

private :
// *************** Propriétés de la classe Fenetre **********************
    GtkWidget *fenetre, *contenant, *zoneDeDessin; /* fenetre et interface associé */
    GdkPixmap *dessin; /* bitmap en mémoire utilisé pour rafraîchir la fenêtre */
    GdkColor stylo; /* couleur de tracé */
    GdkColor fond; /* couleur de fond utilisée pour initialiser le bitmap */
    GdkFont* fonte; /* fonte courante */
    int largeurFenetre,hauteurFenetre; // dimensions de la fenêtre
    int sourisX, sourisY; /* coordonnées de souris */
    int boutonAppuye; /* bouton de souris */
    gboolean existe; /* positionné si la fenetre est visible à l'écran => dessins autorisés */

    /**********************   Méthodes de gestion des événements **********************
    Chaque méthode existe en deux exemplaires : un statique et un dynamique.
    Le principe utilisé est le suivant :
    La méthode statique est associée à l'événement par g_signal_connect qui n'accepte que des
    méthodes statiques. Cette méthode reçoit en dernier paramètre un pointeur sur l'objet
    qui effectue le g_signal_connect. A l'aide de ce pointeur elle peut appeler la méthode
    non statique de cet objet. Ainsi la méthode statique sert de relais pour appeler
    la méthode classique de la classe Fenetre    */

    // Evénement de configuration lié à la zone graphique sert à créer le bitmap associé
    static gboolean relais_configure_event( GtkWidget *, GdkEventConfigure *, Fenetre*);
    gboolean configure_event( GtkWidget *, GdkEventConfigure *);

    // Evénement d'exposition lié à la zone graphique sert à afficher le bitmap associé à l'écran
    static gboolean relais_expose_event( GtkWidget *, GdkEventExpose *, Fenetre*);
    gboolean expose_event( GtkWidget *, GdkEventExpose *);

    // Evénement de fermeture lié à la fenêtre sert à contrôler la fermeture par l'utilisateur
    static gboolean relais_detruire_event(GtkWidget *, GdkEventConfigure *, Fenetre*);
    gboolean detruire_event(GtkWidget *, GdkEventConfigure *);

    // Evénement de destruction lié à la fenêtre sert à fermer la fenêtre.
    // Cet événement est causé par la méthode disparait()
    static gboolean relais_supprime_event(GtkWidget *, GdkEventConfigure *, Fenetre* );
    gboolean supprime_event(GtkWidget *, GdkEventConfigure *);

    // Evénement de déplacement de la souris lié à la zone graphique
    // sert à mémoriser les coordonnées de la souris
    static gboolean relais_bouge_event(GtkWidget *, GdkEventMotion *, Fenetre*);
    gboolean bouge_event(GtkWidget *, GdkEventMotion *);

    // Evénement de clic souris lié à la zone graphique
    // sert à mémoriser les coordonnées et le bouton actif de la souris
    static gboolean relais_bouton_event(GtkWidget *, GdkEventButton *, Fenetre*);
    gboolean bouton_event(GtkWidget *, GdkEventButton *);

    // Cette méthode permet d'éviter l'appel à gtk_main() qui bloque tout.
    // Elle est appelée par chaque méthode de la classe Fenetre.
    // Elle se charge de la prise en compte des événements par la fenêtre
    // qui n'est donc plus faite normalement par gtk_main().
    void traiteEvenements() const;

    // Méthode utilisée en interne pour définir l'épaisseur des tracés dans le fenêtre
    void choixEpaisseurTrace(int);

public :
    // *************** Constructeurs de la classe Fenetre **********************
    // Constructeur permettant la déclaration sans paramètres (pour les débutants)
    Fenetre();
    // Constructeur avec titre, taille (largeur, hauteur),
    //    position (coordonnées du coin supérieur gauche),couleur du fond (composantes RVB)
    Fenetre(const char *, int, int, int=0, int=0, int=65535, int=65535, int=65535);

    // *********** Méthodes d'affichage, suppression et mise à jour des fenetres ******************
    // Création de la fenêtre : à n'utiliser qu'avec le constructeur sans paramètres
    void apparait(const char* ="Sans nom", int=400, int=400, int=0, int=0, int=65535, int=65535, int=65535);
    void disparait(); // suppression de la fenêtre
    void miseAJour(); // méthode inutile avec gtk car tout dessin est immédiatement visible
    void effacer(); // effacement de toute la fenêtre

    // *********** Méthodes de dimension et position des fenetres **********************
    void deplacerEn (int, int);  // placement de la fenêtre à l'écran (coordonnées du coin supérieur gauche)
    int coordEnX() const; // récupération des coordonnées de la fenêtre à l'écran
    int coordEnY() const;
    int hauteur() const; // récupération des dimensions de la fenêtre
    int largeur() const;

    // *********** Méthodes concernant les couleurs des fenêtres **********************
    Couleur couleurFond() const;  // récupération de la couleur de fond de la fenêtre
    void choixCouleurTrace(int, int, int); // choix de la couleur pour les tracés à venir
    void choixCouleurTrace(Couleur);

    // *********** Méthodes de dessin : lignes, arcs de cercle,
    //             ellipses pleines et rectangles pleins     **************************
    // les paramètres sont les coordonnées du point de départ et d'arrivée
    // et l'épaisseur de la ligne.
    void traceLigne(int, int, int, int, int=1);
    // les paramètres sont les coordonnées du coin supérieur gauche et les dimensions
    // (largeur, hauteur) du rectangle dans lequel s'inscrit l'ellipse
    // ainsi que les angles de début et de fin de tracé de l'arc en 1/64 degrés
    // et enfin l'épaisseur de la ligne.
    void traceArc(int, int, int, int, int=0, int=360*64, int=1);
    // les paramètres sont les coordonnées du coin supérieur gauche et les dimensions
    // (largeur, hauteur) du rectangle dans lequel s'inscrit l'ellipse à remplir.
    void remplitEllipse(int,int,int,int);
    // les paramètres sont les coordonnées du coin supérieur gauche et les dimensions
    // (largeur, hauteur) du rectangle a remplir.
    void remplitRectangle(int,int,int,int);

    // *********** Méthodes concernant les images **********************
    // Les paramètres sont le nom du fichier contenant l'image (jpeg par exemple)
	//           ou un objet de classe Image
    // Les deux derniers paramètres définissent la position de l'image dans la fenêtre
    void afficheImage(const char *, int=0, int=0);
    void afficheImage(Image, int=0, int=0);

    // ******** Méthodes d'écriture de textes : chaînes de caractères et entiers  ******
    // les deux premiers paramètres définissent la position du texte dans la fenêtre
    // Le texte sera totalement au dessus et à droite de ce point
    void ecrit(int, int, const char*);
    void ecrit(int, int, int);

    // *********** Méthodes relatives aux écritures de textes ********************
    // choix d'une fonte avec nom , taille , gras(O/N) , italique(O/N)
    void choixFonte(const char *, int=12, bool=false, bool=false);
    int longueurTexte(const char *) const; // récupération des tailles en pixels des textes
    int hauteurTexte(const char *) const;

    // *********** Méthodes utilisées par la classe Souris ****************
    int getSourisX(); // retourne la dernière position en X de la souris
    int getSourisY(); // retourne la dernière position en Y de la souris
    int getSourisBouton();// retourne le dernier bouton activé de la souris

    // *********** Méthode permettant d'attendre (délai en ms) ***************
    void delai(int) const;

};
#endif
