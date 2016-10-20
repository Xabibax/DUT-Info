<?php
	$monFichier = 'cuisiniers.csv';
	$fd = fopen($monFichier, 'r');

	while(!feof($fd))
	{
		$ligne = fgets($fd);
		$ligne = explode("|", $ligne);
		echo "<BR> Nom : </B> $ligne[0] <BR>";
		echo "<BR> Prénom : </B> $ligne[1] <BR>";
		echo "<BR> Resto : </B> $ligne[2] <BR>";
		echo "<BR> Lieu : </B> $ligne[3] <BR><HR>";
	}

	fclose($fd);
?>
