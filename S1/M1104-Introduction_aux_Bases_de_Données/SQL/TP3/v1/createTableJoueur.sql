CREATE TABLE joueur (
	numero number(2) NOT NULL,
	nom varchar2(15),
	prenom varchar2(15),
	nationalite varchar2(15),
	nbSelecEquNat number(11),
	numeroEquipe number(5),
	PRIMARY KEY (numero),
	FOREIGN KEY (numeroEquipe)
	REFERENCES equipe(numero)
);
