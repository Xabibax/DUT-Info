CREATE TABLE Etudiant (
    num integer,
    nom varchar2(50) NOT NULL,
    prenom varchar2(50),
    anniversaire varchar2(10),
    niveau varchar2(2) CHECK (niveau IN ('1', '2', 'AS', 'LP')),
    groupe number(1),
    departement varchar2(15),
    PRIMARY KEY (num)
);

CREATE TABLE Cours (
    num varchar2(10),
    intitule varchar2(80),
    PRIMARY KEY (num)
);

CREATE TABLE Moyenne_Notation (
    numEtudiant integer,
    numCours varchar2(10),
    note number(4,2) CHECK ((note>=0) AND (note<=20)),
    FOREIGN KEY (numEtudiant) REFERENCES Etudiant(num),
    FOREIGN KEY (numCours) REFERENCES Cours(num),
    PRIMARY KEY (numEtudiant, numCours)
);