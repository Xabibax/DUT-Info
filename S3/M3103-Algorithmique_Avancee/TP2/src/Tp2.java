public class Tp2
{

	public static void main(String args[])
	{
		Joueur j1 = new Joueur(1, "CLARK", "Kent", 12, "Gardien", true);
		Joueur j2 = new Joueur(2, "WAYNE", "Bruce", 3, "Attaquant", false);
		Joueur j3 = new Joueur(3, "STARK", "Tony", 4, "Défenseur", true);

		Equipe e1 = new Equipe(1, "Équipe IUT");
		Equipe e2 = new Equipe(2, "Équipe IUT");

		e1.ajouterJoueur(j1.getId(), j1.getNom(), j1.getPrenom(),j1.getNumero(), j1.getPoste(), j1.getTitulaire());
		e1.ajouterJoueur(j2.getId(), j2.getNom(), j2.getPrenom(),j2.getNumero(), j2.getPoste(), j2.getTitulaire());
		e2.ajouterJoueur(j3.getId(), j3.getNom(), j3.getPrenom(),j3.getNumero(), j3.getPoste(), j3.getTitulaire());

		e1.afficherRemplacants();
		e2.afficherTitulaires();
	}
}
