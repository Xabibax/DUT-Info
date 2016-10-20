<p>
    Veuillez taper vos informations :
</p>

<form action="cible.php" method="post">
<p>
	<p>Entrez votre nom <input type="text" name="nom"/></p>
    <p>Entrez votre prénom <input type="text" name="prenom"/></p>
    <p>Entrez votre adresse mail <input type="text" name="mail1"/></p>
    <p>Confirmez votre adresse mail <input type="text" name="mail2"/></p>
    <p>Entrez votre mot de passe <input type="password" name="password1"/></p>
    <p>Confirmez votre mot de passe <input type="password" name="password2"/></p>

    <p> Sélectionnez votre pays
	    <select name="choix">
		    <option value="choix1">États-Unis</option>
		    <option value="choix2">Chine</option>
		    <option value="choix3">France</option>
		    <option value="choix4">Allemagne</option>
		</select>
	</p>

	<p>Sélectionnez vos langages de programmation</br>
		<input type="checkbox" name="case" id="case1" /> <label for="case1">C++</label></br>
		<input type="checkbox" name="case" id="case2" /> <label for="case2">PHP</label></br>
		<input type="checkbox" name="case" id="case3" /> <label for="case3">SQL</label></br>
		<input type="checkbox" name="case" id="case4" /> <label for="case4">Java</label></br>
		<input type="checkbox" name="case" id="case5" /> <label for="case5">Shell</label></br>
		<input type="checkbox" name="case" id="case6" /> <label for="case6">HTML/CSS</label></br>

		<!-- <input type="checkbox" name="case" checked="checked" /> pour cocher une case par défaut -->
	</p>

	<p>
		Recevoir la newsletter ? 
		<input type="radio" name="news" value="oui" id="oui" checked="checked" /> <label for="oui">Oui</label> <!-- OUI par défaut -->
		<input type="radio" name="news" value="non" id="non" /> <label for="non">Non</label>
	</p>

    <input type="submit" value="Valider" />
</p>
</form>