#2. Write a shell script to find sum of digits.
#!bin/bash
echo "enter 1st number :"
read a
echo "enter 2nd number :"
read b

sum=$((a+b))

echo "Sum of digits is : $sum"
