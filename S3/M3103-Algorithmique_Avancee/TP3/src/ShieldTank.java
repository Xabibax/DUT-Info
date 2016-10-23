public class ShieldTank extends BasicTank
{
	protected int shield;
	
	public ShieldTank()
	{
		this.name = "Tank Bouclier";
		this.fuel = 100;
		this.power = 10;
		this.shield = 3;
	}
	
	public void etreTouche(BasicTank adversaire)
	{
		if(shield > 0)
			shield--;
		else
			super.etreTouche(adversaire);
	}
}
