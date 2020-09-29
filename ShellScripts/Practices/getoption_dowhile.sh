#!/bin/bash

echo ==================================== getoption testing ==================================== 

until [ $# -eq 0 ]
do
    echo "第一个参数：$1 参数个数：$#"
    shift
done

