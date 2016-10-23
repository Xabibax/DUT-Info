public class TestTank
{
	public static void main(String[] args)
	{
		BasicTank noob = new BasicTank();
		AgileTank mlg = new AgileTank();
		
		noob.shoot(mlg);
		noob.shoot(mlg);
		noob.shoot(mlg);
		noob.shoot(mlg);
		
		System.out.println("Fuel mlg = " + mlg.fuel);
	}
}
