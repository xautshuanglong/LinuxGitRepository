#!/bin/bash

param_flag_directory="FALSE"
param_flag_cpu="FALSE"
param_flag_list="FALSE"
param_flag_help="FALSE"

param_value_directory=""
param_value_cpu=""
param_value_list=""
param_value_help=""

array_directory_list=(
    '/cygdrive/i/WorkMGI/02_design/05_SW/97_third_party/coturn-4.5.1.3/'
    '/cygdrive/i/WorkMGI/02_design/05_SW/97_third_party/libwebsockets/RestClientDemo/'
    '/cygdrive/i/WorkMGI/02_design/05_SW/97_third_party/libwebsockets/libwebsockets-4.1.6/'
)

function print_help ()
{
    echo '------------------- help string -------------------'
    echo "help parameter $1"
}

function print_cpu_information ()
{
    echo '------------------- print cpu information -------------------'
    echo "cpu parameter $1"
}

function list_all_directories ()
{
    for((i=0;i<${#array_directory_list[@]};i++))
    do
        echo "    $i --> ${array_directory_list[$i]}"
    done
}

function change_work_directory ()
{
    dir=${array_directory_list[$1]}
    echo "---> change to directory $dir"
    if [ -d "$dir" ]
    then
        cd "$dir"
        ls -al
    fi
}

#  注意事项：
#  ::表示 0 个或 1 个参数，为确保没有歧义：
#                          短型参数，选项与值之间不能有空格；
#                          长型参数，选项与值之间用等号连接。
ARGS=`getopt -o d:c:h::,l -l dir:,cpu:,help::,list -- "$@"`

if [ $? == 0 ]
then
    # 重置命令行参数
    eval set -- "${ARGS}"
    # echo "ARGS = $ARGS"
    # 匹配命令行选项
    while :
    do
        # echo "--------- switching $1"
        case $1 in
            -d|--dirctory)
                param_value_directory=$2
                param_flag_directory="TRUE"
                shift
                ;;
            -c|--cpu)
                param_value_cpu=$2
                param_flag_cpu="TRUE"
                shift
                ;;
            -l|--list)
                param_flag_list="TRUE"
                ;;
            -h|--help)
                param_value_help=$2
                param_flag_help="TRUE"
                shift
                ;;
            --)
                # parameter separator, do nothing
                break
                ;;
            *)
                param_flag_help="TRUE"
                break
                ;;
        esac
        shift
    done
fi

# list all directories
if [ "$param_flag_list" == 'TRUE' ]
then
    list_all_directories
fi

# change pwd to directory
if [ "$param_flag_directory" == 'TRUE' ]
then
    change_work_directory $param_value_directory
fi

# Print cpu information
if [ "$param_flag_cpu" == 'TRUE' ]
then
    print_cpu_information $param_value_cpu
fi

# Print help string
if [ "$param_flag_help" == 'TRUE' ]
then
    echo $param_value_help
    print_help $param_value_help
fi

