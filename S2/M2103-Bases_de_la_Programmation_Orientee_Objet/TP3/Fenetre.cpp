#include <stdio.h>
// Pour Windows : remplacer #include <unistd.h>  par #include <windows.h>
//#include <windows.h>
#include <unistd.h>
#include <string.h>
#include "Fenetre.h"

//****************************************************************
// *****   Méthodes associées aux événements (callbacks)
// *****   Ces méthodes utilisent une méthode relais statique
// *****   pour prendre en compte les événements.
//****************************************************************
gboolean Fenetre::detruire_event(GtkWidget *widget, GdkEventConfigure *event)
{ // l'utilisateur veut fermer la fenêtre
    return FALSE; // fermeture par l'utilisateur acceptée
    }
gboolean Fenetre::relais_detruire_event(GtkWidget *widget, GdkEventConfigure *event, Fenetre* objet) {
    return objet->detruire_event(widget, event);
    }

gboolean Fenetre::supprime_event(GtkWidget *widget, GdkEventConfigure *event)
{ // la fenêtre vient de disparaître
    return FALSE;
    }
gboolean Fenetre::relais_supprime_event(GtkWidget *widget, GdkEventConfigure *event, Fenetre* objet) {
    return objet->detruire_event(widget, event);
    }

gboolean Fenetre::configure_event(GtkWidget *widget, GdkEventConfigure *event)
{ // init => on crée une image mémoire pour le rafraîchissement
  if (dessin!=NULL) // enlever l'ancien bitmap
      g_object_unref (dessin);
  // en créer un nouveau
  dessin = gdk_pixmap_new (widget->window,
			   widget->allocation.width,
			   widget->allocation.height, -1);
  // l'image est effacée = remplie par la couleur de fond
  gdk_gc_set_rgb_fg_color(widget->style->bg_gc[GTK_STATE_NORMAL],&fond);
  gdk_draw_rectangle (dessin, widget->style->bg_gc[GTK_STATE_NORMAL],
              TRUE, 0, 0,
              widget->allocation.width, widget->allocation.height);
  return TRUE;
}
gboolean Fenetre::relais_configure_event(GtkWidget *widget, GdkEventConfigure *event, Fenetre* objet) {
    return objet->configure_event(widget, event);
    }

gboolean Fenetre::expose_event(GtkWidget *widget, GdkEventExpose *event)
{ // devient visible => on réaffiche l'image mémoire à l'écran
  gdk_draw_drawable (widget->window,
		     widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		     dessin,
		     event->area.x, event->area.y,
		     event->area.x, event->area.y,
		     event->area.width, event->area.height);
  return FALSE;
}
gboolean Fenetre::relais_expose_event(GtkWidget *widget, GdkEventExpose *event, Fenetre* objet) {
    return objet->expose_event(widget, event);
    }

gboolean Fenetre::bouton_event(GtkWidget *widget, GdkEventButton *event)
{ // clic souris => on conserve les coordonnées et le numéro de bouton
  int x,y;
  GdkModifierType etat;
  gdk_window_get_pointer(event->window,&x,&y,&etat);
  sourisX=x;
  sourisY=y;
  boutonAppuye=event->button;
  return TRUE;
}
gboolean Fenetre::relais_bouton_event(GtkWidget *widget, GdkEventButton *event, Fenetre* objet) {
    return objet->bouton_event(widget, event);
    }

gboolean Fenetre::bouge_event(GtkWidget *widget, GdkEventMotion *event)
{ //mouvement souris => on conserve les coordonnées
  int x,y;
  GdkModifierType etat;
  gdk_window_get_pointer(event->window,&x,&y,&etat);
  sourisX=x;
  sourisY=y;
  return TRUE;
}
gboolean Fenetre::relais_bouge_event(GtkWidget *widget, GdkEventMotion *event, Fenetre* objet) {
    return objet->bouge_event(widget, event);
    }

void Fenetre::traiteEvenements() const {
// cette méthode permet d'éviter l'appel à gtk_main() qui bloque tout
// il suffit de l'appeler à chaque méthode pour traiter les événements
    if (existe) while(gtk_events_pending()) gtk_main_iteration();
    }

