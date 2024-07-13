#!/bin/bash

# Check if the path to the text file is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <path_to_text_file>"
  exit 1
fi

# Path to the compiled binary
binary="./a.out"

# Path to the text file
input_file="$1" #Test data file

if [-f "Results.txt"]; then
  rm Results.txt
  touch Results.txt
fi

# Check if the file exists
if [ ! -f "$input_file" ]; then
  echo "File not found: $input_file"
  exit 1
fi

cat $input_file | while IFS= read -r line; do ./a.out $line; if [ $? -eq 134 ]; then echo "Process aborted with SIGABRT (signal 6), continuing to the next line..."; fi; done > ../02_UnitTests/${input_file%test*}results.txt
