#!/bin/bash

read -p "Entrez un nom de dossier : " dossier
mkdir "$dossier"

for (( i=1 ; 11 - $i ; i++)); do
     mkdir "$dossier/$dossier$i"
ls $dossier
done