/* méthodes permettant d'obtenir les infos de souris pour une fenetre donnée
Ces méthodes n'existent que pour faire fonctionner la classe Souris tout en
laissant les propriétés sourisX, sourisY et boutonAppuye privées dans Fenetre */
int Fenetre::getSourisX() {
    if (!existe) return -1;
    else { traiteEvenements();
        return sourisX;  }
    }
int Fenetre::getSourisY() {
    if (!existe) return -1;
    else { traiteEvenements();
        return sourisY; }
    }
int Fenetre::getSourisBouton() {
    if (!existe) return -1;
    else {
        traiteEvenements();
        int bouton = boutonAppuye;
        boutonAppuye=-1;
        return bouton;
        }
}

// méthode permettant d'attendre un petit délai utile pour les TPs
void Fenetre::delai(int tempo) const {
    // la tempo est en millisecondes
    traiteEvenements();
    GTimer* montre;
    gdouble secondes=0;
    gulong microsecondes=0;
    gulong mesure;
    montre=g_timer_new();
    g_timer_start(montre);
    do {
        secondes=g_timer_elapsed(montre,&microsecondes);
        mesure=((gulong)(secondes*1000))+(microsecondes/1000);
        }
        while (mesure<tempo);
    traiteEvenements();
    }


// Constructeurs
Fenetre::Fenetre() { existe=FALSE; } // sans paramètre
Fenetre::Fenetre(const char *titre, int large, int haut, int x, int y, int r, int v, int b) {
// construction complète avec titre, taille, position et couleur de fond
     existe=FALSE;
     apparait(titre, large, haut, x, y, r, v, b);
}

void Fenetre::disparait() { // supprime la fenêtre de l'écran. Ce n'est pas un destructeur
    if (existe) {
        existe=FALSE; // la fenêtre n'est plus utilisable
//        g_signal_emit_by_name((GtkObject *)fenetre,"destroy");
		gtk_object_destroy((GtkObject *)fenetre);
		traiteEvenements();
        }
}

