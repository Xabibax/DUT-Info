<form method="post" action="image.php">
	<p>
		Génération d'une image en fonction des critères. <br/>
		Veuillez rentrer les informations suivantes :
	</p>

	<p>
		<p>X : <input type="text" name="X"/></p>
		<p>Y : <input type="text" name="Y"/></p>
		<p>Texte :	<SELECT name="couleur" size="1">
						<OPTION selected value="--">--</OPTION>
						<OPTION value="Rouge">Rouge</OPTION>
						<OPTION value="Vert">Vert</OPTION>
					</SELECT>
		</p>
		<p>Fond : <SELECT name="fond" size="1"></p>
					  <OPTION selected value="--">--</OPTION>
					  <OPTION value="Noir">Noir</OPTION>
					  <OPTION value="Blanc">Blanc</OPTION>
				  </SELECT>
		</p>
		<p>Texte :<input type="text" name="texte" /></p>
		<input type="submit" value="GENERER" />
	</p>
</form>
