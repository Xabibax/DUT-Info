<?php
    session_start();

    if(isset($_SESSION['authentifie']) && ($_SESSION['authentifie']))
        echo "Bienvenue sur l'intranet";
    else
        echo "Acces refusé";
 ?>
