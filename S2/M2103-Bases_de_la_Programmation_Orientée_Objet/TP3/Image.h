#ifndef _IMAGE
#define _IMAGE
#include <gtk/gtk.h>
#include <gdk/gdk.h>

/* Classe pour manipuler des images créées à partir de fichiers jpeg ou d'autres formats */
class Image {

private :
    GdkPixbuf * img;
public :
    Image(const char *); // construction à partir du fichier dont le nom est passé en paramètre
	GdkPixbuf * getPixbub(); // structure utilisée par gtk
    int largeur() const; // dimensions de l'image (-1 s'il n'y a pas d'image)
    int hauteur() const;
};
#endif

