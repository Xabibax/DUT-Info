CREATE TABLE PILOTE (
    plNum number(4),
    plNom varchar(25),
    plPrenom varchar(25),
    ville varchar(25),
    salaire number(6),
    PRIMARY KEY (plNum)
);

CREATE TABLE AVION (
    avNum number(4),
    avNom varchar(25),
    capacite number(3),
    localisation varchar(25),
    PRIMARY KEY (avNum)
);

CREATE TABLE VOL (
    volNum number(4),
    plNum number(4),
    avNum number(4),
    villeDep varchar(25),
    villeArr varchar(25),
    heureDep number(2),
    heureArr number(2),
    PRIMARY KEY (volNum),
    FOREIGN KEY (plNum) REFERENCES PILOTE(plNum),
    FOREIGN KEY (avNum) REFERENCES AVION(avNum)
);
    