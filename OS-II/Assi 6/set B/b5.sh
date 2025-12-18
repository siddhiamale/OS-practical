#5. Write a shell script that accepts any number of arguments and prints them in a reverse order.
#!bin/bash

for (( i=$#; i>0; i-- ))
do
    echo "${!i}"
done
