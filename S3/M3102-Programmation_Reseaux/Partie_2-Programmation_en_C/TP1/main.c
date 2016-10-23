#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define LONG_MSG_MAX 150

void initIpSocket(struct sockaddr_in *ipToConfigure, char* local, int port)
						// "localhost" or ip("X.X.X.X")
{
	memset((char*) ipToConfigure, '\0', sizeof(struct sockaddr_in)); //tout à zéro
	ipToConfigure->sin_family = AF_INET;

	if (strcmp(local, "localhost"))
	   ipToConfigure->sin_addr.s_addr = htonl(INADDR_ANY);
	else
	   ipToConfigure->sin_addr.s_addr = inet_addr(local);

	ipToConfigure->sin_port = htons(port);
}

int main()
{
	// INITIALISATION
    int descSocket; // le descripteur de la socket
  	struct sockaddr_in adresseLocale; // l'adresse de rattachement locale
  	struct sockaddr_in adresseServeur; // l'adresse distante
  	int erreurConnexion; // récupère l'erreur de connexion
  	int nbOctets; // le nb d'octets d'abord envoyés puis reçu
  	char msgSend[LONG_MSG_MAX]; // le msg qui va être envoyé
  	char msgRecv[LONG_MSG_MAX]; // le msg qui va être reçu

	// TRAITEMENTS
  	// création de la socket
  	descSocket = socket(AF_INET, SOCK_STREAM, 0);

  	// initialisation des adresses de rattachement (local et distant)
  	initIpSocket(&adresseLocale, "localhost", 0);
  	initIpSocket(&adresseServeur, "127.0.0.1", 10500);

  	// attachement
  	bind(descSocket, (struct sockaddr*) &adresseLocale, sizeof(struct sockaddr));

  	// connexion
  	printf("Connexion au serveur en cours...\n");
  	erreurConnexion = connect(descSocket, (struct sockaddr*) &adresseServeur, sizeof(struct sockaddr));

  	if(erreurConnexion == -1)
  		printf("Il y a eu une erreur pendant la connexion !\n");
  	else
    {
  		printf("Vous êtes connecté !\n");

      	//récupération du mes à envoyer
      	printf("Entrez votre message : ");
      	scanf("%s", msgSend);

      	//envoi
      	nbOctets = send(descSocket, msgSend, strlen(msgSend), 0);
      	printf("%d/%d octets ont été envoyés.\n", nbOctets, strlen(msgSend));

      	//reception
      	nbOctets = recv(descSocket, msgRecv, LONG_MSG_MAX, 0);
      	printf("%d octets ont été reçus.\n", nbOctets);

      	//deconnexion et fermeture
      	printf("Fermeture... Etats : %d, %d.\n", shutdown(descSocket, 2), close(descSocket));

      	//affichage de la réponse du serveur
      	printf("Le serveur a répondu : \"%s\" !\n\n", msgRecv);
    }

  	return 0;
  }
