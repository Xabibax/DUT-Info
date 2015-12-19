CREATE TABLE EQUIPE (
    num number(5),
    nom varchar2(25),
    capaciteStade number(7),
    budget number(9),
    PRIMARY KEY (num)
);

CREATE TABLE JOUEUR (
    code number(5) NOT NULL
    numMaillot number(2),
    nom varchar2(25),
    prenom varchar2(25),
    nationalite varchar2(25),
    nbSelections number(3),
    numEquipe number(5),
    PRIMARY KEY (code),
    FOREIGN KEY (numEquipe) REFERENCES EQUIPE(num)
);

CREATE TABLE COMPETITION (
    num number(5),
    nom varchar2(25),
    type varchar2(25),
    saison number(4),
    numEquipe number(5),
    PRIMARY KEY (num),
    FOREIGN KEY (numEquipe) REFERENCES EQUIPE(num)
);

CREATE TABLE PARTICIPER (
    resultat number(2),
    numCompetition number(5),
    numEquipe number(5),
    PRIMARY KEY (numCompetition, numEquipe),
    FOREIGN KEY (numCompetition) REFERENCES COMPETITION (num),
    FOREIGN KEY (numEquipe) REFERENCES EQUIPE (num)
);

CREATE TABLE PALMARESJ (
    numJoueur number(2),
    numCompetition number(),
    PRIMARY KEY (numJoueur, numCompetition),
    FOREIGN KEY (numJoueur) REFERENCES JOUEUR(num),
    FOREIGN KEY (numCompetition) REFERENCES COMPETITION(num)
);

CREATE TABLE PALMARESE (
    numEquipe number(2),
    numCompetition number(),
    PRIMARY KEY (numEquipe, numCompetition),
    FOREIGN KEY (numEquipe) REFERENCES EQUIPE(num),
    FOREIGN KEY (numCompetition) REFERENCES COMPETITION(num)
);
