#!/bin/bash

for ((i = 7; i <= 7; i++))
do
    ./gen > $i.in
done

for ((i = 1; i <= 10; i++))
do
    ./sol < $i.in > $i.out
done
