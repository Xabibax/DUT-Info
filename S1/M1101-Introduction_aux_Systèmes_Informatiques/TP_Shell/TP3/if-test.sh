#!/bin/bash 
 
echo "Entrez votre note :" 
read -r note 

if [ "$note" -gt 20 ]; then
    echo "Erreur: la note saisie est supérieur à 20"
elif [ "$note" -ge 16 ]; then
    echo "Très bien" 
elif [ "$note" -ge 14 ]; then 
    echo "Bien" 
elif [ "$note" -ge 12 ]; then 
    echo "Assez bien" 
elif [ "$note" -ge 10 ]; then 
    echo "Moyen" 
elif [ "$note" -ge 0 ]; then 
    echo "Insuffisant" 
else
    echo "Erreur: la note saisie est inférieur à 0"
fi
