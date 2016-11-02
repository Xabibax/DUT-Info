<?php
	header("Content-type: image/jpeg");

	$X = $_POST['X'];
	$Y = $_POST['Y'];
	$texte = $_POST['texte'];

	$couleur = $_POST['couleur'];
	$fond = $_POST['fond'];
	$image = imagecreate($X, $Y);

	if($fond == "Noir")
		$majCouleur = imagecolorallocate($image, 0, 0, 0);
	else
		$majCouleur = imagecolorallocate($image, 255, 255, 255);

	imagefill($image, 0, 0, $majCouleur);
	
	if($couleur == "Rouge")
		$majCouleur = imagecolorallocate($image, 255, 0, 0);
	else
		$majCouleur = imagecolorallocate($image, 0, 255, 0);
	
	imagestring($image, 5, 0, 0, $texte, $majCouleur);
	imagejpeg($image);
	imagedestroy($image);
 ?>
