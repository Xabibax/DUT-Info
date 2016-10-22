<?php
    session_start();

    $user=$_POST['user'];
    $password=$_POST['password'];

    if($user == "vgraglia") // Change login here
    {
        if($password == "azerty123") // Change password here
        {
            $_SESSION['authentifie'] = true;
            header('Location: http://iparla.iutbayonne.univ-pau.fr/~vgraglia/PHP/TD5/authentifie.php');
            // header('Location: http://iparla.iutbayonne.univ-pau.fr/~votreLogin/PHP/TD5/authentifie.php');
        }
        else
            echo "Mot de passe incorrect";
    }
    else
        echo "Compte inexistant dans la base de données";
 ?>
