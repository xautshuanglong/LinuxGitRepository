#!/bin/bash

echo =========================== getoption testing pid:$$ argc:$# =============================

# getopts 后跟选项字符串，字符后面跟着一个冒号，表示该选项需要一个参数
# $OPTARG 对应选项携带的参数
# $OPTIND 选项位置加1或2 （开关选项：1，带参选项：2），代表下一个要处理的参数的索引（从0开始，包括脚本名称）

echo '$* -->' $*
while getopts "a:bc:" opt
do
    case $opt in
        a)
            echo '----- inside case a --> $OPTARG='$OPTARG
            echo '----- inside case a --> $OPTIND='$OPTIND
            ;;
        b)
            echo "----- inside case b --> \$OPTIND=$OPTIND"
            ;;
        c)
            echo "----- inside case c --> \$OPTARG=$OPTARG"
            echo "----- inside case c --> \$OPTIND=$OPTIND"
            ;;
        ?)
            echo "----- inside case ? --> error"
            exit 1
    esac
done

echo '$OPTIND -->' $OPTIND
shift $(( $OPTIND-1 ))
echo '$0 -->' $0
echo '$* -->' $*

