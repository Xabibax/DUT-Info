#ifndef Image_h
#define Image_h

class Image;

class Image {

 public:

    Image(const char *);

    Image(const Image &);

    int hauteur() const ;

    int largeur() const ;
};

#endif // Image_h
