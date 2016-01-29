SELECT nom, prenom FROM Etudiant
WHERE niveau='1'
ORDER BY nom, prenom;

SELECT nom, prenom FROM Etudiant
WHERE nom BETWEEN 'D' AND 'F';

SELECT nom, prenom FROM Etudiant
WHERE nom LIKE '%PO%';

SELECT nom, prenom FROM Etudiant
WHERE departement='Informatique'
AND (anniversaire LIKE '%1977' OR anniversaire LIKE '%1978');

SELECT nom, prenom, CEIL((SYSDATE-anniversaire)/365)-1 AS age
FROM ETUDIANT;

SELECT nom, prenom FROM Etudiant
WHERE anniversaire IS NULL;

SELECT nom, prenom FROM Etudiant
JOIN Moyenne_Notation ON Moyenne_Notation.numEtudiant=Etudiant.num
JOIN Cours ON Cours.num=Moyenne_Notation.numcours
WHERE niveau='2' AND Cours.num='CX56';

SELECT numCours, MIN(note), MAX(note), AVG(note) FROM Moyenne_Notation
GROUP BY numCours;