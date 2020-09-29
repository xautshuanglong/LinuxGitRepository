#!/bin/bash

echo =========================== getoption testing pid:$$ argc:$# =============================

echo "\$*=" $*
echo "\"\$*\"=" "$*"

echo "\$@=" $@
echo "\"\$@\"=" "$@"

echo ------------------------------------------------------------------------------------------

echo "print each param from \$*"
for var in $*
do
    echo "$var"
done

echo ------------------------------------------------------------------------------------------

echo "print each param from \$@"
for var in $@
do
    echo "$var"
done

echo ------------------------------------------------------------------------------------------

echo "print each param from \"\$*\""
for var in "$*"
do
    echo "$var"
done

echo ------------------------------------------------------------------------------------------

echo "print each param from \"\$@\""
for var in "$@"
do
    echo "$var"
done

