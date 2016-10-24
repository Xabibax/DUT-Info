<?php
    session_start();

    if(file_exists('compteurNbVu.txt'))
    {
        $compteur_f = fopen('compteurNbVu.txt', 'r+');
        $compte = fgets($compteur_f);
    }
    else
    {
        $compteur_f = fopen('compteurNbVu.txt', 'a+');
        $compte = 0;
    }

    if(!isset($_SESSION['compteur_de_visite']))
    {
        $_SESSION['compteur_de_visite'] = 'visite';
        $compte++;
        fseek($compteur_f, 0);
        fputs($compteur_f, $compte);
    }

    fclose($compteur_f);
    echo '<strong>'.$compte.'</strong> visites.';
?>