// Création de la fenêtre à l'écran. Cette méthode n'existe que pour pouvoir se passer
// de constructeur avec paramètres pour les débutants en C++.
void Fenetre::apparait(const char *titre, int large, int haut, int x, int y, int r, int v, int b) {
    if (!existe) {
    	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL); // création de la fenêtre
    	gtk_window_set_title(GTK_WINDOW(fenetre), titre); // mise en place du titre
    	gtk_window_set_default_size (GTK_WINDOW(fenetre), large, haut); // taille minimale

        // mise en place d'un contenant dans cette fenêtre
        contenant = gtk_vbox_new (FALSE, 0);
        gtk_container_add (GTK_CONTAINER (fenetre), contenant);
        gtk_widget_show (contenant);

        /* Création de la zone graphique pour la fenêtre */
        zoneDeDessin = gtk_drawing_area_new ();
        gtk_widget_set_size_request (GTK_WIDGET (zoneDeDessin), large, haut);
        gtk_box_pack_start (GTK_BOX (contenant), zoneDeDessin, TRUE, TRUE, 0);
        gtk_widget_show (zoneDeDessin);

        dessin=NULL; // pas de bitmap pour le moment il sera crée par l'exposition
        boutonAppuye=-1; // indicateurs pour la souris non positionnés
        sourisX=-1; sourisY=-1;
        fond.red=r; fond.green=v; fond.blue=b; // couleur de fond selon paramètre
        existe=TRUE; // le fenêtre est utilisable

        /* Signaux utilisés pour fermer la fenêtre */
    	g_signal_connect(G_OBJECT(fenetre), "destroy",
                G_CALLBACK(Fenetre::relais_supprime_event), this);
        g_signal_connect(G_OBJECT(fenetre), "delete_event",
                G_CALLBACK(Fenetre::relais_detruire_event), this);

        /* Signaux utilisés pour rafraîchir l'écran */
        g_signal_connect (G_OBJECT (zoneDeDessin), "expose_event",
    		    G_CALLBACK (Fenetre::relais_expose_event), this);
        g_signal_connect (G_OBJECT (zoneDeDessin), "configure_event",
    		    G_CALLBACK (Fenetre::relais_configure_event), this);

        /* Signaux utilisés pour la souris */
        g_signal_connect (G_OBJECT (zoneDeDessin), "motion_notify_event",
    		    G_CALLBACK (Fenetre::relais_bouge_event), this);
        g_signal_connect (G_OBJECT (zoneDeDessin), "button_press_event",
    		    G_CALLBACK (Fenetre::relais_bouton_event), this);

         // signaux autorisés dans la zone de dessin
        gtk_widget_set_events(zoneDeDessin, GDK_EXPOSURE_MASK
            | GDK_LEAVE_NOTIFY_MASK
            | GDK_BUTTON_PRESS_MASK
            | GDK_POINTER_MOTION_MASK
            | GDK_POINTER_MOTION_HINT_MASK);

        choixFonte("times"); // fonte initiale

        gtk_widget_show_all(fenetre); // visible

        deplacerEn(x,y); // position initiale de la fenêtre
		delai(100); // ce délai est nécessaire pour que la première écriture dans la fenêtre soit prise en compte
		effacer(); // au départ la fenêtre est de la couleur de fond choisie
        }
}

 void Fenetre::miseAJour() { // méthode probablement inutile laissée pour compatibilité
    if (!existe) return;
    gdk_draw_drawable (fenetre->window,
		     fenetre->style->fg_gc[GTK_WIDGET_STATE (fenetre)],
		     dessin, 0, 0, 0, 0, largeur(), hauteur());
   traiteEvenements();
 }

 void Fenetre::effacer() { // remplit tout le bitmap avec la couleur de fond
   if (existe) {
      gdk_gc_set_rgb_fg_color(fenetre->style->bg_gc[GTK_STATE_NORMAL],&fond);
      gdk_draw_rectangle (dessin,
    		 /*fenetre->style->white_gc*/ fenetre->style->bg_gc[GTK_STATE_NORMAL],
    		 TRUE, 0, 0, largeur(), hauteur());
      gtk_widget_queue_draw(fenetre);
      traiteEvenements();
      }
}

 // méthodes pour obtenir les dimensions de la fenêtre
 int Fenetre::largeur() const {
     if (!existe) return 0;
     else return fenetre->allocation.width;
     }
 int Fenetre::hauteur() const {
    if (!existe) return 0;
    else return fenetre->allocation.height;
    }
 // méthodes pour obtenir les coordonnées de la fenêtre à l'écran
 int Fenetre::coordEnX()  const {
     if (!existe) return -1;
     else {
        gint x,y;
        gtk_window_get_position(GTK_WINDOW(fenetre),&x,&y);
        return x;
        }
 }
 int Fenetre::coordEnY() const {
    if (!existe) return -1;
    else {
     gint x,y;
     gtk_window_get_position(GTK_WINDOW(fenetre),&x,&y);
     return y;
     }
 }

 void Fenetre::deplacerEn (int x, int y){ // permet de placer la fenêtre dans l'écran
     if (existe) gtk_window_move(GTK_WINDOW(fenetre),x,y);
 }

 Couleur Fenetre::couleurFond() const { // retourne la couleur de fond
    Couleur c(65535,65535,65535); // blanc si la fenêtre n'est pas affichée
    if (existe) c.changeCouleur(fond.red,fond.green,fond.blue);
    return c;
}

 // Choix de la couleur utilisée pour tous les tracés suivants
void Fenetre::choixCouleurTrace(Couleur c) {
    choixCouleurTrace(c.rouge(), c.vert(), c.bleu());
}
 void Fenetre::choixCouleurTrace(int r, int v, int b) {
     if (existe) {
         stylo.red=r; stylo.green=v; stylo.blue=b;
         traiteEvenements();
         }
}

// Choix de l'épaisseur de ligne utilisée pour un tracé.
// Cette méthode est privée et utilisée par les méthodes de dessin
void Fenetre::choixEpaisseurTrace(int e) {
      if (existe) {
          GdkGCValues valeurs;
          valeurs.line_width=e;
          gdk_gc_set_values(fenetre->style->fg_gc[GTK_STATE_NORMAL],
                &valeurs,GDK_GC_LINE_WIDTH);
          traiteEvenements();
          }
}

