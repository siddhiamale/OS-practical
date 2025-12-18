#1. Write a shell script which will print the numbers 1 - 10 (each on a separate line) and whether they are
#even or odd.
#!bin/bash

for i in {1..10}
do
	if [ $((i%2)) -eq 0 ]
	then
		echo "Even $i"
	else
		echo "Odd $i"
	fi
done
