#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
	// Déclaration des variables
	int adr_ip = inet_addr(argv[1]);
	int num_port = htons(atoi(argv[2]));

	int socketClient;
	struct sockaddr_in adresseLocale;
	struct sockaddr_in adresseDistante;
	char chaine[50];
	char reponse[50];

	int errors;


	/// Init
	// Création d'une socket (p.32)
	socketClient = socket(AF_INET, SOCK_STREAM, 0);

	// Attachement d'une socket (p.34)
   	bind(socketClient, (struct sockaddr*) &adresseLocale, sizeof(struct sockaddr));

	memset ((char*) &adresseLocale, '\0', sizeof(struct sockaddr_in)); // tout à 0 - transtypage de données
	adresseLocale.sin_family = AF_INET;
	adresseLocale.sin_addr.s_addr = htonl(INADDR_ANY); // inet_addr("10.3.203.15")
	adresseLocale.sin_port = htons(0); // num_port

	// Afficher "quelle chaîne ?" >> écran
	printf("Quelle est la chaine ? \n");

	// Saisir chaîne >>
	scanf("%s", chaine);

	// Demande de connexion
	memset ((char*) &adresseDistante, '\0', sizeof(struct sockaddr_in)); // tout à 0 - transtypage de données
	adresseDistante.sin_family = AF_INET;
	adresseDistante.sin_addr.s_addr = adr_ip; // "10.3.203.15"
	adresseDistante.sin_port = num_port; //
	errors = connect(socketClient, (struct sockaddr*) &adresseDistante, sizeof(struct sockaddr));

	if(errors == -1)
	{
		printf("L'adresse IP ou le numéro de port est invalide ou le serveur ne répond pas.\n");
		return 1;
	}


	// socket, req >> Envoi
	send(socketClient, chaine, 50, 0);

	// socket >> Réception >> reponse
	recv(socketClient, reponse, 50, 0);

	// socket >> Déconnexion >> socket
	shutdown(socketClient, 0);

	// reponse >> Afficher chaîne
	printf("La nouvelle chaine est %s.\n", reponse);

	return 0;
}
