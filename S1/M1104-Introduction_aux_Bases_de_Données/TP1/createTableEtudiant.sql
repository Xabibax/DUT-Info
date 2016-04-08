CREATE TABLE etudiant (
	numero number(10) NOT NULL,
	nom varchar(25),
	prenom varchar(10),
	sexe varchar(4),
	groupe_TD number(1),
	groupe_TP number(1),
	PRIMARY KEY (numero)
);

