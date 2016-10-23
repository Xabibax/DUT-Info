
public class Tp1
{

	public static void main(String[] args)
	{
		Tp1 t = new Tp1();

		int tab[] = {7, 2, 4, 0, 2, 0, 8, 1, -2, 10};
		int choix = 3;

		switch(choix)
		{
		case 1:
			t.affichageDuTableau(tab);
			// on peut aussi faire 'new Tp1().affichageDuTableau(tab);'
			break;
		case 2:
			t.afficherSommeTableau(tab);
			break;
		case 3:
			t.trierValeursTableau(tab);
			t.affichageDuTableau(tab);
			break;
		}
	}

	void affichageDuTableau(int tab[])
	{
		for(int i=0; i<tab.length; i++)
			System.out.println(tab[i]);
	}

	int afficherSommeTableau(int tab[])
	{
		int somme = 0;
		for(int i=0; i<tab.length; i++)
			somme+=tab[i];

		System.out.println(somme);
		return 0;
	}

	void trierValeursTableau(int tab[])
	{
		int temp;

		for(int i=0; i<tab.length; i++)
		{
			for(int j=0; j<tab.length - 1; j++)
			{
				if(tab[j] > tab[j+1])
				{
					temp = tab[j+1];
					tab[j+1] = tab[j];
					tab[j] = temp;
				}
			}
		}
	}
}