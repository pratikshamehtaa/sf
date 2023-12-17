#!/bin/bash

file_path=""

word_count=$(wc -w < "$file_path")
char_count=$(tr -d ' \n' < "$file_path" | wc -m)
line_count=$(wc -l < "$file_path")

echo "Word Count: $word_count"
echo "Character Count: $char_count"
echo "Line Count: $line_count"
