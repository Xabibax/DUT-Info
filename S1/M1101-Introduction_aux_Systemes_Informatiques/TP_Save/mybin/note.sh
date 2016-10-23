#!/bin/sh

echo 'Entrez la note à analyser !'

read note


if [ $note -le 20 ] && [ $note -gt 16 ]
	then
		echo 'Très bien !'
elif [ $note -le 16 ] && [ $note -gt 14 ]
	then
		echo 'Bien.'
elif [ $note -le 14 ] && [ $note -gt 12 ]
	then
		echo 'Assez bien.'
elif [ $note -le 12 ] && [ $note -gt 10 ]
	then
		echo 'Moyen'
else
	echo 'Insuffisant...'
fi

