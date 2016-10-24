#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

#define NB_MAX_CONNEXIONS 5
#define LONG_MSG_MAX 50

int main (int argc, char* argv[])
{
	int socketServeur; //le descripteur de ma socket d'écoute
	int descSocketService; // le descripteur de ma socket de service
	struct sockaddr_in adresseLocale; //l'adresse de rattachement locale
	struct sockaddr_in adresseAttache; //l'adresse d'attachement
	int erreurListen; // récupère l'erreur de connexion
	int nbOctets; // le nb d'octets d'abord envoyés puis reçu
	char msg[LONG_MSG_MAX]; //le msg qui va être reçu
	int erreur; //pour stocker mes erreurs que je ne regarde pas (c'est pas bien !)
	int adrAccept; //adresse de l'appelant
	char reponse[50];


    /// Init
	// Création d'une socket (p.32)
	socketServeur = socket(AF_INET, SOCK_STREAM, 0);

	// Attachement de la socket (p.34)
	bind(socketServeur, (struct sockaddr*) &adresseLocale, sizeof(struct sockaddr));
	memset ((char*) &adresseLocale, '\0', sizeof(struct sockaddr_in)); // tout à 0 - transtypage de données
	adresseLocale.sin_family = AF_INET;
	adresseLocale.sin_addr.s_addr = htonl(INADDR_ANY); // inet_addr("10.3.203.15")
	adresseLocale.sin_port = htons(0); // num_port

	//mise à l'écoute
	erreurListen = listen(socketServeur, NB_MAX_CONNEXIONS);
			//à exploiter avec le -1 pour erreur

	while(1)
    {
        //acceptation de connexion
        descSocketService = accept(socketServeur,(struct sockaddr*) &adresseAttache, &adrAccept);

        //reception
        nbOctets = recv(descSocketService, msg, LONG_MSG_MAX, 0);
        printf("%d octets ont été reçus.\n", nbOctets);

        int i=0;

        while(msg[i] != '\0')
        {
            if(msg[i] >= 'a' && msg[i] <= 'z')
            {
                reponse[i] = reponse[i] - 'a' + 'A';
            }
            else
            {
                reponse[i] = msg[i];
            }

        }

        //envoi
        nbOctets = send(descSocketService, msg, strlen(msg), 0);
        printf("%d/%d octets ont été envoyés.\n", nbOctets, strlen(msg));

        //deconnexion et fermeture
        erreur = shutdown(descSocketService, 2);
        erreur = close(descSocketService);
	}

    return 0;
}
