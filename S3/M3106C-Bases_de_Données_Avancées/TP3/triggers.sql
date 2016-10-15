-- 1
CREATE OR REPLACE TRIGGER nbTuples
AFTER INSERT OR DELETE ON DEPT

DECLARE
    compteur INTEGER;

BEGIN
    SELECT COUNT(*) INTO compteur FROM DEPT;
    dbms_output.put_line('Il y a ' || compteur || ' tuples dans la table DEPT.');
END;

-- 2
CREATE OR REPLACE TRIGGER majTuples
AFTER UPDATE ON DEPT FOR EACH ROW

DECLARE

BEGIN
    UPDATE EMP e
    SET e.numdep = :NEW.numdep WHERE e.numdep = :OLD.numdep;
END;

-- 3
CREATE OR REPLACE TRIGGER prefixeNomDep
BEFORE INSERT ON DEPT

DECLARE

BEGIN
    :NEW.nomdep := ('DEPT_' || :NEW.nomdep);
END;

-- 4
CREATE SEQUENCE monCompteur INCREMENT BY 1 START WITH 10;

CREATE OR REPLACE TRIGGER sequenceClePrimaire
BEFORE INSERT ON EMP FOR EACH ROW

DECLARE
BEGIN
    :NEW.numemp := monCompteur.NEXTVAL;
END;

-- 5
