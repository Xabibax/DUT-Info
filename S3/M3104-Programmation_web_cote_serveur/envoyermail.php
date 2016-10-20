<?php
	$somme = 0;
	$fic = "dons.txt";
	$fd = fopen($fic, "r");

	while(!feof($fd))
	{
		$ligne = fgets($fd);

		if(!empty($ligne))
		{
			$tligne = explode("|", $ligne);
			$tnom = $tligne[0];
			$tdons = $tligne[1];
			$tmail = $tligne[2];
			$somme = $somme + $tligne[1];
		}
	}

	$moyenne = $somme / count($tdons);
	fclose($fd);

	for($i=0; $i<count($tdons); $i++)
	{
		$chaine = "M/Mme $tnom[$i], vous avez donné $tdons[$i] <BR>
		Le Téléthon a récupéré $somme € <BR>
		La moyenne est de $moyenne.";

		//mail($tmail[$i], 'Téléthon', $chaine);

		if(mail($tmail[$i], 'Téléthon', $chaine)) // Envoi du message
		{
		    echo 'Votre message a bien été envoyé ';
		}
		else // Non envoyé
		{
		    echo "Votre message n'a pas pu être envoyé";
		}
	}
?>
