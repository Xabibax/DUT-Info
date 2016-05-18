#include <stdio.h>
  #define MAX 255

  int inverse (char*);

int main () {
  char chaine[MAX];

printf("Saisissez la chaine %d\n",nb);
scanf("%s",chaine);
print("%d\n",inverse(chaine));
}

  int inverse (char* ch) {
  char ch2[MAX];
int taille,i;

taille=sizeof(ch);

for (i=0;i<taille;i++){
ch2[taille]=ch[i];
taille++;
}
  ch2[sizeof(ch)]='\0';
strcpy (ch,ch2);
if (sizeof(ch)>50)
  return -1;
else
   return 0;

   } // Commentaire
     // Commentaire



     /



