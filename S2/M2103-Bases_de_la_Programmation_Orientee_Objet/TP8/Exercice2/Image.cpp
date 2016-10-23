#include "Image.h"	

Image::Image(const char *nom) { // construction à partir d'un fichier
    img = gdk_pixbuf_new_from_file(nom, NULL);
}

GdkPixbuf * Image::getPixbub(){
    return img;
}

int Image::largeur() const { //largeur de l'image en pixels
    if (img!=NULL) return gdk_pixbuf_get_width(img);
    else return -1;
}

int Image::hauteur() const{ //hauteur de l'image en pixels
    if (img!=NULL) return gdk_pixbuf_get_height(img);
    else return -1;
}

