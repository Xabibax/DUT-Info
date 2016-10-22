import java.util.Random;

public class AgileTank extends BasicTank
{
	protected int chanceEsquive;

	public AgileTank()
	{
		this.name = "Tank Agile";
		this.fuel = 100;
		this.power = 5;
		this.chanceEsquive = 21;
	}

	public void etreTouche(BasicTank adversaire)
	{
		Random r = new Random();
		if(r.nextInt(100) > chanceEsquive)
			this.fuel = (this.fuel - adversaire.power);
		else
			System.out.println("ESQUIVE");
	}

}
