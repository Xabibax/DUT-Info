<form action="envoyerMail.php" method="post">
    <?php
        $fic = "dons.txt";
        $nom = $_POST['nom'];
        $don = $_POST['don'];
        $mail = $_POST['mail'];

        $ligne = "$nom | $don | $mail \n";
        $fd = fopen($fic, "a+");
        fputs($fd, $ligne);

        fclose($fd);
    ?>

    <p>Afin de valider votre don, cliquez sur le bouton ci-dessous</p>
    <input type="submit" value="Donner"/>
</form>
