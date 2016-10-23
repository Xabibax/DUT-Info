#!/bin/bash

mkdir $1
cd $1

for (( i=1 ; i < 11 ; i++)) do
    touch $1$i
    ls $1 -r
done
