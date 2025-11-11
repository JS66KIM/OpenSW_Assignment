#! /bin/bash

factorial(){

    result=1
    for ((i =1; i <= $1; i++)); do
        result=$(( result * i))
        done

    echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM