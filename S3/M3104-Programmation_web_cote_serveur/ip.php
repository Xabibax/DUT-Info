<?php
	$ip = $_SERVER['REMOTE_ADDR'];
	$tip = explode(".", $ip);

	if($tip < 127)
		$classe = "Classe A";
	else if((127 > $tip) AND ($tip < 192))
		$classe = "Classe B";
	else
		$classe = "Classe C";

	echo $classe;
?>