INSERT INTO EMP
VALUES(1, 'BARTH Florent', 'CHEF DE PROJET', 3, 13000, 2); 
INSERT INTO EMP
VALUES(2, 'XAVIER Richard', 'CHERCHEUR', 3, 21000, 1); 
INSERT INTO EMP
VALUES(3, 'NICOLE Chris', 'CHERCHEUR', NULL, 25000, 1); 
INSERT INTO EMP
VALUES(4, 'BLAKE John', 'DEVELOPPEUR', 6, 8000, 2); 
INSERT INTO EMP
VALUES(5, 'DUPONT Jean', 'DEVELOPPEUR', 3, 9000, 2); 
INSERT INTO EMP
VALUES(6, 'MARTIN Alexandre', 'COMPTABLE', 3, 10000, 3); 
INSERT INTO EMP
VALUES(7, 'RAY Benjamin', 'COMPTABLE', 3, 10000, 3); 
INSERT INTO EMP
VALUES(8, 'MILLER Pascal', 'DEVELOPPEUR', 3, 9000, 2); 
INSERT INTO EMP
VALUES(9, 'FORD John', 'DIRECTEUR', 3, 30000, 4); 

INSERT INTO DEPT
VALUES(1, 'RECHERCHE', 'DIJON');
INSERT INTO DEPT
VALUES(2, 'DEVELOPPEMENT', 'NEW-YORK');
INSERT INTO DEPT
VALUES(3, 'FACTURATION', 'PARIS');
INSERT INTO DEPT
VALUES(4, 'DIRECTION', 'LONDRES');


-- PL/SQL
set serveroutput on

DECLARE
    n NUMBER(2);
    CURSOR employes IS SELECT numemp, nom_complet, salaire FROM EMP;
    -- Permet de retourner le résultat de la requête dans employes
    newsal emp.salaire%TYPE;
    -- newsal sera de même type que salaire dans la table emp
    empv EXCEPTION;
BEGIN
    SELECT COUNT(*) INTO n FROM EMP;
    IF n=0 THEN
        RAISE empv;
    END IF;
    FOR employe IN employes LOOP
        newsal:=employe.salaire+50;
        -- on additionne 50 à tous les salaires
        UPDATE EMP SET SALAIRE=newsal where NUMEMP = employe.numemp;
    END LOOP;
    EXCEPTION
        WHEN empv THEN dbms_output.put_line('0 row selected');
  Commit;
END;

-- Hello world!
CREATE OR REPLACE PROCEDURE hello_world AS
BEGIN
    dbms_output.put_line('Hello world!'); 
END;

DECLARE
BEGIN
  hello_world;
END;

CREATE OR REPLACE FUNCTION salaire (employe in emp.nomComplet%TYPE)
RETURN emp.salaire%TYPE IS
        lesalaire emp.salaire%TYPE;
        n NUMBER(2);
BEGIN
        SELECT COUNT(*) INTO n FROM EMP WHERE nomComplet=employe;
        IF n=0 THEN
                dbms_output.put_line('Pas d''entrée sous ce nom');
        ELSIF n>1 THEN
                dbms_output.put_line('Plusieures entrées sous ce nom');
        ELSE
                SELECT salaire INTO lesalaire FROM EMP WHERE nomComplet=empl    oye;
        END IF;
RETURN lesalaire;
END;
/
 
show errors