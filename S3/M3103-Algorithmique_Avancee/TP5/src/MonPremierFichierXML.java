import java.io.*;
import org.jdom2.*;
import org.jdom2.output.*;

public class MonPremierFichierXML
{
	//Nous allons commencer notre arborescence en créant la racine XML qui sera ici "personnes".
	static Element racine = new Element("personnes");

	//On crée un nouveau Document JDOM basé sur la racine que l'on vient de créer
	static org.jdom2.Document document = new Document(racine);

	static void affiche()
    {
		try
        {
			//On utilise ici un affichage classique avec getPrettyFormat()
			XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());
			sortie.output(document, System.out);
		}

		catch (java.io.IOException e){}
	}

	static void enregistre(String fichier)
    {
		try
        {
			// On utilise ici un affichage classique avec getPrettyFormat()
			XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());

			// Remarquez qu'il suffit simplement de créer une instance de FileOutputStream avec en argument le
			// nom du fichier pour effectuer la sérialisation.
			sortie.output(document, new FileOutputStream(fichier));
		}

		catch (java.io.IOException e){}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args)
    {
		// On crée un nouvel Element etudiant et on l'ajoute en tant qu'Element de racine
        Element etudiant = new Element("etudiant");
        racine.addContent(etudiant);

        // On crée un nouvel Attribut classe et on l'ajoute à etudiant grâce à la méthode setAttribute
        Attribute classe = new Attribute("classe", "P2");
        etudiant.setAttribute(classe);

        // On crée un nouvel Element nom, on lui assigne du texte et on l'ajoute en tant
        // qu'Element de etudiant
        Element nom = new Element("nom");
        nom.setText("CynO");
        etudiant.addContent(nom);

        // 3 Créer un fichier XML
        Element prenoms = new Element("prenoms");
        etudiant.addContent(prenoms);

        Element prenom1 = new Element("prenom");
        prenom1.setText("Nicolas");
        prenoms.addContent(prenom1);

        Element prenom2 = new Element("prenom");
        prenom2.setText("Laurent");
        prenoms.addContent(prenom2);

		Element etudiant2 = new Element("etudiant");
        racine.addContent(etudiant2);

        Attribute classe2 = new Attribute("classe", "P1");
        etudiant2.setAttribute(classe2);

		Element nom2 = new Element("nom");
        nom2.setText("Superwoman");
        etudiant2.addContent(nom2);

		Element etudiant3 = new Element("etudiant");
        racine.addContent(etudiant3);

        Attribute classe3 = new Attribute("classe", "P1");
        etudiant3.setAttribute(classe3);

		Element nom3 = new Element("nom");
        nom3.setText("Don Carleone");
        etudiant3.addContent(nom3);



        // On affiche le document XML
        affiche();

        // On crée le fichier Exercice1.xml dans lequel on enregistre le document XML
        enregistre("Exercice1.xml");
	}
}
