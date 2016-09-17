public class Joueur
{
	// Attributs
	private int id;
	private String nom;
	private String prenom;
	private int numero;
	private String poste;
	private boolean estTitulaire;

	// Constructeur
	public Joueur(int id, String nom, String prenom, int numero, String poste, boolean estTitulaire)
	{
		this.id=id;
		this.nom=nom;
		this.prenom=prenom;
		this.numero=numero;
		this.poste=poste;
		this.estTitulaire=estTitulaire;
	}

	// Getters
	public int getId() {return id;}
	public String getNom() {return nom;}
	public String getPrenom() {return prenom;}
	public int getNumero() {return numero;}
	public String getPoste() {return poste;}
	public boolean getTitulaire() {return estTitulaire;}

	// Setters
	public void setId(int id) {this.id = id;}
	public void setNom(String nom) {this.nom = nom;}
	public void setPrenom(String prenom) {this.prenom = prenom;}
	public void setnumero(int numero) {this.numero = numero;}
	public void setPoste(String poste) {this.poste = poste;}
	public void setTitulaire(boolean estTitulaire) {this.estTitulaire = estTitulaire;}

	// Affichage des "propriétés" du joueur
	public void afficherJoueur()
	{
		System.out.println("  Identifiant : " + getId());
		System.out.println("  Nom : " + getNom());
		System.out.println("  Prénom : " + getPrenom());
		System.out.println("  Maillot : " + getNumero());
		System.out.println("  Poste : " + getPoste());
		System.out.println("  Titulaire : " + getTitulaire() + "\n");
	}
}
