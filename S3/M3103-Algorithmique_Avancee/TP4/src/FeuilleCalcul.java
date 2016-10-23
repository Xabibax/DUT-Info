import java.util.Map;
import java.util.TreeMap;

public class FeuilleCalcul
{
	private Map<String, Cellule> cellules;

	public FeuilleCalcul()
	{
		super();
		//TreeMap pour avoir des cles triees par ordre alphabetique
		cellules = new TreeMap<String, Cellule>(); 
	}
	
	public Map<String, Cellule> getCellules()
	{
		//pas de setter car nous disposons de methodes
		// pour manipuler les cellules (ajout, suppression, modification
		return cellules;
	}

	public void ajouterCellule(String cle,Cellule cellule)
	{
		cellules.put(cle, cellule);
	}
	
	public void supprimerCellule(String cle)
	{
		cellules.put(cle, null);
	}
	
	public void deplacerCellule(String cleDepart, String cleArrivee)
	{
		ajouterCellule(cleArrivee, cellules.get(cleDepart)); // copie de la cellule à sa nouvelle place
		supprimerCellule(cleDepart); // suppression de la cellule à son ancienne place
	}
	
	public double getValeur(String cle)
	{
		//obtenir la valeur de la cellule
		if (cellules.get(cle) != null)
			return cellules.get(cle).getValeur();
		else
			return 0.0;
	}
	
	public void afficher()
	{
		System.out.println("     1    2    3    4");//on travaille arbitrairement sur 4 colonnes
		System.out.print("A");
		
		int ligneCourante = "A".codePointAt(0);//conversion du caractère d'indice 0 de la chaine "A" en int
		int colonneCourante = 1;
		
		for (String cle : cellules.keySet())
		{
			//sauts de ligne
			int ligneParcours = cle.codePointAt(0);//conversion du caractère d'indice 0 de la chaine cle en int
			
			while ( ligneCourante != ligneParcours)
			{
				System.out.println();
				ligneCourante = ligneCourante + 1;
				colonneCourante = 1;
				System.out.print(Character.toChars(ligneCourante));//affichage de la lettre de la ligne
			}
			
			//sauts de colonne
			int colonneParcours = Integer.parseInt(cle.substring(1));//conversion de la sous chaine depuis l'indice 1
																	// de cle en entier
			while ( colonneCourante != colonneParcours )
			{
				System.out.print("     ");
				colonneCourante = colonneCourante + 1;
			}
			
			//affichage
			if (cellules.get(cle) != null) //verification pour une cellule supprimée
				cellules.get(cle).affiche();//conversion de la valeur en chaine
			else
				System.out.print("     ");
			
			colonneCourante = colonneCourante + 1;
		}
	}
}
