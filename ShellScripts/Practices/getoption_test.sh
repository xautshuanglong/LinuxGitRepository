#!/bin/bash

echo ==================================== getoption testing ==================================== 

func() {
    echo "Usage:"
    echo "getoption_test.sh [-j S_DIR] [-m D_DIR]"
    echo "Description:"
    echo "S_DIR, the path of source."
    echo "D_DIR, the path of destination."
    exit -1
}

upload="false"

echo '$OPTIND -->' $OPTIND

while getopts 'h:j:m:u' OPT; do
    case $OPT in
        j) S_DIR="$OPTARG";;
        m) D_DIR="$OPTARG";;
        u) upload="true";;
        h) func;;
        ?) func;;
    esac
done

# $OPTIND 从 1 开始，增长到最大参数个数，个数为 case 选项个数。

echo '$S_DIR -->' $S_DIR
echo '$D_DIR -->' $D_DIR
echo '$upload -->' $upload

echo '$1 -->' $1
echo '$2 -->' $2
echo '$3 -->' $3
echo '$4 -->' $4
echo '$5 -->' $5
echo '$6 -->' $6

echo '$OPTIND -->' $OPTIND
shift $(($OPTIND - 1))
echo $1

