#4. Write a shell script sum.sh that takes an unspecified number of command line arguments (up to 9) of int and
#finds their sum. Modify the code to add a number to the sum only if the number is greater than 10.
#!bin/bash
sum=0

for n in "$@"
do
	if [ $n -gt 10 ]
	then
		sum=$((sum+n))
	fi
done
echo "Sum of numbers : $sum"
