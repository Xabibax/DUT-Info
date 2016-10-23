public class Cellule
{
	private double valeur;
		
	public Cellule(double valeur)
	{
		super();
		this.valeur = valeur;
	}
	
	public double getValeur()
	{
		return valeur;
	}
	
	public void setValeur(double valeur)
	{
		this.valeur = valeur;
	}
	
	public void affiche()
	{
		String affichage = String.valueOf(getValeur()); //conversion de la valeur en chaine
		
		while (affichage.length() < 5)//les chaines auront toutes 5 caractères de longueur
			affichage = " " + affichage;//ajout d' espaces devant la chaine
			
		System.out.print(affichage);// => les nombres doivent etre sur 5 digits
	}
}
