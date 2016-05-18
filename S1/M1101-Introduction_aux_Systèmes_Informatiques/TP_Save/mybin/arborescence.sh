#!/bin/sh

mkdir $1
cd $1

for i in $(seq 1 10)
	do
	nom=$1$i
	touch $nom
done
