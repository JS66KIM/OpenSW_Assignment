#!/bin/bash

print_param() {
    echo "script name: $0"
    echo "first param: $1"
    echo "second param: $2"
    echo "all params: $@"
    echo "the number of params: $#"
}

print_param Hello World "!"
