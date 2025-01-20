#!/bin/bash

# Check if exactly three arguments (filename, string1, string2) are provided
if [ "$#" -ne 3 ]; then
  echo "Usage: $0 <filename> <string1> <string2>"
  exit 1
fi

# Get the arguments
filename=$1
string1=$2
string2=$3
control=expected

# Check if the original file exists
if [ ! -f "$filename" ]; then
  echo "File $filename not found."
  exit 1
fi

# Create the control file with the expected modified contents
sed "s/$string1/$string2/g" "$filename" > "$control"

# Check if the new file was created successfully
if [ ! -f "$control" ]; then
  echo "Failed to create file $control."
  exit 1
fi

# Compare the generated .replace file with the expected output (control file)
if cmp -s "${filename}.replace" "$control"; then
  echo "Test passed"
else
  echo "Test failed"
fi

# Clean up temporary control file
rm "$control"