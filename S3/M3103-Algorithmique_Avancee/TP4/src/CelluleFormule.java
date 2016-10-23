public class CelluleFormule extends Cellule
{
	private String formule;
	private FeuilleCalcul feuilleCalcul;

	public CelluleFormule(String formule, FeuilleCalcul feuilleCalcul)
	{
		super(0);
		// TODO Auto-generated constructor stub
		this.formule = formule;
		this.feuilleCalcul = feuilleCalcul;
		calculer();
	}
	
	public double getValeur()
	{
		calculer(); //recalcul avant de renvoyer la valeur
		return super.getValeur();
	}

	
	public void affiche()
	{
		calculer();  //recalcul car des cellules peuvent avoir changé de valeur 
					// depuis la creation de cette cellule 
		super.affiche();
	}
	
	private void calculer()
	{
		if (feuilleCalcul != null)
		{
			int iOperateur = getIndiceOperateur(formule);// recherche de l'operateur
			
			String idCellule1 = formule.substring(0, iOperateur);//la cellule 1 est avant l'operateur
			String idCellule2 = formule.substring(iOperateur + 1);//la cellule 2 est apres l'operateur
			
			if ("+".equals(formule.substring(iOperateur, iOperateur + 1)))
				setValeur(feuilleCalcul.getValeur(idCellule1) + 
						  feuilleCalcul.getValeur(idCellule2));
			
			if ("-".equals(formule.substring(iOperateur, iOperateur + 1)))
				setValeur(feuilleCalcul.getValeur(idCellule1) - 
						  feuilleCalcul.getValeur(idCellule2));
			
			if ("/".equals(formule.substring(iOperateur, iOperateur + 1)))
				setValeur(feuilleCalcul.getValeur(idCellule1) / 
						  feuilleCalcul.getValeur(idCellule2));
			
			if ("*".equals(formule.substring(iOperateur, iOperateur + 1)))
				setValeur(feuilleCalcul.getValeur(idCellule1) * 
						  feuilleCalcul.getValeur(idCellule2));
		}
	}
	
	private int getIndiceOperateur(String chaine)
	{
		int iOperateur = -1;
		
		if (chaine != null)
		{
			int iParcours = 0;
			
			while (iOperateur == -1 && iParcours < chaine.length())
			{
				//tant qu'on a pas trouve un operateur et qu'on ne depasse pas la fin de chaine
				if ("+".equals(chaine.substring(iParcours, iParcours + 1)) ||
					"-".equals(chaine.substring(iParcours, iParcours + 1)) ||
					"*".equals(chaine.substring(iParcours, iParcours + 1)) ||
					"/".equals(chaine.substring(iParcours, iParcours + 1)))
					iOperateur = iParcours;
					
				iParcours ++;
			}
		}
	
		return iOperateur;
	}
}
