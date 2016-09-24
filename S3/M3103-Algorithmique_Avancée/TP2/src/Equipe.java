class Equipe
{
	// Attributs
	private int id;
	private String nom;
	private int nombreJoueur;
	private final int NOMBREMAXJOUEUR = 10;
	private Joueur listeJoueur[] = new Joueur[10];

	// Constructeur
	public Equipe(int id, String nom)
	{
		this.id = id;
		this.nom = nom;
		this.nombreJoueur = 0;
		this.listeJoueur = new Joueur[NOMBREMAXJOUEUR];
	}

	// Ajout d'un joueur dans le tableau
	public void ajouterJoueur(int id, String nom, String prenom, int numero, String poste, boolean estTitulaire)
	{
		if(nombreJoueur < NOMBREMAXJOUEUR)
		{
			this.listeJoueur[nombreJoueur]= new Joueur(id, nom, prenom, numero, poste, estTitulaire);
			nombreJoueur++;
		}
		else
			System.out.println("Erreur : il y a d�j� bien assez de joueur dans cette �quipe !");
	}

	// Afficher seulement les joueurs titulaires
	public void afficherTitulaires()
	{
		System.out.println(nom + " - Titulaire(s) : ");

		for(int i=0; i<nombreJoueur; i++)
		{
			if(this.listeJoueur[i].getTitulaire())
				this.listeJoueur[i].afficherJoueur();
		}
	}

	// Afficher seulement les joueurs rempla�ants
	public void afficherRemplacants()
	{
		System.out.println(nom + " - Rempla�ant(s) : ");

		for(int i=0; i<nombreJoueur; i++)
		{
			if(!this.listeJoueur[i].getTitulaire())
				this.listeJoueur[i].afficherJoueur();
		}
	}

	// Supprimer un joueur du tableau
	public void enleverJoueur(int caseASupprimer)
	{
		if(nombreJoueur > 0)
			listeJoueur[caseASupprimer] = null;
		else
			System.out.println("Erreur : il n'y a aucun joueur � supprimer !");
	}

	// Supprimer un joueur du tableau en utilisant son ID
	public void enleverJoueurAvecId(int id)
	{
		int numeroCase=-1;

		for(int i=0; i<nombreJoueur; i++)
		{
			if(listeJoueur[i].getId()==id)
				numeroCase=i;
		}

		if(numeroCase>-1)
			this.enleverJoueur(numeroCase);
		else
			System.out.println("Erreur : il n'y a aucun joueur avec cet ID !");
	}

	// Afficher tous les joueurs
	public void afficherListeJoueur()
	{
		System.out.println(nom);

		for(int i=0; i < nombreJoueur; i++)
		{
			this.listeJoueur[i].afficherJoueur();
		}
	}
}
