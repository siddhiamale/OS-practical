#4. Write a shell script that will report the number of lines in each file within the current directory.
#!/bin/bash
for file in *
do
    if [ -f "$file" ]   # check if it is a regular file
    then
        lines=$(wc -l < "$file")
        echo "File: $file → Lines: $lines"
    fi
done

