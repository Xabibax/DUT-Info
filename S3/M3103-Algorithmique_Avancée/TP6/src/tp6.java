import java.io.*;
import java.util.*;
import org.jdom2.*;
import org.jdom2.input.*;
import org.jdom2.output.*;

public class tp6
{
	static Element racine = new Element("personnage");

	//Document JDOM qui fait l'objet des opérations
	static org.jdom2.Document document = new Document(racine);

	// Initialiser le document JDOMà partir d'un fichier XML //
	//*******************************************************//
	public static void deFichierXMLversJDOM(String fichier)
	{
		// Créer une instance de SAXBuilder
		SAXBuilder sxb = new SAXBuilder();

		try
		{
			// Créer le document JDOM avec en argument le fichier XML
			document = sxb.build(new File(fichier));
		}
		catch(Exception e) {e.printStackTrace();}
	}

	// Enregistrer le document JDOM dans un fichier XML //
	//**************************************************//
	static void deJDOMversFichierXML(String fichier)
	{
		try
		{
			// Utiliser un affichage classique avec getPrettyFormat()
			XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());
			// Créer une instance de FileOutputStream
			// avec en argument le nom du fichier pour effectuer la sérialisation
			sortie.output(document, new FileOutputStream(fichier));
		}
		catch(java.io.IOException e) {e.printStackTrace();}
	}

	// Afficher le document JDOM //
	//***************************//
	public static void afficherJDOM()
	{
		try
		{
			// Utiliser un affichage classique avec getPrettyFormat()
			XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());
			// Préciser que la sortie de document se fait sur System.out
			sortie.output(document, System.out);
		}
		catch(java.io.IOException e) {e.printStackTrace();}
	}

	static void enregistrerJDOM(String fichier)
    {
		try
        {
			// On utilise ici un affichage classique avec getPrettyFormat()
			XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());

			// Remarquez qu'il suffit simplement de créer une instance de FileOutputStream avec en argument le
			// nom du fichier pour effectuer la sérialisation.
			sortie.output(document, new FileOutputStream(fichier));
		}

		catch (java.io.IOException e) {e.printStackTrace();}
	}

	public static void afficherTexteDePetitsFilsDeLaRacine(String nomDeFils, String nomDePetitFils)
	{
		// Initialiser un Element racine avec la racine du document
		Element racine = document.getRootElement();

		// Créer une List d'Element constituée des nomDeFils de la racine
		// mais sans les autres fils de la racine
		List <Element> listFils = racine.getChildren(nomDeFils);

		// Parcourir la liste listFils constituée
		for(int i=0; i < listFils.size(); i++)
		{
			// Accéder au i-ème Element de la liste
			Element courant = listFils.get(i);
			// Accéder au nom de l'Element courant de la list, en format texte
			System.out.println(courant.getChild(nomDePetitFils).getText());
		}
	}

	public static void afficherAttributDeFilsDeLaRacine(String nomDeFils, String attribut)
	{
		// Initialiser un Element racine avec la racine du document
		Element racine = document.getRootElement();

		// Créer une List d'Element constituée des nomDeFils de la racine
		// mais sans les autres fils de la racine
		List <Element> listFils = racine.getChildren(nomDeFils);

		// Parcourir la liste listFils constituée
		for(int i=0; i < listFils.size(); i++)
		{
			// Accéder au i-ème Element de la liste
			Element courant = listFils.get(i);
			// Accéder au nom de l'Element courant de la list, en format texte
			System.out.println(courant.getAttributeValue(attribut));
		}
	}

	// Supprimer mes élément petitFils d'un élément fils
	public static void supprimerPetitFilsDansFils(String fils, String petitFils)
	{
		// Initialiser un Element racine avec la racine du document
		Element racine = document.getRootElement();

		// Dans un premier temps on liste tous les étudiants
		List listFils = racine.getChildren(fils);
		// On parcours la liste grâce à un  iterator
		Iterator i = listFils.iterator();

		while(i.hasNext())
		{
			Element courant = (Element) i.next();
			// Si l'élément courant possèdfe un élémentPetitFils on applique la modification
			if(courant.getChild(petitFils)!= null)
			{
				// On supprime le ptitFils en question
				courant.removeChild(petitFils);
				// On renomme l'element courant ainsi modifié
				courant.setName(courant.getName()+"_modifie");
			}
		}
	}

	// Supprimer mes élément petitFils d'un élément fils
	public static void supprimerSaufSuperwoman(String fils, String petitFils)
	{
		// Initialiser un Element racine avec la racine du document
		Element racine = document.getRootElement();

		// Dans un premier temps on liste tous les étudiants
		List listFils = racine.getChildren(fils);
		// On parcours la liste grâce à un  iterator
		Iterator i = listFils.iterator();

		while(i.hasNext())
		{
			Element courant = (Element) i.next();
			// Si l'élément courant possèdfe un élémentPetitFils on applique la modification
			if(courant.getChild(petitFils)!= null)
			{
				if(courant.getChild(petitFils).getText() != "Superwoman")
				{
					// On supprime le ptitFils en question
					courant.removeChild(petitFils);
					// On renomme l'element courant ainsi modifié
					courant.setName(courant.getName()+"_modifie");
				}
			}
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args)
    {
		// On crée un nouvel Element etudiant et on l'ajoute en tant qu'Element de racine
        Element etudiant = new Element("etudiant");
        racine.addContent(etudiant);

        // On crée un nouvel Attribut classe et on l'ajoute �� etudiant gràce �� la méthode setAttribute
        Attribute classe = new Attribute("classe", "P2");
        etudiant.setAttribute(classe);

        // On crée un nouvel Element nom, on lui assigne du texte et on l'ajoute en tant
        // qu'Element de etudiant
        Element nom = new Element("nom");
        nom.setText("LeJardinier");
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

        Attribute classe3 = new Attribute("classe", "P3");
        etudiant3.setAttribute(classe3);

		Element nom3 = new Element("nom");
        nom3.setText("Don Carleone");
        etudiant3.addContent(nom3);


        // On affiche le document XML
		//afficherJDOM();

        afficherJDOM();
		enregistrerJDOM("Source.xml");

		afficherTexteDePetitsFilsDeLaRacine("etudiant", "nom");

        afficherAttributDeFilsDeLaRacine("etudiant", "classe");

		supprimerPetitFilsDansFils("etudiant", "prenoms");
		enregistrerJDOM("Resultat.xml");

		supprimerSaufSuperwoman("etudiant", "nom");
		enregistrerJDOM("ResultatFinal.xml");

        // On crée le fichier Exercice1.xml dans lequel on enregistre le document XML
        //enregistrerJDOM("Source.xml");
	}
}
