-- Afficher les messages
	set serveroutput on

-- Question 1 à 6
---- Script CREATE TABLE
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

---- Script INSERT
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

---- Bloc PL/SQL permettant d'addionner 50 à tous les salaires.
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
			-- on met à jour

		END LOOP;

		EXCEPTION
			WHEN empv THEN dbms_output.put_line('0 row selected');

		Commit;
	END;

-- Question 7 : "Hello world!"
	CREATE OR REPLACE PROCEDURE hello_world AS
	BEGIN
		dbms_output.put_line('Hello world!');
	END;

	DECLARE
	BEGIN
	  hello_world;
	END;

-- Question 8.1 : Affichage du salaire
	CREATE OR REPLACE FUNCTION salaire (employe in VARCHAR2)
	RETURN NUMBER IS leSalaire emp.salaire%TYPE;
			n NUMBER(2);
	BEGIN
			SELECT COUNT(*) INTO n FROM EMP WHERE nom_complet=employe;
			IF n=0 THEN
				dbms_output.put_line('Pas d''entrée sous ce nom');
			ELSIF n>1 THEN
				dbms_output.put_line('Plusieures entrées sous ce nom');
			ELSE
				SELECT salaire INTO leSalaire FROM EMP WHERE nom_complet=employe;
			END IF;
	RETURN leSalaire;
	END;
	/

	show errors

	DECLARE
	BEGIN
	 dbms_output.PUT_LINE(salaire('BARTH Florent'));
	END;

-- Question 8.2 : Affichage du salaire avec message
	CREATE OR REPLACE FUNCTION indiquerSalaire (employe in EMP.nom_complet%TYPE)
		RETURN VARCHAR2 IS
			message VARCHAR2(100);
			LeSalaire EMP.salaire%Type;
			LaProfession EMP.profession%Type;
			LeNumemp EMP.numemp%Type;
	BEGIN
		SELECT salaire INTO LeSalaire FROM EMP WHERE nom_complet=employe;
		SELECT profession INTO LaProfession FROM EMP WHERE nom_complet=employe;
		SELECT numemp INTO LeNumemp FROM EMP WHERE nom_complet=employe;
		message := 'Num = ' || LeNumemp || ', salaire = ' || LeSalaire || ', prefession : ' || LaProfession || '.';
		RETURN message;
	END;

	DECLARE
	BEGIN
	 dbms_output.PUT_LINE(indiquerSalaire('RAY Benjamin'));
	END;

-- Question 9 : Nouveau département (la compilation fonctionne mais pas l'exécution)
	CREATE OR REPLACE PROCEDURE affecter_emp_dept (employe IN EMP.nom_complet%TYPE, newDept IN DEPT.nomdep%TYPE) AS
	  numDept DEPT.numdep%TYPE;
	BEGIN
	  SELECT numdep INTO numDept FROM DEPT WHERE nomdep=newDept;
	  UPDATE EMP SET EMP.numdep=numDept WHERE employe=nom_complet;
	END;
	/

	show errors

	DECLARE
	BEGIN
		dbms_output.PUT_LINE(affecter_emp_dept('XAVIER Richard', 'Anglet'));
	END;
