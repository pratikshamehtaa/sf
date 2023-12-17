#!/bin/bash

echo "Enter three numbers:"
read num1
read num2
read num3

max=$num1

if [ $num2 -gt $max ]; then
    max=$num2
fi

if [ $num3 -gt $max ]; then
    max=$num3
fi

echo "The biggest number is: $max"
