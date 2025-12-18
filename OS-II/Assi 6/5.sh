#5. Write a shell script that accepts two integers as its arguments and computers the value of first number raised to
#the power of the second number.
#!bin/bash

echo "enter 1st no :"
read x
echo "enter 2nd no :"
read y
result=1

while [ $y -ge 1 ] 
do 
	result=$((result*x))
	y=$((y-1))
done
echo "Ans is $result"
