<?php
    $rep = ".";
    $fd = opendir($rep);

    while (($fichier = readdir($fd)) != " ")
    {
        $text = explode(".", $fichier);
        $pos = count($text) - 1;
        $ext = $text[$pos];

        if(($ext == "doc") || ($ext == "xls") || ($ext == "ppt"))
        {
            ?>
            <font color=#FF0000><?php echo $fichier; ?></font>
            <?php
        }
        else if(($ext == "txt") || ($ext == "php"))
        {
            ?>
            <font color=#00FF00><?php echo $fichier; ?></font>
            <?php
        }
        else if(($ext == "jpg") || ($ext == "png"))
        {
            ?>
            <font color=#0000FF><?php echo $fichier; ?></font>
            <?php
        }
    }

    closedir($fd);
?>
