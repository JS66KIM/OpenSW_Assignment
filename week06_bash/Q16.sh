#!/bin/bash

file_wordcnt() {
    
    if [ ! -e "$1" ]; then
        echo "$1 파일이 존재하지 않습니다."
        return 1
    fi

    cnt=$(wc -w < "$1")
    echo "$1 파일의 단어는 ${cnt}개 입니다."
}
read -p "Enter a file name: " FILE
file_wordcnt $FILE
echo "file_wordcnt 함수가 종료상태 : $?"
 