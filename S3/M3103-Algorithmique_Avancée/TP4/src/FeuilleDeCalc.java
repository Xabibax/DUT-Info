import java.util.Map;

public class FeuilleDeCalc
{
	private String nom;
	private Map <String, Cellule> Feuille;
	
	public String getNom() {return nom;}
	public void setNom(String nom) {this.nom = nom;}
	
	public void ajouterCellule(String cle, Cellule c)
	{
		Feuille.put(cle, c);
	}
	
	public void supprimerCellule(String cle)
	{
		Feuille.remove(cle);
	}
	
	public void deplacerCellule(String cle, String nouveauCle)
	{
		Cellule c = Feuille.get(cle);
	
		supprimerCellule(cle);
		ajouterCellule(nouveauCle);
		
		
	}
}
