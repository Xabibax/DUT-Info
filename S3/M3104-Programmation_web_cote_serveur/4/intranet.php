<?php

session_start();

$user=$_POST['user'];
$password=$_POST['password'];

if($user == "nvalsecchi"){
  if($password == "64azerty")
  {
    $_SESSION['authentifie'] = true;
    header('Location: http://localhost/lenomquetuveuxonsentappe/TD5/authentifie.php');}

  else echo "Mot de passe incorrect";
}
else "Compte innexistant dans la base de données";

 ?>
