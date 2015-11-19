CREATE TABLE participer (
	numeroEquipe number(6),
	numeroCompetition number(6),
	resultat number(2),
	PRIMARY KEY (numeroEquipe, numeroCompetition),
	FOREIGN KEY (numeroEquipe) REFERENCES equipe(numero),
	FOREIGN KEY (numeroCompetition) REFERENCES competition(numero)
);
