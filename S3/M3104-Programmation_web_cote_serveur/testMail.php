<?php
    // Le message
    $message = "Line 1\r\nLine 2\r\nLine 3";

    // Dans le cas où nos lignes comportent plus de 70 caractères, nous les coupons en utilisant wordwrap()
    //$message = wordwrap($message, 70, "\r\n");

    // Envoi du mail
    //mail('valougraglia@gmail.com', 'Mon Sujet', $message);

    if(mail('vgraglia@iutbayonne.univ-pau.fr', 'Mon Sujet', $message)) // Envoi du message
    {
        echo 'Votre message a bien été envoyé ';
    }
    else // Non envoyé
    {
        echo "Votre message n'a pas pu être envoyé";
    }
?>
