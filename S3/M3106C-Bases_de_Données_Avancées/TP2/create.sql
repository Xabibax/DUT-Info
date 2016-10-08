--1
CREATE OR REPLACE TYPE COORDONNEE AS OBJECT
(ville VARCHAR2(25), cp VARCHAR2(5), telephone VARCHAR2(12), fax VARCHAR2(12));

CREATE TABLE EMP2(
    numEmp NUMBER(2),
    nomComplet VARCHAR2(50),
    coord COORDONNEE,
    PRIMARY KEY (numEmp)
);

--2
ALTER TABLE EMP
ADD COORD COORDONNEE;

--3
INSERT INTO EMP(numEmp, nom_complet, coord)
VALUES(14, 'DUPUIS Yvonne', COORDONNEE('Lyon', '69000', '0472546585', NULL));

INSERT INTO EMP(numEmp, nom_complet, coord)
VALUES(15, 'DUPOND Jean', COORDONNEE('Paris', '75000', NULL, NULL));

INSERT INTO EMP(numEmp, nom_complet, coord)
VALUES(16, 'CRINIERE Belle', COORDONNEE('Grenoble', '38001', NULL, NULL));

INSERT INTO EMP(numEmp, nom_complet, coord)
VALUES(17, 'AUBERT Louis', COORDONNEE('Lyon', '69100', '0478556585', NULL));

INSERT INTO EMP(numEmp, nom_complet, coord)
VALUES(18, 'MAURI John', COORDONNEE('Anglet', '64200', NULL, NULL));

--4
UPDATE EMP
SET nom_complet = 'XAVIER Richard',
    salaire = 30000,
    coord = COORDONNEE('Anglet', '64200', NULL, NULL)
WHERE numEmp = 2;

UPDATE EMP
SET nom_complet = 'NICOLLE Chris',
    salaire = 20000,
    coord = COORDONNEE('Anglet', '64200', '0698098989', NULL)
WHERE numEmp = 3;

--5
UPDATE emp
SET salaire = &sal
WHERE numEmp = &numero;

--6
SELECT DISTINCT e.coord.ville
FROM EMP e;

--7
SELECT DISTINCT COUNT(*)
FROM EMP e
GROUP BY e.coord.ville;

--8
SELECT numemp
FROM emp e
WHERE e.coord.ville = 'Anglet';

--9
SELECT numemp
FROM emp e
WHERE e.coord.telephone IS NOT NULL;

--10
SELECT e.coord.ville, DEPT.nomloc
FROM EMP e, DEPT
GROUP BY e.coord.ville, DEPT.nomloc;

--11
UPDATE EMP e
SET e.coord.telephone = '0612345678',
    e.coord.fax = '0600000099'
WHERE nom_complet = 'XAVIER Richard';


/****************/
/*   PARTIE 2   */
/****************/

-- 1
CREATE OR REPLACE PROCEDURE INSERT_EMP IS
BEGIN
    INSERT INTO EMP
    VALUES(&num, '&nom', '&metier', &superieur, &salaire, &numdep, COORDONNEE('&city', '&code', '&numtel', '&numfax'));
    commit;
END;


DECLARE
BEGIN
    insert_emp;
END;

-- 2
CREATE OR REPLACE PROCEDURE MAJ_EMP (nomEmp IN EMP.nom_complet%TYPE, sal IN EMP.salaire%TYPE) AS
BEGIN
    UPDATE EMP
    SET salaire = &sal
    WHERE nom_complet = &nomEmp;
    commit;
END;


DECLARE
BEGIN
    MAJ_EMP();
    -- TODO: mettre des boîtes de dialogues
END;
