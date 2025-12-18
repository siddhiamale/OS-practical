#6. Write a shell script which will take a single command line argument (a directory) and will print each entry in that directory. If the entry is a file it will print its size. If the entry is a directory it will print how many
#items are in that directory.
#!bin/bash


# Check if directory argument is given
if [ $# -ne 1 ]
then
    echo "Usage: $0 <directory>"
    exit 1
fi

dir=$1

# Check if the argument is a directory
if [ ! -d "$dir" ]
then
    echo "$dir is not a valid directory"
    exit 1
fi

# Loop through all entries in the directory
for entry in "$dir"/*
do
    if [ -f "$entry" ]    # If it is a file
    then
        size=$(stat -c %s "$entry")   # Get file size in bytes
        echo "File: $(basename "$entry") → Size: $size bytes"
    elif [ -d "$entry" ]  # If it is a directory
    then
        count=$(ls -1 "$entry" | wc -l)   # Count items in sub-directory
        echo "Directory: $(basename "$entry") → Items: $count"
    fi
done