// méthodes de dessin (droite, arc)
void Fenetre::traceLigne(int ax, int ay, int bx, int by, int e) { //droite
    if (existe) {
        gdk_gc_set_rgb_fg_color(fenetre->style->fg_gc[GTK_STATE_NORMAL],&stylo);
        choixEpaisseurTrace(e); // couleur et épaisseur du tracé
        gdk_draw_line(dessin, fenetre->style->fg_gc[GTK_WIDGET_STATE (fenetre)],
                ax,ay,bx,by);
        gtk_widget_queue_draw(fenetre); // provoquer l'affichage
        traiteEvenements();
        }
}
void Fenetre::traceArc(int x, int y, int large, int haut, int angle1, int angle2, int e) {
    if (existe) {
       gdk_gc_set_rgb_fg_color(fenetre->style->fg_gc[GTK_STATE_NORMAL],&stylo); // courbe
       choixEpaisseurTrace(e); // couleur et épaisseur du tracé
       gdk_draw_arc(dessin,
    		      fenetre->style->fg_gc[GTK_WIDGET_STATE (fenetre)], FALSE,
                  x,y,large,haut,angle1*64,angle2*64);
       gtk_widget_queue_draw(fenetre); // provoquer l'affichage
       traiteEvenements();
       }
}

// Méthodes de remplissage (ellipse, rectangle)
void Fenetre::remplitEllipse(int x, int y, int large, int haut) { // ellipse pleine
    if (existe) {
       gdk_gc_set_rgb_fg_color(fenetre->style->fg_gc[GTK_STATE_NORMAL],&stylo);
       gdk_draw_arc(dessin,
    		      fenetre->style->fg_gc[GTK_WIDGET_STATE (fenetre)], TRUE,
                  x,y,large,haut,0,360*64);
       gtk_widget_queue_draw(fenetre); // provoquer l'affichage
       traiteEvenements();
       }
}
void Fenetre::remplitRectangle(int x,int y,int large,int haut ){ // rectangle plein
    if (existe) {
      gdk_gc_set_rgb_fg_color(fenetre->style->fg_gc[GTK_STATE_NORMAL],&stylo);
      gdk_draw_rectangle (dessin,
    		      fenetre->style->fg_gc[GTK_WIDGET_STATE (fenetre)], TRUE,
    		      x, y, large, haut);
      gtk_widget_queue_draw(fenetre); // provoquer l'affichage
      traiteEvenements();
      }
}
void Fenetre::afficheImage(const char * nom, int x, int y) { // image à partir d'un fichier
   if (existe) {
   // Les lignes mises en commentaire correspondent à la version utilisant des fichiers
   // au format XMP seulement (format de base de gtk)
/*	GdkPixmap * image=gdk_pixmap_create_from_xpm(fenetre->window,
		NULL, &fenetre->style->bg[GTK_STATE_NORMAL],nom);
	gdk_draw_pixmap(dessin, fenetre->style->fg_gc[GTK_WIDGET_STATE(fenetre)],
		image,0,0,0,0,-1,-1);
*/
    // version pour tous types de fichiers
    GdkPixbuf * image = gdk_pixbuf_new_from_file(nom, NULL);
    if (image!=NULL) {
	    gdk_pixbuf_render_to_drawable(image, dessin, fenetre->style->fg_gc[GTK_WIDGET_STATE(fenetre)],
                        0,0,x,y,-1,-1,GDK_RGB_DITHER_MAX,0,0);
	    gtk_widget_queue_draw(fenetre);
        gdk_pixbuf_unref(image);
//	gdk_pixmap_unref(image); utilisé dans la version pour XMP
	    traiteEvenements();
	    }
	}
}
void Fenetre::afficheImage(Image img, int x, int y) { // image à partir d'un objet
   if (existe) {
    GdkPixbuf * image = img.getPixbub();
    if (image!=NULL) {
	    gdk_pixbuf_render_to_drawable(image, dessin, fenetre->style->fg_gc[GTK_WIDGET_STATE(fenetre)],
                        0,0,x,y,-1,-1,GDK_RGB_DITHER_MAX,0,0);
	    gtk_widget_queue_draw(fenetre);
	    traiteEvenements();
	    }
    }
}

