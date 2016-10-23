CREATE TABLE EMP(
    numemp NUMBER(2),
    nom_complet VARCHAR2(50),
    profession VARCHAR2(25),
    chef NUMBER(2),
    salaire NUMBER(6),
    numdep NUMBER(2),
    PRIMARY KEY (numemp),
	FOREIGN KEY (chef) REFERENCES EMP(numemp),
    FOREIGN KEY (numdep) REFERENCES DEPT(numdep)
);

CREATE TABLE DEPT(
    numdep NUMBER(2),
    nomdep VARCHAR2(25),
    nomloc VARCHAR2(25),
    PRIMARY KEY (numdep)
);
