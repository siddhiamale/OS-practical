#3. Write a shell script to display days of week and adds “(WEEKEND)” to Sat and Sun, and “(weekday)” to rest of the days.
#Day 1 : Mon (weekday)

#!bin/bash

days=(Mon Tue Wed Thu Fri Sat Sun)

for i in {1..7}
do
    day=${days[$((i-1))]}

    if [ $i -eq 6 ] || [ $i -eq 7 ]
    then
        echo "Day $i : $day (WEEKEND)"
    else
        echo "Day $i : $day (weekday)"
    fi
done

