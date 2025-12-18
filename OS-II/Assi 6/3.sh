#3. Write a shell script to print multiplication table using command line arguments.
#!bin/bash
n=$1

for i in {1..10}
do
	echo "$n * $i = $((n*i))"
done
