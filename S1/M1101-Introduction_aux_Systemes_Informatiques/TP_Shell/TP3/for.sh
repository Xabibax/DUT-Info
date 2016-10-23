#!/bin/bash 

echo "Saisir un nombre" 
read -r nombre 

resultat=1 

for (( i=0 ; i<$nombre ; i++ )); do 
    let resultat=$resultat*$nombre 
done 

echo "$nombre^$nombre = $resultat"
