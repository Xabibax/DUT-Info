
public class Equipe
{
	private int id;
	private String nom;
	private int nombreJoueur;
	private int nombreJoueurMax = 10;
	private Joueur listeJoueur[nombreJoueurMax];

	public Equipe(int id, String nom, int nombreJoueur, int nombreJoueurMax)
	{
		this.id = id;
		this.nom = nom;
		this.nombreJoueur = nombreJoueur;
		this.nombreJoueurMax = nombreJoueurMax;
	}

	public void ajouterJoueur(Joueur j)
	{
		if(nombreJoueur < nombreJoueurMax)
		{
			listeJoueur[nombreJoueur] = j;
			nombreJoueur++;
		}
	}

	public void enleverJoueur(Joueur)
	{
		if(nombreJoueur > 0)
		{
			listeJoueur[nombreJoueur] = null;
		}
	}
}
