
public class CelluleFormule extends Cellule
{
    private String formule;
	private FeuilleDeCalc feuille;

	public CelluleFormule(String formule, FeuilleDeCalc feuille)
    {
		super();
		this.formule = formule;
		this.feuille = feuille;
		calculer();
	}

	public String getFormule() {return formule;}
	public void setFormule(String formule) {this.formule = formule;}

	private double calculer()
    {
		// TODO: split...
		/*
		String formule;
		Feuille
		return 0;
		*/
	}
}
