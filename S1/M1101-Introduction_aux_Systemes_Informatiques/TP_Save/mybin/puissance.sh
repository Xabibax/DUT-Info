#!/bin/sh

echo 'Saisissez un nombre : '

read nombre
resultat=1

for (( i=0;i<$nombre;i++ ))
	do
	let resultat=$resultat*$nombre
done

echo 'La puissance vaut' $resultat
