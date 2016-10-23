public class BasicTank
{
		protected String name;
		protected int fuel;
		protected int power;
		
		public BasicTank()
		{
			this.name = "Char Basique";
			this.fuel = 100;
			this.power = 10;
		}
		
		public void shoot(BasicTank adversaire)
		{
			adversaire.etreTouche(this);
			System.out.println("En plein dedans mon commandant");
		}
		
		public void etreTouche(BasicTank adversaire)
		{
			this.fuel = (this.fuel - adversaire.power);
			System.out.println("TOUCHE");
		}
}
