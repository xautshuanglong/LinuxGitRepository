#!/bin/bash

echo =========================== getoption testing pid:$$ argc:$# =============================

echo '$* -->' $*
while getopts ":a:bc:-:" opt
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
        -)
            case $OPTARG in
                loglevel)
                    real_arg=${!OPTIND}
                    OPTIND=$(( $OPTIND + 1 ))
                    echo "----- inside case loglevel --> $OPTARG=$real_arg"
                    ;;
                loglevel=*)
                    real_arg=${OPTARG#*=}
                    real_opt=${OPTARG%=$real_arg}
                    echo "----- inside case loglevel --> $real_opt=$real_arg"
                    ;;
                others)
                    echo "----- inside case others -->"
                    ;;
                *)
                    echo "----- inside case - --> long option error"
                    exit 1
            esac;;
        *)
            echo "----- inside case * --> short option error"
            exit 1
    esac
done

echo '$OPTIND -->' $OPTIND
shift $(( $OPTIND-1 ))
echo '$0 -->' $0
echo '$* -->' $*

echo --------------------------------------------------------------------------------------

DDF_SOURCE="siebel_DATA_DATE_FORMAT"
siebel_DATA_DATE_FORMAT='Hello world'
DATA_DATE_FORMAT=${!DDF_SOURCE}

echo $DDF_SOURCE
echo $DATA_DATE_FORMAT

echo --------------------------------------------------------------------------------------