// Méthode de choix de fonte de caractères
// La syntaxe pour une fonte est : "-adobe-helvetica-bold-r-normal--12-120-75-75-p-70-iso8859-1"
// Chaque champ peut être remplacé par * si on ne veut pas de valeur particulière
// Les champs sont les suivants :
// - Créateur de la fonte
// - Nom de la famille
// - Graisse :  'bold' ou 'medium' ...
// - Aspect : 'R' pour Roman, 'I' pour italique, 'O' pour oblique ...
// - Largeur : 'normal' ou 'condensed'
// - le chanp suivant est omis => on a -- entre la largeur et la taille
// - Taille : taille en pixels
// - Points : taille en points
// - Résolution en X
// - Résolution en y
// - Espacement :  'p' pour proportionel, 'm' pour monospaced ou 'c' pour matrice de caractère
// - Taille moyenne d'un caractère de la fonte
// - Norme de codage
// - Codage du jeu de caractères
// Cette méthode permet de créer des noms de la forme :
// "-*-famille-graisse-italique-*--taille-*-*-*-*-*-*-*"
// où graisse peut être 'bold' ou '*'
// et italique peut être ; 'i' ou '*'
// et taille est la valeur passée en paramètre
void Fenetre::choixFonte(const char *famille, int taille, bool grasBool, bool italiqueBool) {
    if (existe) {
      char nom[80];
      gboolean gras = (grasBool ? TRUE : FALSE);
      gboolean italique = (italiqueBool ? TRUE : FALSE);
      strcpy (nom,"-*-"); strcat(nom,famille);
      if (gras) strcat(nom,"-bold"); else strcat(nom,"-*");
      if (italique) strcat(nom,"-i"); else strcat(nom,"-r");
      strcat(nom,"-*--");
      char t[3]; sprintf(t,"%d",taille); strcat(nom,t);
      strcat(nom,"-*-*-*-*-*-*-*");
      GdkFont* essai; essai=gdk_font_load(nom);
      if (essai==NULL) {
		  g_print("La fonte %s de taille %d ",famille, taille);
		  if (gras) g_print(" gras ");
		  if (italique) g_print(" italiques ");
		  g_print("n'existe pas : on garde la fonte precedente\n");
		  }
      else fonte=essai;
      traiteEvenements();
	  // Ce qui suit est la version utilisant Pango
/*      strcpy (nom,famille);
      strcat(nom," ");
      if (gras) strcat(nom,"bold ");
      if (italique) strcat(nom,"italic");
      strcat(nom," ");
      char t[3]; sprintf(t,"%d",taille); strcat(nom,t);
      PangoFontDescription* descripteur=pango_font_description_from_string(nom);
      fonte=gdk_font_from_description(descripteur);
      traiteEvenements();*/
      }
}

// Méthodes pour obtenir les tailles en pixels des textes selon la fonte choisie
int Fenetre::longueurTexte(const char *texte) const {
    if (!existe) return -1;
    traiteEvenements();
    int lb,rb,w,as,de;
    gdk_string_extents (fonte, texte, &lb, &rb, &w, &as, &de);
    traiteEvenements();
    return w; // longueur du texte en pixels
}
int Fenetre::hauteurTexte(const char *texte) const {
    if (!existe) return -1;
    int lb,rb,w,as,de;
    gdk_string_extents (fonte, texte, &lb, &rb, &w, &as, &de);
    traiteEvenements();
    return as+de; // hauteur du texte en pixels
}

// Méthodes pour écrire du texte et des entiers dans une fenêtre
void Fenetre::ecrit(int x, int y, const char * texte) {
    if (existe) {
      gdk_gc_set_rgb_fg_color(fenetre->style->fg_gc[GTK_STATE_NORMAL],&stylo);
      int lb,rb,w,as,de;
      gdk_string_extents (fonte, texte, &lb, &rb, &w, &as, &de);
      gdk_draw_string (dessin, fonte,
        fenetre->style->fg_gc[GTK_WIDGET_STATE (fenetre)],x,y-de,texte);
      gtk_widget_queue_draw(fenetre); // provoquer l'affichage
      traiteEvenements();
      }
}
void Fenetre::ecrit(int ax, int ay, int valeur) {
    char val[20];
    sprintf(val,"%d",valeur); // transformer l'entier en chaîne
    ecrit(ax, ay, val);
}
