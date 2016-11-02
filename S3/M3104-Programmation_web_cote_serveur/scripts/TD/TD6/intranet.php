<?php
    session_start();

    $user=$_POST['user'];
    $password=$_POST['password'];

    if($user == "vgraglia") // Change login here
    {
        if($password == "azerty123") // Change password here
        {
            $_SESSION['authentifie'] = true;
            header('Location: authentifie.php'); // fonctionne pour IUT et Wamp
            // Ou (Wamp) : header('Location: http://localhost/votreNomDeDossier/authentifie.php');
        }
        else
            echo "Mot de passe incorrect";
    }
    else
        echo "Compte inexistant dans la base de données";
 ?>
