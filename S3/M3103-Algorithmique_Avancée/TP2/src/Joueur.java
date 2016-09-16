
public class Joueur
{
	private int id;
	private String nom;
	private String prenom;
	private int numero;
	private String poste;
	private boolean estTitulaire;

	public Joueur(int id, String nom, String prenom, int numero, String poste, boolean estTitulaire)
	{
		this.id=id;
		this.nom=nom;
		this.prenom=prenom;
		this.numero=numero;
		this.poste=poste;
		this.estTitulaire=estTitulaire;
	}

	public int getId() {return id;}
	public String getNom() {return nom;}
	public String getPrenom() {return prenom;}
	public int getNumero() {return numero;}
	public String getPoste() {return poste;}
	public boolean getTitulaire() {return estTitulaire;}

	public void setId(int id) {this.id = id;}
	public void setNom(String nom) {this.nom = nom;}
	public void setPrenom(String prenom) {this.prenom = prenom;}
	public void setnumero(int numero) {this.numero = numero;}
	public void setPoste(String poste) {this.poste = poste;}
	public void setTitulaire(boolean estTitulaire) {this.estTitulaire = estTitulaire;}

	public void afficherJoueur()
	{
		System.out.println(getId());
		System.out.println(getNom());
		System.out.println(getPrenom());
		System.out.println(getNumero());
		System.out.println(getPoste());
		System.out.println(getTitulaire());
	}
}