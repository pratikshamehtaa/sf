#!/bin/bash

file_path=""


size=$(du -h "$file_path" | cut -f1)


permissions=$(ls -l "$file_path" | awk '{print $1}')


owner=$(ls -l "$file_path" | awk '{print $3}')
group=$(ls -l "$file_path" | awk '{print $4}')

last_modified=$(date -r "$file_path" "+%Y-%m-%d %H:%M:%S")

echo "File Name: $file_path"
echo "Size: $size"
echo "Permissions: $permissions"
echo "Owner: $owner"
echo "Group: $group"
echo "Last Modified: $last_modified"
