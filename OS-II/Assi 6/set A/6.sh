#6. Write a shell script to display first 10 odd numbers and their sum.
#!bin/bash

sum=0
for i in {1..20}
do 
	if [ $((i%2)) -ne 0 ]
	then
		echo "odd = $i"
		sum=$((sum+i))
	fi
done
echo "Sum is $sum"
	
