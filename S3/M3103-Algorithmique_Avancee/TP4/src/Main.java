public class Main
{
	public static void main(String[] args)
	{
		FeuilleCalcul feuille = new FeuilleCalcul();

		Cellule cellule1 = new Cellule(5);
		Cellule cellule2 = new Cellule(18.5);
		CelluleFormule cellule3 = new CelluleFormule("D2+B2", feuille);
		
		feuille.ajouterCellule("B2", cellule2);
		feuille.ajouterCellule("D4", cellule3);
		feuille.ajouterCellule("D2", cellule1);
		
		feuille.afficher();
	}
}
