chmod -R +w ~/sauvegarde

filename=$1

#Test d'existence du fichier source
if [ ! -e "$filename" ]; then
    echo "La ressource $filename n'existe pas"
    exit 0
fi

# Test d'existence du fichier cible
if [ -e ~/sauvegarde/$(basename $filename) ]; then
    echo "Le fichier $filename existe déjà, veuillez entrer un autre nom pour la sauvegarde :"
    read newfilename
fi

# Sauvegarde
cp -r $filename ~/sauvegarde/$newfilename
echo "Ressource $filename sauvegardé"

chmod -R -w ~/sauvegarde

