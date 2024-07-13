#!/bin/bash

# Check if the path to the text file is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <path_to_file_to_compile> <path_to_testfile>"
  exit 1
fi

if [ -z "$2" ]; then
  echo "Usage: $0 <path_to_file_to_compile> <path_to_testfile>"
  exit 1
fi

# Path to the compiled binary
binary="./a.out"

# Path to the text file
input_file="$2" #Test data file
file_to_compile="$1"

if [ ! -f "$file_to_compile" ]; then
  echo "File not found2: $file_to_compile"
  exit 1
else
  gcc $file_to_compile
fi

# Check if the file exists
if [ ! -f "$input_file" ]; then
  echo "File not found: $input_file"
  exit 1
fi

#Check if result file exists, delete the contents and overwrite
output_file="../02_UnitTests/${input_file%test*}results.txt"
if [ -f "$output_file" ]; then
  rm $output_file
  touch $output_file
  echo $output_file
fi

cat $input_file | while IFS= read -r line; do ./a.out $line; if [ $? -eq 134 ]; then echo "Process aborted with SIGABRT (signal 6), continuing to the next line..."; fi; done > $output_file
