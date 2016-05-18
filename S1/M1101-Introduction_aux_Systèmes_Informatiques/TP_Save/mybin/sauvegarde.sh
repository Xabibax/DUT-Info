#!/bin/sh

chmod +w $2

if [ ! -e $2/$1 ]
   then cp $1 $2/$1
else
    echo 'Entrez le nom de cette sauvegarde'
    read nom
    cp $1 $2/nom
fi

chmod -w $2