/*** PARTIE 1 ***/
-- 1
CREATE OR REPLACE TYPE B_Point AS OBJECT
(
    x INTEGER,
    y INTEGER
);

-- 2
CREATE OR REPLACE TYPE Ligne AS OBJECT
(
    ptLigne1 B_Point,
    ptLigne2 B_Point
);

-- 3
CREATE OR REPLACE TYPE Polygone
AS TABLE OF B_Point;

-- 4
CREATE TABLE REGION
(
    nom VARCHAR2(50) PRIMARY KEY,
    poly Polygone
)
NESTED TABLE poly STORE AS tabpoly;

-- 5
INSERT INTO REGION
VALUES('Aquitaine', Polygone(B_Point(15, 30), B_Point(20, 30), B_Point(20, 15), B_Point(30, 15), B_Point(30, 30)));

-- 6
CREATE OR REPLACE TYPE Rect AS OBJECT
(
    ptRect1 B_Point,
    ptRect2 B_Point
);

-- 7
CREATE TABLE VILLE
(
    nom VARCHAR2(50) PRIMARY KEY,
    rectangle Rect
);

-- 8
INSERT INTO VILLE
VALUES('Anglet', Rect(B_Point(8950, 4840), B_Point(9180, 5050)));

INSERT INTO VILLE
VALUES('Lyon', Rect(B_Point(8820, 7020), B_Point(9080, 7230)));

INSERT INTO VILLE
VALUES('Paris', Rect(B_Point(6310, 2940), B_Point(6560, 3110)));

-- 9
SELECT v.nom, ABS((v.rectangle.ptRect2.x - v.rectangle.ptRect1.X) * (v.rectangle.ptRect1.y - v.rectangle.ptRect2.y))
FROM VILLE v;

-- 10
SELECT v.nom
FROM VILLE v
WHERE ABS(v.rectangle.ptRect2.x - v.rectangle.ptRect1.X) > 10
OR ABS(v.rectangle.ptRect1.y - v.rectangle.ptRect2.y) > 10;


/*** PARTIE 2 ***/
-- 1
---- Création des tables
CREATE TABLE CATEGORIE
(
    noCat INTEGER PRIMARY KEY,
    libelle VARCHAR2(50)
);

CREATE TABLE ARTICLE
(
    noArt VARCHAR2(50) PRIMARY KEY,
    description VARCHAR2(50),
    couleur VARCHAR2(50),
    cat INTEGER,
    prix INTEGER,
    stock INTEGER,
    FOREIGN KEY(cat) REFERENCES CATEGORIE(noCat)
);

CREATE OR REPLACE TYPE cmde
AS TABLE OF INTEGER;

CREATE SEQUENCE noClient
INCREMENT BY 1
START WITH 0;

CREATE TABLE CLIENT
(
    noClient INTEGER PRIMARY KEY,
    nomClient VARCHAR2(50),
    ville VARCHAR2(50),
    panier cmde
)
NESTED TABLE panier STORE AS tabcmde;

CREATE SEQUENCE noCmde
INCREMENT BY 1
START WITH 100;

CREATE OR REPLACE TYPE Details_Type AS OBJECT
(
    art VARCHAR2(50),
    qteCmde INTEGER
);

CREATE OR REPLACE TYPE DetailsS_Type
AS TABLE OF Details_Type;

CREATE TABLE COMMANDE
(
    noCmde INTEGER PRIMARY KEY,
    dateCmde DATE DEFAULT SYSDATE,
    det DetailsS_Type
)
NESTED TABLE det STORE AS tabdetails;

---- Peuplement des tables
INSERT INTO CATEGORIE
VALUES(1, 'Apple');
INSERT INTO CATEGORIE
VALUES(2, 'PC');
INSERT INTO CATEGORIE
VALUES(3, 'Autre');

INSERT INTO ARTICLE
VALUES('A1', 'MacPro', 'Rouge', 1, 1.50, 500);
INSERT INTO ARTICLE
VALUES('A2', 'MacPro Air', 'Blanc', 1, 1.50, 800);
INSERT INTO ARTICLE
VALUES('A3', 'MacPro Server', 'Noir', 1, 2.00, 1000);
INSERT INTO ARTICLE
VALUES('A4', 'Dell', 'Jaune', 2, 1500, 1);
INSERT INTO ARTICLE
VALUES('A5', 'HP', 'Bleu', 1, 10.00, 200);
INSERT INTO ARTICLE
VALUES('A6', 'Acer', 'Gris', 3, 10.00, 25);
INSERT INTO ARTICLE
VALUES('A7', 'Sony', 'Noir', 2, 120, 300);

INSERT INTO CLIENT
VALUES(1, 'BARTH Florent', 'Anglet', cmde(101, 106, 107));
INSERT INTO CLIENT
VALUES(2, 'FREE Marc', 'Lyon', cmde(102));
INSERT INTO CLIENT
VALUES(3, 'POISSON Christophe', 'Lille', cmde(103, 104));
INSERT INTO CLIENT
VALUES(4, 'BLAKE John', 'Mez', cmde(105));
INSERT INTO CLIENT
VALUES(5, 'DUPONT Jean', 'Paris', cmde(NULL));

INSERT INTO COMMANDE
VALUES(noCmde.NEXTVAL, TO_DATE('10/10/2008'), DetailsS_Type(Details_Type('A1', 5), Details_Type('A2', 6), Details_Type('A3', 4)));
INSERT INTO COMMANDE
VALUES(noCmde.NEXTVAL, TO_DATE('12/11/2007'), DetailsS_Type(Details_Type('A4', 2)));
INSERT INTO COMMANDE
VALUES(noCmde.NEXTVAL, TO_DATE('13/02/2008'), DetailsS_Type(Details_Type('A5', 3), Details_Type('A1', 2)));
INSERT INTO COMMANDE
VALUES(noCmde.NEXTVAL, TO_DATE('12/12/2006'), DetailsS_Type(Details_Type('A2', 1)));
INSERT INTO COMMANDE
VALUES(noCmde.NEXTVAL, TO_DATE('01/05/2008'), DetailsS_Type(Details_Type('A3', 2)));
INSERT INTO COMMANDE
VALUES(noCmde.NEXTVAL, TO_DATE('02/02/2008'), DetailsS_Type(Details_Type('A1', 3), Details_Type('A2', 6), Details_Type('A3', 4)));
INSERT INTO COMMANDE
VALUES(noCmde.NEXTVAL, TO_DATE('03/06/2005'), DetailsS_Type(Details_Type('A4', 2)));
