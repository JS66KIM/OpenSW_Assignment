#!/bin/bash

file_wordcnt() {
    
    cnt=$(wc -w < "$1")
    echo "$1 파일의 단어는 ${cnt}개 입니다."
}
read -p "Enter a file name: " FILE
file_wordcnt $FILE
 