--1
SELECT nom, prenom FROM Etudiant
WHERE niveau='1'
ORDER BY nom, prenom;

--2
SELECT nom, prenom FROM Etudiant
WHERE nom BETWEEN 'D' AND 'F';

--3
SELECT nom, prenom FROM Etudiant
WHERE nom LIKE '%PO%';

--4
SELECT nom, prenom FROM Etudiant
WHERE departement='Informatique'
AND (anniversaire LIKE '%1977' OR anniversaire LIKE '%1978');

--5
SELECT nom, prenom, CEIL((SYSDATE-anniversaire)/365)-1 AS age
FROM ETUDIANT;

--6
SELECT nom, prenom FROM Etudiant
WHERE anniversaire IS NULL;

--7
SELECT nom, prenom FROM Etudiant
JOIN Moyenne_Notation ON Moyenne_Notation.numEtudiant=Etudiant.num
JOIN Cours ON Cours.num=Moyenne_Notation.numcours
WHERE niveau='2' AND Cours.num='CX56';

--8
SELECT numCours, MIN(note), MAX(note), AVG(note) FROM Moyenne_Notation
GROUP BY numCours;

--9
SELECT Etudiant.nom, AVG(note) FROM Moyenne_Notation
JOIN Etudiant ON Moyenne_Notation.numetudiant=Etudiant.num
GROUP BY num, nom
ORDER BY AVG(note) DESC;

--10
ALTER TABLE Etudiant
MODIFY departement varchar2(50);

UPDATE Etudiant
SET departement='Genie Mecanique et Productique'
WHERE departement='GMP';

--11
DELETE FROM Moyenne_Notation
WHERE numetudiant=346;

DELETE FROM Etudiant
WHERE num=346;

/* TEST */
SELECT * FROM Etudiant;
SELECT * FROM Cours;
SELECT * FROM Moyenne_Notation;
